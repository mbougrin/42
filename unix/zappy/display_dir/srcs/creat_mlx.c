/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 21:14:05 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 10:20:03 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>

#include "display.h"
#include "xpm_file_to_img.h"
#include "mlx_hook.h"
#include "mlx_expose.h"
#include "my_mlx_font.h"
#include "creat_bg.h"
#include "creat_img_bg.h"

void	ft_creat_mlx(t_display *d)
{
	d->mlx->mlx = mlx_init();
	d->mlx->win = mlx_new_window(d->mlx->mlx, MAX_WIDTH, MAX_HEIGHT, "Zappy");
	d->mlx->img = mlx_new_image(d->mlx->mlx, MAX_WIDTH, MAX_HEIGHT);
	d->mlx->img2 = mlx_new_image(d->mlx->mlx, MAX_WIDTH, MAX_HEIGHT);
	d->mlx->img3 = mlx_new_image(d->mlx->mlx, MAX_WIDTH, MAX_HEIGHT);
	d->mlx->addr = (unsigned char *)mlx_get_data_addr(d->mlx->img,
			&d->mlx->bpp, &d->mlx->size, &d->mlx->endian);
	d->mlx->addr2 = (unsigned char *)mlx_get_data_addr(d->mlx->img2,
			&d->mlx->bpp, &d->mlx->size, &d->mlx->endian);
	d->mlx->addr3 = (unsigned char *)mlx_get_data_addr(d->mlx->img3,
			&d->mlx->bpp, &d->mlx->size, &d->mlx->endian);
	ft_xpm_file_to_img(d);
	d->font_img_small = ft_load_file_font(d->mlx->mlx, IMG_FONT_SMALL);
	d->font_img_big = ft_load_file_font(d->mlx->mlx, IMG_FONT_BIG);
	ft_creat_img_bg(d);
	ft_creat_bg(d);
	ft_mlx_hook(d);
	ft_mlx_expose(d);
}
