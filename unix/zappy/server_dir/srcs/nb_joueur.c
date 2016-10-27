/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_joueur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:38:23 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 20:38:46 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

int		nb_joueur(t_env *e, int x, int y)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT)
		{
			if (e->fds[i].player.pos_x == x
				&& e->fds[i].player.pos_y == y)
				c++;
		}
		i++;
	}
	return (c);
}
