/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:36:52 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/27 12:03:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_packet				sendpacket(t_addrinfo *addr_info)
{
	t_stc			*stc;
	t_packet		packet;

	stc = singleton(NULL);
	ft_bzero(&packet, sizeof(packet));
	packet.hdr.type = ICMP_ECHO;
	packet.hdr.un.echo.id = stc->pid;
	packet.hdr.un.echo.sequence = stc->count + 1;
	packet.hdr.checksum = checksum(&packet, sizeof(packet));
	if (sendto(stc->sd, &packet, sizeof(packet), 0, addr_info->ai_addr, \
				sizeof(*addr_info->ai_addr)) <= 0)
		sendtoerror();
	return (packet);
}

void					recvpacket(struct timeval tend, \
						struct timeval tstart, t_packet packet)
{
	t_stc				*stc;
	struct icmp			*pkt;
	struct iphdr		*iphdr;

	stc = singleton(NULL);
//	clock_gettime(CLOCK_MONOTONIC, &tend);
	gettimeofday(&tend, NULL);
	stc->ms = (double)((tend->tv_sec - tstart->tv_sec) * 1000.0f);
	stc->ms += (double)((tend->tv_usec - tstart->tv_usec) / 1000.0f);
//	stc->ms = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec) - \
//					((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	stc->allms += stc->ms;
	iphdr = (struct iphdr *)&packet;
	pkt = (struct icmp *)(&packet + (iphdr->ihl << 2));
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
	t_stc			*stc;
	struct timeval	timeout;

	stc = singleton(NULL);
	timeout.tv_sec = WAIT;
	timeout.tv_usec = 0;
	setsockopt(stc->sd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, \
			sizeof(struct timeval));
}
