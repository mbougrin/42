/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 11:05:19 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 07:13:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "print_entity.h"
#include "print_loot.h"
#include "mlx_pixel_to_menu.h"
#include "print_view_entity_list.h"

static void		ft_draw_encar_menu(t_display *d, int js, int h, int color)
{
	int		i;
	int		j;
	int		dc;

	i = 20;
	d->mlx->color = color % 0xFFFFFF;
	d->mlx->color_d = 0xFFFFFF;
	dc = 352;
	while (i <= dc - 20)
	{
		j = js;
		while (j <= js + h)
		{
			if (!((i == 20 || i == dc - 20) && (j == js || j == js + h)))
			{
				if ((i == 20 || i == dc - 20))
					ft_put_pixel_to_menu(d, j, i);
				if ((j < js + 20 || j == js + h))
					ft_put_pixel_to_menu(d, j, i);
			}
			j++;
		}
		i++;
	}
}

static void		ft_print_team(t_display *d, int i, int c)
{
	char	*tmp;

	tmp = ft_strjoin("Team : ", d->team[i]);
	ft_mlx_font(d->font_img_small, 28, c + 6, 0x000000, tmp,
			d->menu->menu_img->addr, d->menu->menu_img->bpp,
			d->menu->menu_img->size);
	ft_mlx_font(d->font_img_small, 26, c + 6, 0x000000, tmp,
			d->menu->menu_img->addr, d->menu->menu_img->bpp,
			d->menu->menu_img->size);
	ft_mlx_font(d->font_img_small, 28, c + 4, 0x000000, tmp,
			d->menu->menu_img->addr, d->menu->menu_img->bpp,
			d->menu->menu_img->size);
	ft_mlx_font(d->font_img_small, 26, c + 4, 0x000000, tmp,
			d->menu->menu_img->addr, d->menu->menu_img->bpp,
			d->menu->menu_img->size);
	ft_mlx_font(d->font_img_small, 27, c + 5, 0xFFFFFF, tmp,
			d->menu->menu_img->addr, d->menu->menu_img->bpp,
			d->menu->menu_img->size);
	ft_strdel(&tmp);
}

void			ft_draw_menu_info(t_display *d)
{
	int		i;
	int		c;
	int		ddc;
	int		dc;
	int		color;

	i = 0;
	dc = 0;
	bzero((char *)d->menu->menu_img->addr, 360 * (MAX_HEIGHT - 120) * 8);
	while (d->team && d->team[i])
	{
		color = (int)((*(long *)d->team[i]) % 0xFFFFFF);
		c = ft_print_view_entity_list(d, i, dc);
		if (c > 0)
			ddc = (c > 5) ? ((c - 1) / 5) + 1 : 1;
		else
			ddc = 0;
		ft_draw_encar_menu(d, dc + 1, 20 + ddc * 62, color);
		ft_print_team(d, i, dc);
		dc = (c > 0) ? dc + 23 + ddc * 62 : dc + 23;
		i++;
	}
	d->menu->max = dc;
}
