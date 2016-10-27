/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:12:33 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 07:55:15 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

static t_cmd_reader		g_cmd_readers[] =
{
	graph_msz,
	graph_mct,
	graph_tna,
	graph_ppos,
	graph_sgt,
	graph_sst,
	graph_seg,
	clt_avance,
	clt_tourne,
	clt_inventaire,
	clt_mort,
	clt_prend,
	clt_pose,
	clt_voir,
	clt_incantation
};

static void	ft_bienvenue(t_env *e, int cs)
{
	sprintf(e->fds[cs].buf_write, "BIENVENUE\n");
	ft_putstr_fd(e->fds[cs].buf_write, cs);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}

int			ft_cmd(t_env *e, int cs)
{
	size_t					i;

	if (ft_strcmp(e->fds[cs].buf_read, "BIENVENUE\n") == 0)
	{
		ft_bienvenue(e, cs);
		return (0);
	}
	if (e->fds[cs].player.team == NULL)
		init_player(e, cs);
	else
	{
		i = 0;
		while (i < (sizeof(g_cmd_readers) / sizeof(t_cmd_reader)))
		{
			if (g_cmd_readers[i++](e, cs))
				return (1);
		}
		return (-1);
	}
	return (0);
}
