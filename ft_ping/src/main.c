/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:44 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/26 14:09:46 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_stc					*singleton(t_stc *stc)
{
	static t_stc	*singleton;

	if (stc != NULL)
		singleton = stc;
	return (singleton);
}

void					firstPrint(t_addrinfo *tmp)
{
	t_stc		*stc = singleton(NULL);
	struct sockaddr_in *test = (struct sockaddr_in*)tmp->ai_addr;

	printf("%s %s (%s) 56(84) bytes of data\n", \
			stc->name, stc->ip, inet_ntoa(test->sin_addr));
}

char					*arg(char **av)
{
	int			i;
   
	i = 1;
	while (av[i])
	{
		if (ft_strcmp(av[i], "-h") == 0)
			showhelp(av[0]);
		else if (av[i][0] != '-')
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
	{
		printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%f ms\n",\
				PACKET_SIZE, stc->ip, stc->count, stc->ttl, stc->ms);
		stc->packetreceiv++;
	}
	else
		printf("Request timeout from icmp_seq %d\n", stc->count);
}

void					sendToError(void)
{
	t_stc 			*stc = singleton(NULL);

	printf("sendto error\n");
	free(stc);
	exit(-1);
}

t_packet				sendPacket(t_addrinfo *addr_info)
{
	t_stc 			*stc = singleton(NULL);
	t_packet		packet;

	ft_bzero(&packet, sizeof(packet));
	packet.hdr.type = ICMP_ECHO;
	packet.hdr.un.echo.id = stc->pid;
	packet.hdr.un.echo.sequence = stc->count + 1;
	packet.hdr.checksum = checksum(&packet, sizeof(packet));
	if (sendto(stc->sd, &packet, sizeof(packet), 0, addr_info->ai_addr, sizeof(*addr_info->ai_addr)) <= 0)
		sendToError();
	return (packet);
}

void					socketConfig(void)
{
	t_stc 			*stc = singleton(NULL);
	const int 		val = 255;

	stc->sd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (stc->sd < 0) 
		socketerror();
	if (setsockopt(stc->sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0)
		setsockopterror();
}

void					recvPacket(struct timespec tend, struct timespec tstart, t_packet packet)
{
	t_stc 			*stc = singleton(NULL);

	clock_gettime(CLOCK_MONOTONIC, &tend);
	stc->ms = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec) - \
			  ((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	stc->allms += stc->ms;
	struct icmp *pkt;
	struct iphdr *iphdr = (struct iphdr *) &packet;
	pkt = (struct icmp *) (&packet + (iphdr->ihl << 2));
	stc->ttl = iphdr->ttl;
	if (pkt->icmp_type == ICMP_ECHOREPLY)
	{
		stc->success = 1;
		print();
	}
	else 
		print();
}

void					timeout(void)
{
	t_stc 			*stc = singleton(NULL);

	struct timeval timeout;
	timeout.tv_sec = WAIT;
	timeout.tv_usec = 0;
	setsockopt(stc->sd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));
}

int						percentage(int nombre, int nombre2)
{
	  return (((nombre2 - nombre)* 100 / nombre) * -1);
}

void					printSigint(void)
{
	t_stc 			*stc = singleton(NULL);

	printf("\n--- %s %s statistics ---\n", stc->ip, stc->name);
	printf("%d packets transmitted, %d received, %d%c packet loss, time %fms\n", \
			stc->count, stc->packetreceiv, percentage(stc->count, stc->packetreceiv), '%', stc->allms);
	free(stc);
	exit(0);
}

void					sig_handler(int sig)
{
	if (sig == SIGINT)
		printSigint();
}

void					ping(t_addrinfo *addr_info)
{
	t_stc 			*stc = singleton(NULL);
	t_sockaddr_in 	r_addr;
	t_packet		packet;

	socketConfig();
	stc->count = 1;
	stc->packetreceiv = 0;
	stc->allms = 0.0;
	signal(SIGINT, sig_handler);
	while (stc->count < NUMBER_PACKET)
	{
		int len = sizeof(r_addr);
		struct timespec tstart={0,0}, tend={0,0};

		packet = sendPacket(addr_info);
		clock_gettime(CLOCK_MONOTONIC, &tstart);
		timeout();
		stc->ms = 0.0;
		stc->success = 0;
		if (recvfrom(stc->sd, &packet, sizeof(packet), 0, (t_sockaddr*)&r_addr, (socklen_t *)&len) > 0 )
			recvPacket(tend, tstart, packet);
		else
			print();
		sleep(SLEEP);
		stc->count++;
	}
}

int						main(int ac, char **av)
{
	t_stc	*stc;

	stc = (t_stc*)malloc(sizeof(t_stc));
	if (ac == 1)
		showhelp(av[0]);
	stc->name = av[0];
	stc->ip = arg(av);
	stc->pid = getpid();
	stc->sd = 0;
	singleton(stc);
	initaddr();
	ipconnect();
	ping(stc->addr);
	free(stc);
	return (0);
}
