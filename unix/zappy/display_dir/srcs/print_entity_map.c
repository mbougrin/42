/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 02:34:33 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 02:42:33 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "creat_entity.h"
#include "print_entity.h"

void	ft_anim_entity_map(t_display *d, int x, int y, t_entity *e)
{
	if (d->n >= d->map->size_case)
		e->anim = 0;
	if (e->anim)
	{
		if (e->o == 0)
			ft_print_entity_run(d, x - d->n + d->map->size_case, y, e);
		else if (e->o == 1)
			ft_print_entity_run(d, x, y + d->n - d->map->size_case, e);
		else if (e->o == 2)
			ft_print_entity_run(d, x + d->n - d->map->size_case, y, e);
		else if (e->o == 3)
			ft_print_entity_run(d, x, y - d->n + d->map->size_case, e);
	}
	else
		ft_print_entity(d, x, y, e);
}

void	ft_print_entity_map(t_display *d)
{
	unsigned int	i;
	unsigned int	j;
	int				d_x;
	int				d_y;

	i = 0;
	d_x = (MAX_WIDTH - d->map->map_w) / 2;
	d_y = (MAX_HEIGHT - d->map->map_h) / 2;
	j = ft_listlen(d->entity);
	while (i < j)
	{
		ft_anim_entity_map(d,
				d->entity[i]->y * d->map->size_case + d->map->size_case / 2 +
				d_y - 21,
				d->entity[i]->x * d->map->size_case + d->map->size_case / 2 +
				d_x - 15, d->entity[i]);
		i++;
	}
	if (d->n >= d->map->size_case)
		d->n = 0;
	d->n += d->sgt / d->fps;
}
