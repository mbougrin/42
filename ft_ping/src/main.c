/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:44 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/26 14:29:33 by mbougrin         ###   ########.fr       */
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
		sendtoerror();
	return (packet);
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

void					sig_handler(int sig)
{
	if (sig == SIGINT)
		printsigint();
}

void					ping(t_addrinfo *addr_info)
{
	t_stc 			*stc = singleton(NULL);
	t_sockaddr_in 	r_addr;
	t_packet		packet;

	socketconfig();
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
