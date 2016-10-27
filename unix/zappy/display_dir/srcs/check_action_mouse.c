/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 04:06:05 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 12:41:20 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_check_action_mouse(t_display *d, int x, int y)
{
	if (x > 10 && x <= 107 && y > 10 && y <= 50)
	{
		d->menu->is_open = (d->menu->is_open) ? 0 : 1;
		if (d->menu->is_open)
			d->menu->h = 0;
	}
}
