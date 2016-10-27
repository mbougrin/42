/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 13:59:40 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/27 11:55:59 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void					socketconfig(void)
{
	t_stc			*stc;
	const int		val = 255;

	stc = singleton(NULL);
	stc->sd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (stc->sd < 0)
		socketerror();
	if (setsockopt(stc->sd, SOL_IP, IP_TTL, &val, sizeof(val)) != 0)
		setsockopterror();
}

void					showhelp(char *str)
{
	printf("Usage: %s [-h] destination IP\n", str);
	free(singleton(NULL));
	exit(-1);
}

void					initaddr(void)
{
	t_stc		*stc;

	stc = singleton(NULL);
	stc->hints.ai_family = AF_UNSPEC;
	stc->hints.ai_socktype = SOCK_DGRAM;
	stc->hints.ai_flags = 0;
	stc->hints.ai_protocol = 0;
}

unsigned short			checksum(void *b, int len)
{
	unsigned short		*buf;
	unsigned int		sum;
	unsigned short		result;

	buf = b;
	sum = 0;
	result = 0;
	while (len > 1)
	{
		sum += *buf++;
		len -= 2;
	}
	if (len == 1)
		sum += *(unsigned char*)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	return (result);
}

void					ipconnect(void)
{
	t_stc		*stc;
	t_addrinfo	*tmp;
	t_addrinfo	*result;

	stc = singleton(NULL);
	if ((getaddrinfo(stc->ip, NULL, &stc->hints, &result)) != 0)
		addrerror();
	tmp = result;
	while (tmp != NULL)
	{
		stc->fd = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);
		if (stc->fd == -1)
			continue ;
		if (connect(stc->fd, tmp->ai_addr, tmp->ai_addrlen) != -1)
		{
			//firstprint(tmp);
			close(stc->fd);
			break ;
		}
		close(stc->fd);
		tmp = tmp->ai_next;
	}
	if (tmp == NULL)
		connecterror();
	stc->addr = tmp;
}
