/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_button_stats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 01:47:06 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 01:50:18 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <mlx.h>

#include "display.h"

static void		ft_load_img(t_display *d)
{
	d->img->button_stats_img->img_xpm = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_BUTTON_STATS, &d->img->button_stats_img->w,
			&d->img->button_stats_img->h);
}

static void		ft_load_addr(t_display *d)
{
	d->img->button_stats_img->addr = (unsigned char *)mlx_get_data_addr(
			d->img->button_stats_img->img_xpm, &d->img->button_stats_img->bpp,
			&d->img->button_stats_img->size, &d->img->button_stats_img->endian);
}

void			ft_load_button_stats_img(t_display *d)
{
	if ((d->img->button_stats_img = malloc(sizeof(t_loot_img))) == NULL)
		exit(EXIT_FAILURE);
	ft_load_img(d);
	ft_load_addr(d);
}
