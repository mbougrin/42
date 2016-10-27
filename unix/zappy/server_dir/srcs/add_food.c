/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_food.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 07:07:03 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 07:08:01 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

void		add_food_map(t_env *e)
{
	int		x;
	int		y;

	x = rand() % e->data.size_x;
	y = rand() % e->data.size_y;
	while (e->data.map[y][x].food > QT_MAX)
	{
		x = rand() % e->data.size_x;
		y = rand() % e->data.size_y;
	}
	e->data.map[y][x].food++;
}
