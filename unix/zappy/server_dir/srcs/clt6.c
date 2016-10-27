/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 07:02:50 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 08:00:33 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

int		clt_incantation_5(t_env *e, int cs)
{
	int		x;
	int		y;

	x = e->fds[cs].player.pos_x;
	y = e->fds[cs].player.pos_y;
	if (e->data.map[y][x].linemate >= 2 && e->data.map[y][x].deraumere >= 2
		&& e->data.map[y][x].sibur >= 1 && e->data.map[y][x].mendiane >= 3
		&& nb_joueur(e, x, y) >= 4)
		return (1);
	return (0);
}

int		clt_incantation_6(t_env *e, int cs)
{
	int		x;
	int		y;

	x = e->fds[cs].player.pos_x;
	y = e->fds[cs].player.pos_y;
	if (e->data.map[y][x].linemate >= 1 && e->data.map[y][x].deraumere >= 2
		&& e->data.map[y][x].sibur >= 3 && e->data.map[y][x].phiras >= 1
		&& nb_joueur(e, x, y) >= 6)
		return (1);
	return (0);
}

int		clt_incantation_7(t_env *e, int cs)
{
	int		x;
	int		y;
	char	msg[BUF_SIZE];

	x = e->fds[cs].player.pos_x;
	y = e->fds[cs].player.pos_y;
	if (e->data.map[y][x].linemate >= 2 && e->data.map[y][x].deraumere >= 2
		&& e->data.map[y][x].sibur >= 2 && e->data.map[y][x].mendiane >= 2
		&& e->data.map[y][x].phiras >= 2 && e->data.map[y][x].thystame >= 1
		&& nb_joueur(e, x, y) >= 6)
	{
		ft_bzero(msg, BUF_SIZE);
		sprintf(msg, "ppos\nseg %s\n", e->fds[cs].player.team);
		send_to_graph(e, msg);
		return (1);
	}
	return (0);
}
