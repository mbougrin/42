/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_menu_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 10:32:48 by mblet             #+#    #+#             */
/*   Updated: 2014/06/24 20:49:34 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

#include "display.h"

static void		ft_load_img(t_display *d)
{
	d->menu->menu_img->img = mlx_new_image(d->mlx->mlx, 360,
			(int)MAX_HEIGHT * 10);
}

static void		ft_load_addr(t_display *d)
{
	d->menu->menu_img->addr = (unsigned char *)mlx_get_data_addr(
			d->menu->menu_img->img, &d->menu->menu_img->bpp,
			&d->menu->menu_img->size, &d->menu->menu_img->endian);
}

void			ft_creat_menu_img(t_display *d)
{
	if ((d->menu->menu_img = malloc(sizeof(t_menu_img))) == NULL)
		exit(EXIT_FAILURE);
	ft_load_img(d);
	ft_load_addr(d);
}
