/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:24:21 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/28 15:56:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void					printfirst(void)
{
	t_stc	*stc;

	stc = singleton(NULL);
	if (ft_strcmp(stc->ip, "127.0.0.1") == 0)
	{
		printf("%s to localhost (%s), %d hops max, %d byte packets\n", \
			stc->name, stc->hostname, DEFMAXTTL, PACKET_SIZE);
	}
	else
		printf("%s to %s (%s), %d hops max, %d byte packets\n", \
			stc->name, stc->ip, stc->hostname, DEFMAXTTL, PACKET_SIZE);
}

void					print(void)
{
	t_stc			*stc;
	struct hostent	*client;
	char			ip_buf[512];
	const char		*client_name;

	stc = singleton(NULL);
	if (stc->success)
	{
		inet_ntop(AF_INET, (void*)&(stc->stcip->ip_src.s_addr), ip_buf, \
				BUFFSIZE);
		client = gethostbyaddr((void*)&(stc->stcip->ip_src.s_addr), \
				sizeof(stc->stcip->ip_src.s_addr), AF_INET);
		if (client == NULL)
			client_name = ip_buf;
		else
			client_name = client->h_name;
		printf("%4d %s (%s) %.3f ms\n",
				stc->count, client_name, ip_buf, stc->ms);
		stc->count++;
	}
}
