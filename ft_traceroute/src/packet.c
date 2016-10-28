/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:36:52 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/28 11:58:51 by mbougrin         ###   ########.fr       */
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
	packet.hdr.un.echo.sequence = stc->ttl + 1;
	packet.hdr.checksum = checksum(&packet, sizeof(packet));
	if (sendto(stc->sd, &packet, sizeof(packet), 0, addr_info->ai_addr, \
				sizeof(*addr_info->ai_addr)) <= 0)
		sendtoerror();
	return (packet);
}

int test_is_end(t_ip *ip)
{
	char			ip_buf[512];
	t_stc			*stc;

	stc = singleton(NULL);
	inet_ntop(AF_INET, (void*)&(ip->ip_src.s_addr), ip_buf, BUFFSIZE);
	return (strcmp(stc->hostname, ip_buf) == 0);
}

void					recvpacket(struct timeval tend, \
						struct timeval tstart, t_packet packet)
{
	t_stc				*stc;

	stc = singleton(NULL);
	gettimeofday(&tend, NULL);
	stc->ms = (double)((tend.tv_sec - tstart.tv_sec) * 1000.0f);
	stc->ms += (double)((tend.tv_usec - tstart.tv_usec) / 1000.0f);
	stc->success = 1;
	stc->stcip = (t_ip*)&packet;
	print();
	if (test_is_end((t_ip*)&packet))
		exit(-1);
}

void					timeout(void)
{
	t_stc			*stc;
	struct timeval	timeout;

	stc = singleton(NULL);
	timeout.tv_sec = WAIT;
	timeout.tv_usec = 0;
	setsockopt(stc->sd, IPPROTO_ICMP, SO_RCVTIMEO, (char *)&timeout, \
			sizeof(struct timeval));
}
