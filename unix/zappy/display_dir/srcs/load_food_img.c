/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_food_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 02:35:41 by mblet             #+#    #+#             */
/*   Updated: 2014/06/21 18:42:44 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <mlx.h>

#include "display.h"

static void		ft_load_img(t_display *d)
{
	d->img->loot_img->img_xpm = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_LOOT, &d->img->loot_img->w,
			&d->img->loot_img->h);
}

static void		ft_load_addr(t_display *d)
{
	d->img->loot_img->addr = (unsigned char *)mlx_get_data_addr(
			d->img->loot_img->img_xpm, &d->img->loot_img->bpp,
			&d->img->loot_img->size, &d->img->loot_img->endian);
}

void			ft_load_loot_img(t_display *d)
{
	if ((d->img->loot_img = malloc(sizeof(t_loot_img))) == NULL)
		exit(EXIT_FAILURE);
	ft_load_img(d);
	ft_load_addr(d);
}
