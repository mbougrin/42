/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_in_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 10:04:14 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 18:11:50 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		ft_check_if_in_menu(t_display *d, int x, int y, int button)
{
	if (x > 120 && x <= 220 && y > 20 && y <= 40)
	{
		if (button == MOUSE_SCROLL_DOWN && d->sgt > 1)
			d->sgt -= 1;
		if (button == MOUSE_SCROLL_UP && d->sgt < 1000)
			d->sgt += 1;
		return (1);
	}
	if (d->menu->is_open && x > 0 && x <= 349 && y > 60 && y <= MAX_HEIGHT - 60)
	{
		if (button == MOUSE_SCROLL_DOWN
			&& d->menu->h < d->menu->max - MAX_HEIGHT + 120)
			d->menu->h += 1;
		if (button == MOUSE_SCROLL_UP && d->menu->h > 0)
			d->menu->h -= 1;
		return (1);
	}
	return (0);
}
