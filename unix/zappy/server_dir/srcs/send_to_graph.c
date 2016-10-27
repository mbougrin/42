/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 07:20:07 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 07:29:22 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "serv.h"

void	send_to_graph(t_env *e, char *s)
{
	int		i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT
			&& ft_strcmp(e->fds[i].player.team, "GRAPHIC") == 0)
		{
			ft_bzero(e->fds[i].buf_mem, BUF_SIZE);
			sprintf(e->fds[i].buf_mem, "%s", s);
		}
		i++;
	}
}
