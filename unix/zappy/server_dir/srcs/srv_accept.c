/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:28:34 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 16:36:13 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "serv.h"

void	srv_accept(t_env *e, int s)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;
	int					set;

	set = 1;
	csin_len = sizeof(csin);
	cs = X(-1, accept(s, (struct sockaddr*)&csin, &csin_len), "accept");
	setsockopt(cs, SOL_SOCKET, SO_NOSIGPIPE, (void *)&set, sizeof(int));
	printf("New client #%d from %s:%d\n", cs,
			inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
	clean_fd(&e->fds[cs]);
	e->fds[cs].type = FD_CLIENT;
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_cmd = client_cmd;
	e->fds[cs].fct_write = client_write;
	ft_bzero(e->fds[cs].buf_read, BUF_SIZE);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
	ft_bzero(e->fds[cs].buf_mem, BUF_SIZE);
	e->fds[cs].player.team = NULL;
	e->fds[cs].player.time_life = 0;
	e->fds[cs].player.time_block = 0;
	ft_strcpy(e->fds[cs].buf_read, "BIENVENUE\n");
}
