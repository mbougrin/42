/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 04:21:58 by mblet             #+#    #+#             */
/*   Updated: 2014/06/24 20:51:22 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

#include "display.h"
#include "mlx_pixel_to_img.h"
#include "print_button_stats.h"
#include "print_menu.h"
#include "draw_menu_info.h"

static void		*ft_draw_menu_bg(void *e)
{
	t_display	*d;
	int			i;
	int			j;
	int			i2;

	d = (t_display *)e;
	i = 0;
	j = 60;
	i2 = i;
	while (j < MAX_HEIGHT - 60)
	{
		i = i2;
		while (i < i2 + 334)
		{
			if (i != 18 && i != 0)
			{
				d->mlx->color_d = 3;
				ft_mlx_dec_pixel_to_img(d, j, i);
			}
			i++;
		}
		j++;
	}
	return (NULL);
}

static void		ft_get_hover(t_display *d)
{
	int		x;
	int		y;

	x = d->popup->x;
	y = d->popup->y;
	if (x > 10 && x <= 107
		&& y > 10 && y <= 50)
		ft_print_button_stats(d, 10, 10, 0xAAFFFF);
	else if (d->menu->is_open)
		ft_print_button_stats(d, 10, 10, 0xAAFFAA);
	else
		ft_print_button_stats(d, 10, 10, 0xFFFFFF);
}

void			ft_menu(t_display *d)
{
	if (d->menu->is_open)
	{
		ft_draw_menu_bg(d);
		ft_draw_menu_info(d);
		ft_print_menu(d);
		ft_print_v_bar(d);
	}
	ft_get_hover(d);
}
