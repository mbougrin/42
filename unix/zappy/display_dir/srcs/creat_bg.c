/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_bg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 12:49:15 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 18:06:40 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

#include "display.h"

static void		ft_mlx_put_pixel_to_bg(t_display *d, int x, int y, int color)
{
	int		i;
	int		color_d;

	i = y * (d->mlx->bpp >> 3) + x * d->mlx->size;
	color_d = d->mlx->color_d;
	d->mlx->addr2[i] = (color & color_d);
	d->mlx->addr2[i + 1] = (color & color_d) >> 8;
	d->mlx->addr2[i + 2] = (color & color_d) >> 16;
}

static void		ft_creat_bg_next(t_display *d, int u, int cw, int ch)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAX_WIDTH)
	{
		j = 0;
		while (j < MAX_HEIGHT)
		{
			if (i < cw || j < ch || j - ch > d->map->map_h
				|| i - cw > d->map->map_w)
				ft_mlx_put_pixel_to_bg(d, j, i, 0x424242);
			else if (u % 5 && !((0 - i + cw) % d->map->size_case
					&& (j + d->map->size_case - ch) % d->map->size_case))
				ft_mlx_put_pixel_to_bg(d, j, i, 0x005500);
			j++;
			u++;
		}
		u++;
		i++;
	}
}

static void		ft_get_img_bg(t_display *d)
{
	memcpy(d->mlx->addr2, d->mlx->addr3, MAX_WIDTH * MAX_HEIGHT * 4);
}

void			ft_creat_bg(t_display *d)
{
	ft_get_img_bg(d);
	d->mlx->color_d = 0xFFFFFF;
	ft_creat_bg_next(d,
			0,
			(MAX_WIDTH - d->map->map_w) / 2,
			(MAX_HEIGHT - d->map->map_h) / 2);
}
