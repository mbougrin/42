/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:56:26 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 06:53:49 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "display.h"

void	ft_creat_case(t_display *d)
{
	int		i;
	int		j;

	if ((d->map->map_case = malloc(sizeof(t_case) *
					(d->map->w * d->map->h))) == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < (d->map->w * d->map->h))
	{
		j = 0;
		while (j < 7)
		{
			d->map->map_case[i].loot[j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_creat_map(t_display *d, int w, int h)
{
	int		cal_size_w;
	int		cal_size_h;

	if (w <= 0 || h <= 0)
		exit(EXIT_FAILURE);
	d->map->w = w;
	d->map->h = h;
	cal_size_w = 0;
	while (w * (cal_size_w + 1) < MAX_WIDTH)
		cal_size_w++;
	cal_size_h = 0;
	while (h * (cal_size_h + 1) < MAX_HEIGHT)
		cal_size_h++;
	d->map->size_case = (cal_size_w < cal_size_h) ? cal_size_w : cal_size_h;
	d->map->map_w = d->map->w * d->map->size_case;
	d->map->map_h = d->map->h * d->map->size_case;
	if (cal_size_w == 0 || cal_size_h == 0)
	{
		ft_error("THE BIG MAP");
		exit(EXIT_FAILURE);
	}
	ft_creat_case(d);
}
