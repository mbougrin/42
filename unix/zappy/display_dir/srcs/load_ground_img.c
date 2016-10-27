/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ground_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 00:13:37 by mblet             #+#    #+#             */
/*   Updated: 2014/06/21 18:43:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <time.h>
#include <mlx.h>

#include "display.h"

static void		ft_load_type_ground(t_display *d)
{
	int		i;

	if ((d->img->ground_img->ground_map =
				malloc(MAX_WIDTH * MAX_HEIGHT / 16 * sizeof(char))) == NULL)
		exit(EXIT_FAILURE);
	srand(time(NULL));
	i = 0;
	while (i < (MAX_WIDTH * MAX_HEIGHT / 16))
	{
		d->img->ground_img->ground_map[i] = rand() % 4;
		i++;
	}
}

static void		ft_load_img(t_display *d)
{
	d->img->ground_img->img_xpm = mlx_xpm_file_to_image(d->mlx->mlx,
			IMG_GROUND,
			&d->img->ground_img->w,
			&d->img->ground_img->h);
}

static void		ft_load_addr(t_display *d)
{
	d->img->ground_img->addr = (unsigned char *)mlx_get_data_addr(
			d->img->ground_img->img_xpm, &d->img->ground_img->bpp,
			&d->img->ground_img->size, &d->img->ground_img->endian);
}

void			ft_load_ground_img(t_display *d)
{
	if ((d->img->ground_img = malloc(sizeof(t_ground_img))) == NULL)
		exit(EXIT_FAILURE);
	ft_load_img(d);
	ft_load_addr(d);
	ft_load_type_ground(d);
}
