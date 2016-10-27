/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_button_stats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 01:52:48 by mblet             #+#    #+#             */
/*   Updated: 2014/06/24 18:15:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx_pixel_to_img.h"

void	ft_print_button_stats(t_display *d, int x, int y, int color_h)
{
	int		i;
	int		j;

	i = 0;
	d->mlx->x = y;
	d->mlx->y = x;
	d->mlx->addr_t = d->img->button_stats_img->addr;
	d->mlx->sizeline_t = d->img->button_stats_img->size;
	d->mlx->bpp_t = d->img->button_stats_img->bpp;
	while (i < d->img->button_stats_img->w)
	{
		j = 0;
		while (j < d->img->button_stats_img->h)
		{
			d->mlx->color_d = color_h;
			ft_mlx_check_pixel_to_img(d, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
