/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 11:57:49 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 16:11:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx_pixel_to_img.h"

void	ft_print_v_grey_bar(t_display *d)
{
	int		i;
	float	j;

	i = 2;
	while (i < 17)
	{
		j = 60.f;
		while (j < (60.f + MAX_HEIGHT - 120.f))
		{
			d->mlx->color = 0xAAAAAA;
			d->mlx->color_d = 0xFFFFFF;
			ft_mlx_put_pixel_to_img(d, (int)j, i);
			j++;
		}
		i++;
	}
}

void	ft_print_v_bar(t_display *d)
{
	int		i;
	float	j;

	if (((d->menu->max) / (MAX_HEIGHT - 120.f)) >= 1)
	{
		i = 2;
		while (i < 17)
		{
			j = 60.f + d->menu->h / ((d->menu->max) / (MAX_HEIGHT - 120.f));
			while (j < (MAX_HEIGHT - 120.f) /
					(d->menu->max / (MAX_HEIGHT - 120.f))
					+ 60.f + d->menu->h / (d->menu->max / (MAX_HEIGHT - 120.f)))
			{
				d->mlx->color = 0xFFFFFF;
				d->mlx->color_d = 0xFFFFFF;
				ft_mlx_put_pixel_to_img(d, (int)j, i);
				j++;
			}
			i++;
		}
	}
	else
		ft_print_v_grey_bar(d);
}

void	ft_print_menu(t_display *d)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	d->mlx->x = 60 - d->menu->h;
	d->mlx->y = 0;
	k = d->menu->h;
	d->mlx->addr_t = d->menu->menu_img->addr;
	d->mlx->sizeline_t = d->menu->menu_img->size;
	d->mlx->bpp_t = d->menu->menu_img->bpp;
	while (i < 380)
	{
		j = k;
		while (j < k + MAX_HEIGHT - 120)
		{
			d->mlx->color_d = 0xFFFFFF;
			ft_mlx_check_pixel_to_img(d, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
