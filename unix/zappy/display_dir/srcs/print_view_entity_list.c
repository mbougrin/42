/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_view_entity_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 09:38:53 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 03:26:36 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "display.h"
#include "print_entity.h"
#include "print_loot.h"
#include "mlx_pixel_to_menu.h"

static void		ft_draw_encar_entity(t_display *d, int js, int is)
{
	int		i;
	int		j;

	i = is;
	d->mlx->color = 0xFFFFFF;
	d->mlx->color_d = 0xFFFFFF;
	while (i <= is + 60)
	{
		j = js;
		while (j <= js + 60)
		{
			if (!((i == is || i == is + 60) && (j == js || j == js + 60)))
			{
				if ((i == is || i == is + 60))
					ft_put_pixel_to_menu(d, j, i);
				if ((j == js || j == js + 60))
					ft_put_pixel_to_menu(d, j, i);
			}
			j++;
		}
		i++;
	}
}

static void		ft_print_view_entity(t_display *d, t_entity *e, int x, int y)
{
	char	*lvl;
	char	*lvl2;

	d->mlx->x = x + 22;
	d->mlx->y = y + 22;
	d->mlx->color = 0xFFFFFF;
	d->mlx->color_d = ft_find_color_team(d, e->t);
	ft_print_entity_to_menu(d, e->o, e->lvl - 1);
	ft_draw_encar_entity(d, x + 22, y + 22);
	lvl = ft_itoa(e->lvl);
	lvl2 = ft_strijoin("lvl:", lvl, NULL);
	ft_mlx_font(d->font_img_small, y + 33, x + 32, 0xFFFFFF, lvl2,
			d->menu->menu_img->addr, d->menu->menu_img->bpp,
			d->menu->menu_img->size);
	ft_stridel(&lvl, &lvl2, NULL);
	lvl = ft_itoa(e->loot[0]);
	lvl2 = ft_strijoin(":", lvl, NULL);
	ft_mlx_font(d->font_img_small, y + 33, x + 22, 0xFFFFFF, lvl2,
			d->menu->menu_img->addr, d->menu->menu_img->bpp,
			d->menu->menu_img->size);
	ft_stridel(&lvl, &lvl2, NULL);
	ft_print_loot_to_menu(d, y + 23, x + 22, 0);
}

int				ft_print_view_entity_list(t_display *d, int i, int y)
{
	int		n;
	int		h;
	char	*nu;

	h = 0;
	n = 0;
	while (d->entity[h])
	{
		if (!ft_strcmp(d->entity[h]->t, d->team[i])
				&& d->entity[h]->loot[0] > 0)
		{
			ft_print_view_entity(d, d->entity[h], y + (n / 5) * 62,
					n * 62 - (n / 5) * 5 * 62);
			nu = ft_itoa(d->entity[h]->n);
			ft_mlx_font(d->font_img_small,
					n * 62 - (n / 5) * 5 * 62 + 23, y + (n / 5) * 62 + 71,
					0xFFFFFF, nu,
					d->menu->menu_img->addr, d->menu->menu_img->bpp,
					d->menu->menu_img->size);
			ft_strdel(&nu);
			n++;
		}
		h++;
	}
	return (n);
}
