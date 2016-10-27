/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 17:44:55 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 06:56:16 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_mlx_put_pixel_to_img(t_display *d, int x, int y)
{
	unsigned char	*i;
	int				color;
	int				color_d;

	if (y > MAX_WIDTH || x > MAX_HEIGHT)
		return ;
	i = d->mlx->addr + (y * (d->mlx->bpp >> 3) + x * d->mlx->size);
	color_d = d->mlx->color_d;
	color = d->mlx->color;
	*i++ = (color & color_d);
	*i++ = (color & color_d) >> 8;
	*i = (color & color_d) >> 16;
}

void	ft_mlx_dec_pixel_to_img(t_display *d, int x, int y)
{
	unsigned int	color;
	unsigned char	*i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	i = d->mlx->addr + y * (d->mlx->bpp >> 3) + x * d->mlx->size;
	b = *i++;
	g = *i++;
	r = *i;
	color = (r + b + g) / 3 / d->mlx->color_d;
	*i-- = color;
	*i-- = color;
	*i-- = color;
}

void	ft_mlx_check_pixel_to_img(t_display *d, int x, int y, int bg_color)
{
	int		i;
	void	*tmp;

	if (x + d->mlx->x > MAX_HEIGHT || y + d->mlx->y > MAX_WIDTH)
		return ;
	tmp = d->mlx->addr_t + (x * d->mlx->sizeline_t + (d->mlx->bpp_t >> 3) * y);
	i = *(int *)tmp;
	if (i != bg_color)
	{
		d->mlx->color = i;
		ft_mlx_put_pixel_to_img(d, x + d->mlx->x, y + d->mlx->y);
	}
}
