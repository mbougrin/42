/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 04:14:10 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 07:31:57 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "display.h"
#include "my_mlx_font.h"
#include "creat_bg.h"
#include "menu.h"
#include "print_square.h"
#include "print_entity_map.h"
#include "mlx_pixel_to_img.h"
#include "get_seg.h"

static void		ft_get_bg(t_display *d)
{
	memcpy(d->mlx->addr, d->mlx->addr2, MAX_WIDTH * MAX_HEIGHT * 4);
}

static void		ft_bg_sgt(t_display *d)
{
	int		i;
	int		j;

	i = 120;
	while (i < 220)
	{
		j = 20;
		while (j < 40)
		{
			d->mlx->color = 0x777777;
			d->mlx->color_d = 0xFFFFFF;
			ft_mlx_put_pixel_to_img(d, j, i);
			j++;
		}
		i++;
	}
}

static void		ft_get_sgt(t_display *d)
{
	char	*s1;
	char	*s2;

	ft_bg_sgt(d);
	s1 = ft_itoa(d->sgt);
	s2 = ft_strjoin("sgt:", s1);
	ft_mlx_font(d->font_img_small, 122, 24, 0x000000, s2,
			d->mlx->addr, d->mlx->bpp, d->mlx->size);
	ft_mlx_font(d->font_img_small, 123, 23, 0xFFFFFF, s2,
			d->mlx->addr, d->mlx->bpp, d->mlx->size);
	ft_stridel(&s1, &s2, NULL);
}

static void		ft_get_fps(t_display *d)
{
	static clock_t	t1;
	static clock_t	t2;
	char			*s1;
	char			*s2;

	t1 = t2;
	t2 = clock();
	if (t2 - t1 > 0)
	{
		d->fps = 1000000 / (t2 - t1);
		s1 = ft_itoa(d->fps);
		s2 = ft_strjoin("fps:", s1);
		ft_mlx_font(d->font_img_small, MAX_WIDTH - 60, 1, 0x000000, s2,
				d->mlx->addr, d->mlx->bpp, d->mlx->size);
		ft_mlx_font(d->font_img_small, MAX_WIDTH - 61, 0, 0xFFFFFF, s2,
				d->mlx->addr, d->mlx->bpp, d->mlx->size);
		ft_stridel(&s1, &s2, NULL);
	}
}

void			*ft_thread_loop(void *e)
{
	t_display	*d;

	d = (t_display *)e;
	while (d->winner == NULL)
	{
		pthread_mutex_lock(&d->mutex_display);
		ft_get_bg(d);
		ft_get_fps(d);
		ft_print_square(d);
		ft_print_entity_map(d);
		ft_menu(d);
		ft_get_sgt(d);
		ft_get_seg(d);
		pthread_mutex_unlock(&d->mutex_display);
	}
	return (NULL);
}
