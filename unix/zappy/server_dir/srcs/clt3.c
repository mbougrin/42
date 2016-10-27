/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 16:38:32 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 17:06:12 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

static int		pose_item_display(char *item, t_env *e, int cs)
{
	int		x;
	int		y;

	y = e->fds[cs].player.pos_y;
	x = e->fds[cs].player.pos_x;
	if (!ft_strcmp(item, "food\n"))
	{
		if (e->fds[cs].player.food > 0)
		{
			e->data.map[y][x].food++;
			e->fds[cs].player.food--;
			return (1);
		}
	}
	if (!ft_strcmp(item, "linemate\n"))
	{
		if (e->fds[cs].player.linemate > 0)
		{
			e->data.map[y][x].linemate++;
			e->fds[cs].player.linemate--;
			return (1);
		}
	}
	return (0);
}

static int		pose_item_display_2(char *item, t_env *e, int cs)
{
	int		x;
	int		y;

	y = e->fds[cs].player.pos_y;
	x = e->fds[cs].player.pos_x;
	if (!ft_strcmp(item, "deraumere\n"))
	{
		if (e->fds[cs].player.deraumere > 0)
		{
			e->data.map[y][x].deraumere++;
			e->fds[cs].player.deraumere--;
			return (1);
		}
	}
	if (!ft_strcmp(item, "sibur\n"))
	{
		if (e->fds[cs].player.sibur > 0)
		{
			e->data.map[y][x].sibur++;
			e->fds[cs].player.sibur--;
			return (1);
		}
	}
	return (0);
}

static int		pose_item_display_3(char *item, t_env *e, int cs)
{
	int		x;
	int		y;

	y = e->fds[cs].player.pos_y;
	x = e->fds[cs].player.pos_x;
	if (!ft_strcmp(item, "mendiane\n"))
	{
		if (e->fds[cs].player.mendiane > 0)
		{
			e->data.map[y][x].mendiane++;
			e->fds[cs].player.mendiane--;
			return (1);
		}
	}
	if (!ft_strcmp(item, "phiras\n"))
	{
		if (e->fds[cs].player.phiras > 0)
		{
			e->data.map[y][x].phiras++;
			e->fds[cs].player.phiras--;
			return (1);
		}
	}
	return (0);
}

static int		pose_item(char *item, t_env *e, int cs)
{
	int		x;
	int		y;

	y = e->fds[cs].player.pos_y;
	x = e->fds[cs].player.pos_x;
	if (pose_item_display(item, e, cs))
		return (1);
	if (pose_item_display_2(item, e, cs))
		return (1);
	if (pose_item_display_3(item, e, cs))
		return (1);
	if (!ft_strcmp(item, "thystame\n"))
	{
		if (e->fds[cs].player.thystame > 0)
		{
			e->data.map[y][x].thystame++;
			e->fds[cs].player.thystame--;
			return (1);
		}
	}
	return (0);
}

int				clt_pose(t_env *e, int cs)
{
	if (ft_strncmp(e->fds[cs].buf_read, "pose ", 5) == 0)
	{
		if (pose_item(e->fds[cs].buf_read + 5, e, cs))
			sprintf(e->fds[cs].buf_write, "ok\n");
		else
			sprintf(e->fds[cs].buf_write, "ko\n");
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		e->fds[cs].player.time_block = clock()
			+ (7 * CLOCKS_PER_SEC / e->data.d_time);
		return (1);
	}
	return (0);
}
