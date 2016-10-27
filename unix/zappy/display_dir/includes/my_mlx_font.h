/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_font.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 06:29:55 by mblet             #+#    #+#             */
/*   Updated: 2014/06/22 12:34:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_FONT_H
# define MY_MLX_FONT_H

typedef struct		s_tmp_img
{
	void			*img;
	unsigned char	*addr;
	int				bpp;
	int				size;
	int				endian;
	int				x;
	int				y;
}					t_tmp_img;

typedef struct		s_font_img
{
	int				w;
	int				w_d;
	int				h;
	void			*img;
	unsigned char	*addr;
	int				bpp;
	int				size;
	int				endian;
}					t_font_img;

typedef struct		s_font
{
	int				x;
	int				x_d;
	int				y;
	int				y_d;
	int				color;
	char			*string;
	unsigned char	*addr;
	int				bpp;
	int				size;
	t_font_img		*font_img;
}					t_font;

t_font_img			*ft_load_file_font(void *mlx, char *file_path);
void				ft_mlx_font(t_font_img *font_img, int x, int y, ...);

#endif
