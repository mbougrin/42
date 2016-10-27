/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 18:20:04 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 07:39:24 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "display.h"
#include "draw_menu_info.h"
#include "mlx_pixel_to_img.h"
#include "mlx_pixel_to_menu.h"

void	ft_print_entity_to_menu(t_display *d, int type, int lvl)
{
	int		i;
	int		j;

	i = 0;
	d->mlx->x = d->mlx->x - type * 64;
	d->mlx->y = d->mlx->y;
	d->mlx->addr_t = d->img->entity_img->addr[lvl];
	d->mlx->sizeline_t = d->img->entity_img->size[lvl];
	d->mlx->bpp_t = d->img->entity_img->bpp[lvl];
	while (i < 31)
	{
		j = type * 32;
		while (j < type * 32 + 31)
		{
			ft_check_pixel_to_menu_x_2(d, j, i, 0xFF00FF);
			j++;
		}
		i++;
	}
}

void	ft_print_text(t_display *d, int x, int y, t_entity *e)
{
	char	*tmp;

	tmp = ft_itoa(e->n);
	ft_mlx_font(d->font_img_small, y + 21, x + 21, 0x000000, tmp,
			d->mlx->addr, d->mlx->bpp, d->mlx->size);
	ft_mlx_font(d->font_img_small, y + 20, x + 20, 0xFFFFFF, tmp,
			d->mlx->addr, d->mlx->bpp, d->mlx->size);
	ft_strdel(&tmp);
}

int		ft_find_color_team(t_display *d, char *t)
{
	int		i;

	i = 0;
	while (d->team[i])
	{
		if (t)
		{
			if (!ft_strcmp(d->team[i], t))
				break ;
		}
		i++;
	}
	return ((int)((*(long *)d->team[i]) % 0xFFFFFF));
}

void	ft_print_entity(t_display *d, int x, int y, t_entity *e)
{
	int		i;
	int		j;

	if (e && e->loot[0] > 0 && e->lvl)
	{
		d->mlx->color_d = e->color_team;
		d->mlx->x = x - e->o * 32;
		d->mlx->y = y;
		d->mlx->addr_t = d->img->entity_img->addr[e->lvl - 1];
		d->mlx->sizeline_t = d->img->entity_img->size[e->lvl - 1];
		d->mlx->bpp_t = d->img->entity_img->bpp[e->lvl - 1];
		i = 0;
		while (i < 31)
		{
			j = e->o * 32;
			while (j < e->o * 32 + 31)
			{
				ft_mlx_check_pixel_to_img(d, j, i, 0xFF00FF);
				j++;
			}
			i++;
		}
		ft_print_text(d, x, y, e);
	}
}

void	ft_print_entity_run(t_display *d, int x, int y, t_entity *e)
{
	int		i;
	int		j;

	if (e && e->loot[0] > 0 && e->lvl)
	{
		d->mlx->color_d = e->color_team;
		i = e->anim_2 * 32;
		d->mlx->x = x - e->o * 32;
		d->mlx->y = y - e->anim_2 * 32;
		d->mlx->addr_t = d->img->entity_img->addr[e->lvl - 1];
		d->mlx->sizeline_t = d->img->entity_img->size[e->lvl - 1];
		d->mlx->bpp_t = d->img->entity_img->bpp[e->lvl - 1];
		while (i < e->anim_2 * 32 + 31)
		{
			j = e->o * 32;
			while (j < e->o * 32 + 31)
			{
				ft_mlx_check_pixel_to_img(d, j, i, 0xFF00FF);
				j++;
			}
			i++;
		}
		e->anim_2 = ((e->anim_2 + 1) % 2);
		ft_print_text(d, x, y, e);
	}
}
