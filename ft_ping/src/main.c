/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:44 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/26 14:39:56 by mbougrin         ###   ########.fr       */
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

		packet = sendpacket(addr_info);
		clock_gettime(CLOCK_MONOTONIC, &tstart);
		timeout();
		stc->ms = 0.0;
		stc->success = 0;
		if (recvfrom(stc->sd, &packet, sizeof(packet), 0, (t_sockaddr*)&r_addr, (socklen_t *)&len) > 0 )
			recvpacket(tend, tstart, packet);
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
