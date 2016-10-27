/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:33:14 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 13:39:47 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

static void		graph_mct_display(t_env *e, int cs, int i, int j)
{
	sprintf(e->fds[cs].buf_write, "bct %d %d %d %d %d %d %d %d %d\n",
			j,
			i,
			e->data.map[i][j].food,
			e->data.map[i][j].linemate,
			e->data.map[i][j].deraumere,
			e->data.map[i][j].sibur,
			e->data.map[i][j].mendiane,
			e->data.map[i][j].phiras,
			e->data.map[i][j].thystame);
	ft_putstr_fd(e->fds[cs].buf_write, cs);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}

int				graph_mct(t_env *e, int cs)
{
	int		i;
	int		j;

	if (ft_strcmp(e->fds[cs].buf_read, "mct\n") == 0)
	{
		i = 0;
		while (i < e->data.size_y)
		{
			j = 0;
			while (j < e->data.size_x)
			{
				graph_mct_display(e, cs, i, j);
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int				graph_tna(t_env *e, int cs)
{
	int		i;

	if (ft_strcmp(e->fds[cs].buf_read, "tna\n") == 0)
	{
		i = 0;
		while (e->data.teams[i])
		{
			sprintf(e->fds[cs].buf_write, "tna %s\n",
					e->data.teams[i]);
			ft_putstr_fd(e->fds[cs].buf_write, cs);
			ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
			i++;
		}
		return (1);
	}
	return (0);
}

static void		graph_ppos_display(t_env *e, int cs, int i)
{
	sprintf(e->fds[cs].buf_write,
			"ppos %d %d %d %d %d %s %d %d %d %d %d %d %d\n",
			i,
			e->fds[i].player.pos_x,
			e->fds[i].player.pos_y,
			e->fds[i].player.dir,
			e->fds[i].player.lvl,
			e->fds[i].player.team,
			e->fds[i].player.food,
			e->fds[i].player.linemate,
			e->fds[i].player.deraumere,
			e->fds[i].player.sibur,
			e->fds[i].player.mendiane,
			e->fds[i].player.phiras,
			e->fds[i].player.thystame);
	ft_putstr_fd(e->fds[cs].buf_write, cs);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}

int				graph_ppos(t_env *e, int cs)
{
	int		i;

	if (ft_strcmp(e->fds[cs].buf_read, "ppos\n") == 0)
	{
		i = 0;
		while (i < e->maxfd)
		{
			if (e->fds[i].type == FD_CLIENT
				&& team_exist(e->data.teams, e->fds[i].player.team))
				graph_ppos_display(e, cs, i);
			i++;
		}
		return (1);
	}
	return (0);
}
