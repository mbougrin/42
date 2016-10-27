/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:22:27 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 12:43:48 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "serv.h"

static void		ft_cut(char *s, int n)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (n <= 0)
			s[i] = '\0';
		if (s[i] == '\n')
			n--;
		i++;
	}
}

void			client_read(t_env *e, int cs)
{
	int		r;
	int		n_cmd;

	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("Client #%d gone away\n", cs);
	}
	else
	{
		n_cmd = count_cmd(e->fds[cs].buf_mem);
		if (n_cmd < 10)
		{
			ft_cut(e->fds[cs].buf_read, (10 - n_cmd));
			ft_strcat(e->fds[cs].buf_mem, e->fds[cs].buf_read);
		}
		ft_bzero(e->fds[cs].buf_read, BUF_SIZE);
	}
}
