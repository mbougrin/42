/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_loot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 23:50:51 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 09:32:39 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "draw_menu_info.h"
#include "mlx_pixel_to_img.h"
#include "mlx_pixel_to_menu.h"

void	ft_print_loot_to_menu(t_display *d, int x, int y, int type)
{
	int		i;
	int		j;

	i = type * 10;
	d->mlx->x = y;
	d->mlx->y = x - type * 10;
	d->mlx->addr_t = d->img->loot_img->addr;
	d->mlx->sizeline_t = d->img->loot_img->size;
	d->mlx->bpp_t = d->img->loot_img->bpp;
	while (i < d->img->loot_img->h + type * 10)
	{
		j = 0;
		while (j < d->img->loot_img->h)
		{
			d->mlx->color_d = 0xFFFFFF;
			ft_check_pixel_to_menu(d, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	ft_print_loot(t_display *d, int x, int y, int type)
{
	int		i;
	int		j;

	i = type * 10;
	d->mlx->x = y;
	d->mlx->y = x - type * 10;
	d->mlx->addr_t = d->img->loot_img->addr;
	d->mlx->sizeline_t = d->img->loot_img->size;
	d->mlx->bpp_t = d->img->loot_img->bpp;
	while (i < d->img->loot_img->h + type * 10)
	{
		j = 0;
		while (j < d->img->loot_img->h)
		{
			d->mlx->color_d = 0xFFFFFF;
			ft_mlx_check_pixel_to_img(d, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
