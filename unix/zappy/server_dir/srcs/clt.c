/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:53:27 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 21:02:54 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

int				clt_tourne(t_env *e, int cs)
{
	if (ft_strcmp(e->fds[cs].buf_read, "gauche\n") == 0)
	{
		e->fds[cs].player.dir = (e->fds[cs].player.dir + 3) % 4;
		sprintf(e->fds[cs].buf_write, "ok\n");
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		e->fds[cs].player.time_block = clock()
			+ (7 * CLOCKS_PER_SEC / e->data.d_time);
		return (1);
	}
	else if (ft_strcmp(e->fds[cs].buf_read, "droite\n") == 0)
	{
		e->fds[cs].player.dir = (e->fds[cs].player.dir + 1) % 4;
		sprintf(e->fds[cs].buf_write, "ok\n");
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		e->fds[cs].player.time_block = clock()
			+ (7 * CLOCKS_PER_SEC / e->data.d_time);
		return (1);
	}
	return (0);
}

static void		clt_avance_display(t_env *e, int cs)
{
	if (e->fds[cs].player.dir == N)
	{
		e->fds[cs].player.pos_y--;
		if (e->fds[cs].player.pos_y < 0)
			e->fds[cs].player.pos_y = e->data.size_y - 1;
	}
	else if (e->fds[cs].player.dir == E)
	{
		e->fds[cs].player.pos_x++;
		if (e->fds[cs].player.pos_x > e->data.size_x - 1)
			e->fds[cs].player.pos_x = 0;
	}
	else if (e->fds[cs].player.dir == S)
	{
		e->fds[cs].player.pos_y++;
		if (e->fds[cs].player.pos_y > e->data.size_y - 1)
			e->fds[cs].player.pos_y = 0;
	}
	else if (e->fds[cs].player.dir == O)
	{
		e->fds[cs].player.pos_x--;
		if (e->fds[cs].player.pos_x < 0)
			e->fds[cs].player.pos_x = e->data.size_x - 1;
	}
}

int				clt_avance(t_env *e, int cs)
{
	if (ft_strcmp(e->fds[cs].buf_read, "avance\n") == 0)
	{
		clt_avance_display(e, cs);
		sprintf(e->fds[cs].buf_write, "ok\n");
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		e->fds[cs].player.time_block = clock()
			+ (7 * CLOCKS_PER_SEC / e->data.d_time);
		return (1);
	}
	return (0);
}

int				clt_inventaire(t_env *e, int cs)
{
	if (ft_strcmp(e->fds[cs].buf_read, "inventaire\n") == 0)
	{
		sprintf(e->fds[cs].buf_write, "%d %d %d %d %d %d %d\n",
				e->fds[cs].player.food,
				e->fds[cs].player.linemate,
				e->fds[cs].player.deraumere,
				e->fds[cs].player.sibur,
				e->fds[cs].player.mendiane,
				e->fds[cs].player.phiras,
				e->fds[cs].player.thystame);
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		e->fds[cs].player.time_block = clock()
			+ (1 * CLOCKS_PER_SEC / e->data.d_time);
		return (1);
	}
	return (0);
}

int				clt_mort(t_env *e, int cs)
{
	if (ft_strcmp(e->fds[cs].buf_read, "mort\n") == 0)
	{
		e->fds[cs].player.die = 1;
		sprintf(e->fds[cs].buf_write, "mort\n");
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("Client #%d died and gone away\n", cs);
		return (1);
	}
	return (0);
}
