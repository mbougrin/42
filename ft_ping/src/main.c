/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:44 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/25 08:44:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static unsigned short	checksum(void *b, int len)
{
	unsigned short 	*buf = b;
	unsigned int 	sum = 0;
	unsigned short 	result = 0;

	for (sum = 0; len > 1; len -= 2)
		sum += *buf++;
	if (len == 1)
		sum += *(unsigned char*)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	return (result);
}

static t_stc			*singleton(t_stc *stc)
{
	static t_stc	*singleton;

	if (stc != NULL)
		singleton = stc;
	return (singleton);
}

static void				showHelp(char *str)
{
	printf("Usage: %s [-hv] destination IP\n", str);
	free(singleton(NULL));
	exit(-1);
}

static void				addrError(void)
{
	t_stc		*stc = singleton(NULL);
	printf("%s: unknown host %s\n", stc->name, stc->ip);
	free(stc);
	exit(-1);
}

static void				connectError(void)
{
	printf("connect error\n");
	free(singleton(NULL));
	exit(-1);
}

void					ipConnect(void)
{
	t_stc		*stc = singleton(NULL);
	t_addrinfo	*tmp;
	t_addrinfo	*result;
	int			fd;

	if ((getaddrinfo(stc->ip, NULL, &stc->hints, &result)) != 0)
		addrError();
	tmp = result;
	while (tmp != NULL)
	{
		fd = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);
		if (fd == -1)
			continue ;
		if (connect(fd, tmp->ai_addr, tmp->ai_addrlen) != -1)
		{
			close(fd);
			break ;
		}
		close(fd);
		tmp = tmp->ai_next;
	}
	if (tmp == NULL)
		connectError();
	stc->addr = tmp;
}

static void				initAddr(void)
{
	t_stc		*stc = singleton(NULL);

	stc->hints.ai_family = AF_UNSPEC;
	stc->hints.ai_socktype = SOCK_DGRAM;
	stc->hints.ai_flags = 0;
	stc->hints.ai_protocol = 0;
}

char					*arg(char **av)
{
	int			i;
   
	i = 1;
	while (av[i])
	{
		if (ft_strcmp(av[i], "-h") == 0)
			showHelp(av[0]);
		else if (ft_strcmp(av[i], "-v") != 0)
			return (av[i]);
		i++;
	}
	free(singleton(NULL));
	exit(-1);
}

static void				print(void)
{
	t_stc	*stc = singleton(NULL);

	if (stc->success)
		printf("%d bytes from %s: icmp_seq=%d ttl=254 time=%f ms\n",\
				PACKET_SIZE, stc->ip, stc->count, stc->ms);
	else
		printf("Request timeout from icmp_seq %d\n", stc->count);
}

void					ping(void)
{
	t_stc *stc = singleton(NULL);
	const int val=255;
	int sd = 0;
	t_sockaddr_in 	r_addr;
	t_packet		packet;
	int pid = getpid();

	sd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sd < 0) 
	{
		//printf error exit()
//		perror("socket");
		return;
	}
	if (setsockopt(sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0)
		perror("Set TTL option");

	for (stc->count = 0; stc->count < NUMBER_PACKET; ++stc->count)
	{
		int len = sizeof(r_addr);
		struct timespec tstart={0,0}, tend={0,0};

	//	bzero(&packet, sizeof(packet));
		packet.hdr.type = ICMP_ECHO;
		packet.hdr.un.echo.id = pid;
		packet.hdr.un.echo.sequence = stc->count + 1;
		packet.hdr.checksum = checksum(&packet, sizeof(packet));
		if (sendto(sd, &packet, sizeof(packet), 0, stc->addr->ai_addr, sizeof(*stc->addr->ai_addr)) <= 0)
			perror("sendto");
		clock_gettime(CLOCK_MONOTONIC, &tstart);


		struct timeval tv;
		tv.tv_sec = WAIT;
		tv.tv_usec = 0;
		setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));


		if (recvfrom(sd, &packet, sizeof(packet), 0, (t_sockaddr*)&r_addr, (socklen_t *)&len) > 0 )
		{
			clock_gettime(CLOCK_MONOTONIC, &tend);
			stc->ms = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec) -
				((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
			struct icmp *pkt;
			struct iphdr *iphdr = (struct iphdr *) &packet;
			pkt = (struct icmp *) (&packet + (iphdr->ihl << 2));
			if (pkt->icmp_type == ICMP_ECHOREPLY)
			{
				stc->success = 1;
				print();
			}
			else 
			{
				stc->success = 0;
				print();
			}
		}
		else
		{
			stc->ms = 0.0;
			stc->success = 0;
			print();
		}
		sleep(1);
	}

}

int						main(int ac, char **av)
{
	t_stc	*stc;

	stc = (t_stc*)malloc(sizeof(t_stc));
	if (ac == 1)
		showHelp(av[0]);
	stc->name = av[0];
	stc->ip = arg(av);
	singleton(stc);
	printf("%s\n", stc->ip);
	initAddr();
	ipConnect();
	ping();
	free(stc);
	return (0);
}
