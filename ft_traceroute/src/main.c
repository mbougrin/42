/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:44 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/27 11:59:51 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
/*
static void				initprintfirst(void)
{
	t_stc		*stc;

	stc = singleton(NULL);
	stc->count = 1;
	stc->packetreceiv = 0;
	stc->allms = 0.0;
	signal(SIGINT, sig_handler);
}
*/
void					ping(t_addrinfo *addr_info)
{
	t_stc				*stc;
	t_sockaddr_in		r_addr;
	t_packet			packet;
	struct timespec		tstart;
	struct timespec		tend;

	stc = singleton(NULL);
	socketconfig();
//	initprintfirst();
	while (stc->count < NUMBER_PACKET)
	{
		stc->len = sizeof(r_addr);
		packet = sendpacket(addr_info);
	//	clock_gettime(CLOCK_MONOTONIC, &tstart);
		gettimeofday(&tstart, NULL);
		timeout();
		stc->ms = 0.0;
		stc->success = 0;
		if (recvfrom(stc->sd, &packet, sizeof(packet), 0, \
					(t_sockaddr*)&r_addr, (socklen_t *)&stc->len) > 0)
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
