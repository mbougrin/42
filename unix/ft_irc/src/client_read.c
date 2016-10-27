/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:11:29 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/23 17:37:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "bircd.h"

void	client_exit(t_env *e, int cs)
{
	close(cs);
	clean_fd(&e->fds[cs]);
	ft_putstr("client #");
	ft_putnbr(cs);
	ft_putstr("gone away\n");
}

void	nick(t_env *e, int cs)
{
	ft_strdel(&e->fds[cs].nick_name);
	e->fds[cs].nick_name = ft_strdup(&e->fds[cs].buf_read[6]);
}

void	who(t_env *e, int cs)
{
	int		i;

	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) && i != cs)
		{
			ft_putendl_fd(e->fds[i].nick_name, cs);
			ft_strclr(e->fds[cs].buf_read);
		}
		i++;
	}
}

void	ft_print(t_env *e, int cs)
{
	int		i;

	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) && (i != cs))
		{
			ft_putstr_fd(e->fds[cs].nick_name, i);
			ft_putstr_fd(": ", i);
			ft_putendl_fd(e->fds[cs].buf_read, i);
			ft_strclr(e->fds[cs].buf_read);
		}
		i++;
	}
}

void	client_read(t_env *e, int cs)
{
	int		r;

	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
		client_exit(e, cs);
	else
	{
		write(1, e->fds[cs].buf_read, ft_strlen(e->fds[cs].buf_read));
		ft_putchar('\n');
		if (e->fds[cs].buf_read[0] == '/' && \
			e->fds[cs].buf_read[1] == 'n' && \
			e->fds[cs].buf_read[2] == 'i' && \
			e->fds[cs].buf_read[3] == 'c' && \
			e->fds[cs].buf_read[4] == 'k')
			nick(e, cs);
		else if (e->fds[cs].buf_read[0] == '/' && \
			e->fds[cs].buf_read[1] == 'w' && \
			e->fds[cs].buf_read[2] == 'h' && \
			e->fds[cs].buf_read[3] == 'o')
			who(e, cs);
		else
			ft_print(e, cs);
	}
}
