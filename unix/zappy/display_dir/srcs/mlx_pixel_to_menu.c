/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_to_menu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 09:28:42 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 09:28:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_put_pixel_to_menu(t_display *d, int x, int y)
{
	unsigned char	*i;
	int				color;
	int				color_d;

	i = d->menu->menu_img->addr + (y *
			(d->menu->menu_img->bpp >> 3) + x * d->menu->menu_img->size);
	color_d = d->mlx->color_d;
	color = d->mlx->color;
	*i++ = (color & color_d);
	*i++ = (color & color_d) >> 8;
	*i = (color & color_d) >> 16;
}

void	ft_check_pixel_to_menu(t_display *d, int x, int y, int bg_color)
{
	int		i;
	void	*tmp;

	tmp = d->mlx->addr_t + (x * d->mlx->sizeline_t + (d->mlx->bpp_t >> 3) * y);
	i = *(int *)tmp;
	if (i != bg_color)
	{
		d->mlx->color = i;
		ft_put_pixel_to_menu(d, x + d->mlx->x, y + d->mlx->y);
	}
}

void	ft_check_pixel_to_menu_x_2(t_display *d, int x, int y, int bg_color)
{
	int		i;
	void	*tmp;

	tmp = d->mlx->addr_t + (x * d->mlx->sizeline_t + (d->mlx->bpp_t >> 3) * y);
	i = *(int *)tmp;
	if (i != bg_color)
	{
		d->mlx->color = i;
		ft_put_pixel_to_menu(d, x * 2 + d->mlx->x, y * 2 + d->mlx->y);
		ft_put_pixel_to_menu(d, x * 2 + d->mlx->x + 1, y * 2 + d->mlx->y);
		ft_put_pixel_to_menu(d, x * 2 + d->mlx->x, y * 2 + 1 + d->mlx->y);
		ft_put_pixel_to_menu(d, x * 2 + d->mlx->x + 1, y * 2 + 1 + d->mlx->y);
	}
}
