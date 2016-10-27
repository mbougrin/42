/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:49:39 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 14:31:50 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

static int		connect_nbr(char *team, t_env *e)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT)
		{
			if (e->fds[i].player.team
				&& ft_strcmp(team, e->fds[i].player.team) == 0)
				c++;
		}
		i++;
	}
	return (c);
}

static void		init_val(t_env *e, int cs, char *team, int n_co)
{
	srand(time(NULL));
	e->fds[cs].player.team = ft_strdup(team);
	e->fds[cs].player.pos_x = rand() % e->data.size_x;
	e->fds[cs].player.pos_y = rand() % e->data.size_y;
	e->fds[cs].player.food = 10;
	e->fds[cs].player.linemate = 0;
	e->fds[cs].player.deraumere = 0;
	e->fds[cs].player.sibur = 0;
	e->fds[cs].player.mendiane = 0;
	e->fds[cs].player.phiras = 0;
	e->fds[cs].player.thystame = 0;
	e->fds[cs].player.dir = N;
	e->fds[cs].player.lvl = 1;
	e->fds[cs].player.die = 0;
	sprintf(e->fds[cs].buf_write, "%d\n%d %d\n",
			(e->data.nb_client - n_co),
			e->data.size_x,
			e->data.size_y);
	ft_putstr_fd(e->fds[cs].buf_write, cs);
	ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
	e->fds[cs].player.time_life = clock()
		+ (126 * CLOCKS_PER_SEC / e->data.d_time);
}

static int		init_graph(t_env *e, int cs, char *team)
{
	if (ft_strcmp(e->fds[cs].buf_read, "GRAPHIC\n") == 0)
	{
		e->fds[cs].player.team = ft_strdup(team);
		sprintf(e->fds[cs].buf_write, "You are DISPLAY\n");
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		return (1);
	}
	return (0);
}

static void		not_connect(t_env *e, int cs, char *mess)
{
	close(cs);
	clean_fd(&e->fds[cs]);
	printf("%s [Client #%d]\n", mess, cs);
}

void			init_player(t_env *e, int cs)
{
	int		n_co;
	char	*team;

	team = ft_strtrim(e->fds[cs].buf_read);
	if (init_graph(e, cs, team))
	{
		free(team);
		return ;
	}
	if (team_exist(e->data.teams, team) == 0)
	{
		not_connect(e, cs, "Team not found");
		free(team);
		return ;
	}
	n_co = connect_nbr(team, e);
	if (n_co >= e->data.nb_client)
	{
		not_connect(e, cs, "Team full");
		free(team);
		return ;
	}
	init_val(e, cs, team, n_co);
	free(team);
}
