/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 18:34:35 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 20:38:47 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

static void		clt_voir_display(t_env *e, int cs, int x, int y)
{
	sprintf(e->fds[cs].buf_write, "%d %d %d %d %d %d %d %d\n",
			e->data.map[y][x].food,
			e->data.map[y][x].linemate,
			e->data.map[y][x].deraumere,
			e->data.map[y][x].sibur,
			e->data.map[y][x].mendiane,
			e->data.map[y][x].phiras,
			e->data.map[y][x].thystame,
			nb_joueur(e, x, y));
	ft_putstr_fd(e->fds[cs].buf_write, cs);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}

static int		clt_voir_x(t_env *e, int cs, int i, int j)
{
	int		x;

	if (e->fds[cs].player.dir == N)
		x = e->fds[cs].player.pos_x - i + j;
	else if (e->fds[cs].player.dir == E)
		x = e->fds[cs].player.pos_x + i;
	else if (e->fds[cs].player.dir == S)
		x = e->fds[cs].player.pos_x + i - j;
	else
		x = e->fds[cs].player.pos_x - i;
	if (x < 0)
		x = e->data.size_x + x;
	if (x > e->data.size_x - 1)
		x %= e->data.size_x;
	return (x);
}

static int		clt_voir_y(t_env *e, int cs, int i, int j)
{
	int		y;

	if (e->fds[cs].player.dir == N)
		y = e->fds[cs].player.pos_y - i;
	else if (e->fds[cs].player.dir == E)
		y = e->fds[cs].player.pos_y - i + j;
	else if (e->fds[cs].player.dir == S)
		y = e->fds[cs].player.pos_y + i;
	else
		y = e->fds[cs].player.pos_y + i - j;
	if (y < 0)
		y = e->data.size_y + y;
	if (y > e->data.size_y - 1)
		y %= e->data.size_y;
	return (y);
}

int				clt_voir(t_env *e, int cs)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	if (ft_strcmp(e->fds[cs].buf_read, "voir\n") == 0)
	{
		while (i <= e->fds[cs].player.lvl)
		{
			j = 0;
			while (j < (i * 2) + 1)
			{
				x = clt_voir_x(e, cs, i, j);
				y = clt_voir_y(e, cs, i, j);
				clt_voir_display(e, cs, x, y);
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}
