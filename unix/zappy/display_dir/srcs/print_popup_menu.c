/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_popup_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 23:13:32 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 07:47:36 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "display.h"
#include "mlx_pixel_to_img.h"
#include "print_loot.h"

static void		ft_print_window(t_display *d, int i, int j)
{
	int		i2;
	int		j2;

	i2 = i;
	j2 = j;
	while (j < j2 + 209)
	{
		i = i2;
		while (i < i2 + 179)
		{
			if (j < j2 + 17)
			{
				d->mlx->color_d = 5;
				ft_mlx_dec_pixel_to_img(d, j, i + 1);
			}
			else
			{
				d->mlx->color_d = 3;
				ft_mlx_dec_pixel_to_img(d, j, i + 1);
			}
			i++;
		}
		j++;
	}
}

static void		ft_print_list_inv2(t_display *d, int i, int j, int e)
{
	char	*ia_0;
	char	*ia_1;
	char	*ia_2;
	char	*ia_3;
	char	*ia_4;
	char	*ia_5;
	char	*ia_6;
	char	*s;

	ia_0 = ft_itoa(d->entity[e]->loot[0]);
	ia_1 = ft_itoa(d->entity[e]->loot[1]);
	ia_2 = ft_itoa(d->entity[e]->loot[2]);
	ia_3 = ft_itoa(d->entity[e]->loot[3]);
	ia_4 = ft_itoa(d->entity[e]->loot[4]);
	ia_5 = ft_itoa(d->entity[e]->loot[5]);
	ia_6 = ft_itoa(d->entity[e]->loot[6]);
	s = ft_strijoin(ia_0, " - Life\n\n", ia_1, " - Linemate\n\n",
			ia_2, " - Deraumere\n\n", ia_3, " - Sibur\n\n",
			ia_4, " - Mendiane\n\n", ia_5, " - Phirase\n\n",
			ia_6, " - Thystame", NULL);
	ft_mlx_font(d->font_img_small, i + 50, j + 28, 0XFFFFFF, s,
			d->mlx->addr, d->mlx->bpp, d->mlx->size);
	ft_stridel(&ia_0, &ia_1, &ia_2, &ia_3, &ia_4, &ia_5, &ia_6, &s, NULL);
}

static void		ft_info_window(t_display *d, int i, int j, int e)
{
	int		t;

	t = 0;
	while (t < 7)
	{
		ft_print_loot(d, i + 30, j + 29 + t * 26, t);
		t++;
	}
	ft_print_list_inv2(d, i, j, e);
}

static int		ft_check_view_entity_list(t_display *d, int i, int y)
{
	int		n;
	int		h;

	h = 0;
	n = 0;
	while (d->entity && d->entity[h])
	{
		if (!ft_strcmp(d->entity[h]->t, d->team[i])
			&& d->entity[h]->loot[0] > 0)
		{
			if (d->popup->x > (n * 62 - (n / 5) * 5 * 62 + 22)
				&& d->popup->x < (n * 62 - (n / 5) * 5 * 62 + 22 + 62)
				&& d->popup->y > (y + (n / 5) * 62 + 22)
				&& d->popup->y < (y + (n / 5) * 62 + 22 + 62))
			{
				ft_print_window(d, d->popup->x, d->popup->y);
				ft_info_window(d, d->popup->x, d->popup->y, h);
			}
			n++;
		}
		h++;
	}
	return (n);
}

void			ft_print_popup_menu(t_display *d)
{
	int		i;
	int		c;
	int		dc;
	int		ddc;

	i = 0;
	dc = 0;
	if (d->menu->is_open && d->popup->y > 60 && d->popup->y < MAX_HEIGHT - 60)
	{
		while (d->team && d->team[i])
		{
			c = ft_check_view_entity_list(d, i, dc + 60 - d->menu->h);
			if (c > 0)
				ddc = (c > 5) ? ((c - 1) / 5) + 1 : 1;
			else
				ddc = 0;
			dc = (c > 0) ? dc + 23 + ddc * 62 : dc + 23;
			i++;
		}
	}
}
