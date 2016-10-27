/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_popup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 23:13:32 by mblet             #+#    #+#             */
/*   Updated: 2014/06/25 23:35:30 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "display.h"
#include "mlx_pixel_to_img.h"
#include "print_loot.h"

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

	ia_0 = ft_itoa(d->map->map_case[e].loot[0]);
	ia_1 = ft_itoa(d->map->map_case[e].loot[1]);
	ia_2 = ft_itoa(d->map->map_case[e].loot[2]);
	ia_3 = ft_itoa(d->map->map_case[e].loot[3]);
	ia_4 = ft_itoa(d->map->map_case[e].loot[4]);
	ia_5 = ft_itoa(d->map->map_case[e].loot[5]);
	ia_6 = ft_itoa(d->map->map_case[e].loot[6]);
	s = ft_strijoin(ia_0, " - Life\n\n", ia_1, " - Linemate\n\n",
			ia_2, " - Deraumere\n\n", ia_3, " - Sibur\n\n",
			ia_4, " - Mendiane\n\n", ia_5, " - Phirase\n\n",
			ia_6, " - Thystame", NULL);
	ft_mlx_font(d->font_img_small, i + 50, j + 28, 0XFFFFFF, s,
			d->mlx->addr, d->mlx->bpp, d->mlx->size);
	ft_stridel(&ia_0, &ia_1, &ia_2, &ia_3, &ia_4, &ia_5, &ia_6, &s, NULL);
}

static void		ft_print_list_inv(t_display *d, int i, int j, int e)
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

static int		ft_print_cases(t_display *d, int i, int j)
{
	char	*s;
	char	*t1;
	char	*t2;
	int		tmp_x;
	int		tmp_y;

	t1 = ft_itoa(i / d->map->size_case);
	t2 = ft_itoa(j / d->map->size_case);
	s = ft_strijoin("case: ", t1, ", ", t2, NULL);
	tmp_x = (d->popup->x > MAX_WIDTH - 180) ? MAX_WIDTH - 180 : d->popup->x;
	tmp_y = (d->popup->y > MAX_HEIGHT - 210) ? MAX_HEIGHT - 210 : d->popup->y;
	ft_mlx_font(d->font_img_small,
			tmp_x + 50, tmp_y + 3, 0xFFFFFF, s,
			d->mlx->addr, d->mlx->bpp, d->mlx->size);
	ft_stridel(&t1, &t2, &s, NULL);
	return (i / d->map->size_case + j / d->map->size_case * d->map->w);
}

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

void			ft_print_popup(t_display *d)
{
	int		tmp_x;
	int		tmp_y;
	int		x;
	int		y;
	int		cases;

	x = d->popup->x;
	y = d->popup->y;
	if (!(x > 10 && x <= 107 && y > 10 && y <= 50)
			&& !(d->menu->is_open && x > 0 && x <= 331 && y > 60
			&& y <= MAX_HEIGHT - 60) && x != 0 && y != 0
		&& x > (MAX_WIDTH - d->map->map_w) / 2
		&& x < (MAX_WIDTH - d->map->map_w) / 2 + d->map->map_w
		&& y > (MAX_HEIGHT - d->map->map_h) / 2
		&& y < (MAX_HEIGHT - d->map->map_h) / 2 + d->map->map_h)
	{
		tmp_x = (x > MAX_WIDTH - 180) ? MAX_WIDTH - 180 : x;
		tmp_y = (y > MAX_HEIGHT - 210) ?
			MAX_HEIGHT - 210 : d->popup->y;
		ft_print_window(d, tmp_x, tmp_y);
		cases = ft_print_cases(d,
				x - (MAX_WIDTH - d->map->map_w) / 2,
				y - (MAX_HEIGHT - d->map->map_h) / 2);
		ft_print_list_inv(d, tmp_x, tmp_y, cases);
	}
}
