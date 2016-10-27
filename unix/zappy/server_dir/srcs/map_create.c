/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 13:01:33 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 07:01:20 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serv.h"

static void		ress_create(t_env *e, int i, int j)
{
	e->data.map[i][j].food = rand() % QT_MAX;
	e->data.map[i][j].linemate = rand() % QT_MAX;
	e->data.map[i][j].deraumere = rand() % QT_MAX;
	e->data.map[i][j].sibur = rand() % QT_MAX;
	e->data.map[i][j].mendiane = rand() % QT_MAX;
	e->data.map[i][j].phiras = rand() % QT_MAX;
	e->data.map[i][j].thystame = rand() % QT_MAX;
}

void			map_create(t_env *e)
{
	int		i;
	int		j;

	e->data.map = (t_case **)malloc(sizeof(t_case *) * e->data.size_y);
	i = 0;
	while (i < e->data.size_y)
	{
		e->data.map[i] = (t_case *)malloc(sizeof(t_case) * e->data.size_x);
		i++;
	}
	i = 0;
	while (i < e->data.size_y)
	{
		j = 0;
		while (j < e->data.size_x)
		{
			ress_create(e, i, j);
			j++;
		}
		i++;
	}
}
