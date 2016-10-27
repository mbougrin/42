/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 21:02:20 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 07:03:33 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

int		clt_incantation_1(t_env *e, int cs)
{
	int		x;
	int		y;

	x = e->fds[cs].player.pos_x;
	y = e->fds[cs].player.pos_y;
	if (e->data.map[y][x].linemate >= 1)
		return (1);
	return (0);
}

int		clt_incantation_2(t_env *e, int cs)
{
	int		x;
	int		y;

	x = e->fds[cs].player.pos_x;
	y = e->fds[cs].player.pos_y;
	if (e->data.map[y][x].linemate >= 1 && e->data.map[y][x].deraumere >= 1
		&& e->data.map[y][x].sibur >= 1 && nb_joueur(e, x, y) >= 2)
		return (1);
	return (0);
}

int		clt_incantation_3(t_env *e, int cs)
{
	int		x;
	int		y;

	x = e->fds[cs].player.pos_x;
	y = e->fds[cs].player.pos_y;
	if (e->data.map[y][x].linemate >= 2 && e->data.map[y][x].sibur >= 1
		&& e->data.map[y][x].phiras >= 2 && nb_joueur(e, x, y) >= 2)
		return (1);
	return (0);
}

int		clt_incantation_4(t_env *e, int cs)
{
	int		x;
	int		y;

	x = e->fds[cs].player.pos_x;
	y = e->fds[cs].player.pos_y;
	if (e->data.map[y][x].linemate >= 1 && e->data.map[y][x].deraumere >= 1
		&& e->data.map[y][x].sibur >= 2 && e->data.map[y][x].phiras >= 1
		&& nb_joueur(e, x, y) >= 4)
		return (1);
	return (0);
}

int		clt_incantation(t_env *e, int cs)
{
	if (ft_strcmp(e->fds[cs].buf_read, "incantation\n") == 0)
	{
		if ((e->fds[cs].player.lvl == 1 && clt_incantation_1(e, cs))
			|| (e->fds[cs].player.lvl == 2 && clt_incantation_2(e, cs))
			|| (e->fds[cs].player.lvl == 3 && clt_incantation_3(e, cs))
			|| (e->fds[cs].player.lvl == 4 && clt_incantation_4(e, cs))
			|| (e->fds[cs].player.lvl == 5 && clt_incantation_5(e, cs))
			|| (e->fds[cs].player.lvl == 6 && clt_incantation_6(e, cs))
			|| (e->fds[cs].player.lvl == 7 && clt_incantation_7(e, cs)))
		{
			e->fds[cs].player.lvl++;
			sprintf(e->fds[cs].buf_write, "elevation en cours\n");
		}
		else
			sprintf(e->fds[cs].buf_write, "elevation impossible\n");
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		e->fds[cs].player.time_block = clock()
			+ (300 * CLOCKS_PER_SEC / e->data.d_time);
		return (1);
	}
	return (0);
}
