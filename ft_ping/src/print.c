/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:24:21 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/26 14:32:51 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void					print(void)
{
	t_stc	*stc;

	stc = singleton(NULL);
	if (stc->success)
	{
		printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%f ms\n",\
				PACKET_SIZE, stc->ip, stc->count, stc->ttl, stc->ms);
		stc->packetreceiv++;
	}
	else
		printf("Request timeout from icmp_seq %d\n", stc->count);
}

void					firstprint(t_addrinfo *tmp)
{
	t_stc					*stc;
	struct sockaddr_in		*test;

	test = (struct sockaddr_in*)tmp->ai_addr;
	stc = singleton(NULL);
	printf("%s %s (%s) 56(84) bytes of data\n", \
			stc->name, stc->ip, inet_ntoa(test->sin_addr));
}

static int				percentage(int nombre, int nombre2)
{
	return (((nombre2 - nombre) * 100 / nombre) * -1);
}

void					printsigint(void)
{
	t_stc			*stc;

	stc = singleton(NULL);
	printf("\n--- %s %s statistics ---\n", stc->ip, stc->name);
	printf("%d packets transmitted, %d received, %d%c packet loss, time \
			%fms\n", stc->count, stc->packetreceiv, \
			percentage(stc->count, stc->packetreceiv) \
			, '%', stc->allms);
	free(stc);
	exit(0);
}
