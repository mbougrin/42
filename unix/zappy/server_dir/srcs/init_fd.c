/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:26:12 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 07:19:55 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <stdio.h>
#include "serv.h"

static void		is_die(t_env *e, int i)
{
	ft_bzero(e->fds[i].buf_mem, BUF_SIZE);
	sprintf(e->fds[i].buf_mem, "mort\n");
}

static void		init_cmd(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT)
		{
			if (e->fds[i].player.time_life
				&& clock() >= e->fds[i].player.time_life)
			{
				if ((e->fds[i].player.food--) <= 0)
					is_die(e, i);
				e->fds[i].player.time_life = clock()
					+ (126 * CLOCKS_PER_SEC / e->data.d_time);
			}
			if (ft_strlen(e->fds[i].buf_mem) > 0)
			{
				if (clock() >= e->fds[i].player.time_block)
					e->fds[i].fct_cmd(e, i);
			}
		}
		i++;
	}
}

void			init_fd(t_env *e)
{
	int		i;

	i = 0;
	e->max = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	init_cmd(e);
	while (i < e->maxfd)
	{
		if (e->fds[i].type != FD_FREE)
		{
			FD_SET(i, &e->fd_read);
			if (ft_strlen(e->fds[i].buf_read) > 0)
				FD_SET(i, &e->fd_write);
			e->max = MAX(e->max, i);
		}
		i++;
	}
}
