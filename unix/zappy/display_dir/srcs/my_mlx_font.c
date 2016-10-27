/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_font.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 06:26:06 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 03:56:32 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <mlx.h>
#include <stdlib.h>

#include "my_mlx_font.h"

t_font_img		*ft_load_file_font(void *mlx, char *file_path)
{
	t_font_img	*f;

	if ((f = malloc(sizeof(t_font_img))) == NULL)
		return (NULL);
	f->img = mlx_xpm_file_to_image(mlx, file_path, &f->w, &f->h);
	f->addr = (unsigned char *)mlx_get_data_addr(f->img,
			&f->bpp, &f->size, &f->endian);
	f->bpp = f->bpp >> 3;
	f->w_d = f->w / 94;
	return (f);
}

static void		ft_mlx_font_check_pixel(int x, int y, t_font *f, t_tmp_img *t)
{
	unsigned char	*i;
	void			*tmp;
	int				color;
	int				color_f;

	tmp = f->font_img->addr + x * f->font_img->size + y * f->font_img->bpp;
	color = *(int *)tmp;
	if (color != 0x000000)
	{
		i = f->addr + (y + t->y) * (f->bpp >> 3) + (x + t->x) * f->size;
		color_f = f->color;
		*i++ = (color & color_f);
		*i++ = (color & color_f) >> 8;
		*i = (color & color_f) >> 16;
	}
}

static void		ft_put_char(t_font *f, int d, t_tmp_img *t)
{
	int		i;
	int		j;

	i = (f->string[d] - 33) * f->font_img->w_d;
	if (i < 0)
		return ;
	t->x = f->x;
	t->y = f->y - i + d * f->font_img->w_d;
	while (i < (f->string[d] - 33) * f->font_img->w_d + f->font_img->w_d)
	{
		j = 0;
		while (j < f->font_img->h)
		{
			ft_mlx_font_check_pixel(j, i, f, t);
			j++;
		}
		i++;
	}
}

static void		ft_put_string(t_font *f)
{
	int			i;
	t_tmp_img	*tmp;

	if ((tmp = malloc(sizeof(t_tmp_img))) == NULL)
		return ;
	i = 0;
	while (f->string && f->string[i])
	{
		if (f->string[i] == '\n')
			f->x += f->font_img->h;
		if (f->string[i] == '\n')
			f->y = f->y_d - (i + 1) * f->font_img->w_d;
		ft_put_char(f, i, tmp);
		i++;
	}
	free(tmp);
}

void			ft_mlx_font(t_font_img *font_img, int x, int y, ...)
{
	va_list		args;
	t_font		*f;

	if ((f = malloc(sizeof(t_font))) == NULL)
		return ;
	f->font_img = font_img;
	f->x = y;
	f->y = x;
	f->x_d = y;
	f->y_d = x;
	va_start(args, y);
	f->color = (int)va_arg(args, int);
	f->string = (char *)va_arg(args, char *);
	f->addr = (unsigned char *)va_arg(args, char *);
	f->bpp = (int)va_arg(args, int);
	f->size = (int)va_arg(args, int);
	va_end(args);
	ft_put_string(f);
	free(f);
}
