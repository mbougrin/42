/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_entity_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 02:22:56 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 04:50:04 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <mlx.h>

#include "display.h"

static void		ft_load_img(t_display *d)
{
	d->img->entity_img->img_xpm[0] = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_ENTITY_LVL_1, &d->img->entity_img->w,
			&d->img->entity_img->h);
	d->img->entity_img->img_xpm[1] = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_ENTITY_LVL_2, &d->img->entity_img->w,
			&d->img->entity_img->h);
	d->img->entity_img->img_xpm[2] = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_ENTITY_LVL_3, &d->img->entity_img->w,
			&d->img->entity_img->h);
	d->img->entity_img->img_xpm[3] = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_ENTITY_LVL_4, &d->img->entity_img->w,
			&d->img->entity_img->h);
	d->img->entity_img->img_xpm[4] = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_ENTITY_LVL_5, &d->img->entity_img->w,
			&d->img->entity_img->h);
	d->img->entity_img->img_xpm[5] = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_ENTITY_LVL_6, &d->img->entity_img->w,
			&d->img->entity_img->h);
	d->img->entity_img->img_xpm[6] = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_ENTITY_LVL_7, &d->img->entity_img->w,
			&d->img->entity_img->h);
	d->img->entity_img->img_xpm[7] = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_ENTITY_LVL_8, &d->img->entity_img->w,
			&d->img->entity_img->h);
}

static void		ft_load_addr(t_display *d)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		d->img->entity_img->addr[i] = (unsigned char *)mlx_get_data_addr(
				d->img->entity_img->img_xpm[i], &d->img->entity_img->bpp[i],
				&d->img->entity_img->size[i], &d->img->entity_img->endian[i]);
		i++;
	}
}

void			ft_load_entity_img(t_display *d)
{
	if ((d->img->entity_img = malloc(sizeof(t_entity_img))) == NULL)
		exit(EXIT_FAILURE);
	ft_load_img(d);
	ft_load_addr(d);
}
