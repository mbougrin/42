/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_img_bg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 22:24:10 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 06:44:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void		ft_mlx_put_pixel_to_ground(t_display *d, int x, int y)
{
	int		i;

	i = y * (d->mlx->bpp >> 3) + x * d->mlx->size;
	d->mlx->addr3[i] = (d->mlx->color & d->mlx->color_d);
	d->mlx->addr3[i + 1] = (d->mlx->color & d->mlx->color_d) >> 8;
	d->mlx->addr3[i + 2] = (d->mlx->color & d->mlx->color_d) >> 16;
}

static void		ft_mlx_check_pixel_to_bg(t_display *d, int x, int y, int ncolor)
{
	int		i;
	void	*tmp;

	tmp = d->mlx->addr_t + (x * d->mlx->sizeline_t + (d->mlx->bpp_t >> 3) * y);
	i = *(int *)tmp;
	if (i != ncolor)
	{
		d->mlx->color = i;
		ft_mlx_put_pixel_to_ground(d, x + d->mlx->x, y + d->mlx->y);
	}
}

static void		ft_print_groung(t_display *d, int x, int y, int type)
{
	int		i;
	int		j;

	i = type * 16;
	d->mlx->x = x;
	d->mlx->y = y;
	d->mlx->addr_t = d->img->ground_img->addr;
	d->mlx->sizeline_t = d->img->ground_img->size;
	d->mlx->bpp_t = d->img->ground_img->bpp;
	while (i < d->img->ground_img->w)
	{
		j = 0;
		while (j < d->img->ground_img->h && x +
				j < MAX_HEIGHT)
		{
			d->mlx->color_d = 0xFFFFFF;
			ft_mlx_check_pixel_to_bg(d, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void			ft_creat_img_bg(t_display *d)
{
	int		i;
	int		j;
	int		u;

	i = 0;
	u = 0;
	while (i < MAX_WIDTH)
	{
		j = 0;
		while (j < MAX_HEIGHT)
		{
			ft_print_groung(d, j, i, d->img->ground_img->ground_map[u]);
			u++;
			j += 16;
		}
		i += 16;
	}
}
