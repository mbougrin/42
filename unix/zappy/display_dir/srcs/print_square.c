/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 18:40:52 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 18:59:11 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "print_loot.h"

static void		ft_print_check_ressource2(t_display *d, int i, int d_x, int d_y)
{
	if (d->map->map_case[i].loot[4] && d->map->size_case > 32)
		ft_print_loot(d, d_x + d->map->size_case / 6 + (d->map->size_case -
					32) / 6 - 5, d_y + (d->map->size_case * 5) / 6 -
				(d->map->size_case - 32) / 6 - 5, 4);
	if (d->map->map_case[i].loot[5] && d->map->size_case > 32)
		ft_print_loot(d, d_x + d->map->size_case / 2 - 5,
				d_y + (d->map->size_case * 5) / 6 -
				(d->map->size_case - 32) / 6 - 5, 5);
	if (d->map->map_case[i].loot[6] && d->map->size_case > 32)
		ft_print_loot(d, d_x + d->map->size_case * 5 / 6 +
				(d->map->size_case - (d->map->size_case - 32) / 6) - 4 -
				d->map->size_case,
				d_y + (d->map->size_case * 5) / 6 -
				(d->map->size_case - 32) / 6 - 5, 6);
}

static void		ft_print_check_ressource1(t_display *d, int i, int d_x, int d_y)
{
	if (d->map->map_case[i].loot[0])
		ft_print_loot(d, d_x + d->map->size_case / 2 - 5,
				d_y + d->map->size_case / 2 - 5, 0);
	if (d->map->map_case[i].loot[1] && d->map->size_case > 32)
		ft_print_loot(d, d_x + d->map->size_case / 6 +
				(d->map->size_case - 32) / 6 - 5, d_y + d->map->size_case /
				6 + (d->map->size_case - 32) / 6 - 5, 1);
	if (d->map->map_case[i].loot[2] && d->map->size_case > 32)
		ft_print_loot(d, d_x + d->map->size_case / 2 - 5, d_y +
				d->map->size_case / 6 + (d->map->size_case - 32) / 6 - 5, 2);
	if (d->map->map_case[i].loot[3] && d->map->size_case > 32)
		ft_print_loot(d, d_x + d->map->size_case * 5 / 6 +
				(d->map->size_case - (d->map->size_case - 32) / 6) - 4 -
				d->map->size_case, d_y + d->map->size_case / 6 +
				(d->map->size_case - 32) / 6 - 5, 3);
}

void			ft_print_square(t_display *d)
{
	int		i;
	int		d_y;
	int		d_x;

	i = 0;
	while (i < (d->map->w * d->map->h))
	{
		d_x = (i * d->map->size_case) %
			(d->map->size_case * d->map->w) + (MAX_WIDTH - d->map->map_w) / 2;
		d_y = (i / d->map->w) * d->map->size_case +
			(MAX_HEIGHT - d->map->map_h) / 2;
		ft_print_check_ressource1(d, i, d_x, d_y);
		ft_print_check_ressource2(d, i, d_x, d_y);
		i++;
	}
}
