/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmesas <kmesas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 09:41:36 by mbougrin          #+#    #+#             */
/*   Updated: 2015/05/03 21:51:10 by kmesas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <GLFW/glfw3.h>
# include <libft.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

int					g_fd;

typedef struct		s_map
{
	float			block;
	float			hl;
	float			hr;
	float			right;
	float			left;
	float			co[3];
}					t_map;

typedef struct		s_stc
{
	float			left;
	float			right;
	int				start;
}					t_stc;

typedef struct		s_circle
{
	int				move_h;
	int				move_v;
	float			pos;
	float			pos_v;
}					t_circle;

typedef struct		s_vars_d
{
	double			lat0;
	double			z0;
	double			zr0;
	double			lat1;
	double			z1;
	double			zr1;
	double			lng;
	double			x;
	double			y;
}					t_vars_d;

typedef struct		s_vars_i
{
	int				lats;
	int				longs;
	int				i;
	int				j;
}					t_vars_i;

void				gener_block(t_stc *stc, t_circle *crl);
t_map				**ft_init_map(t_map **map);
void				key_callback(GLFWwindow *window, int key, int scancode,
						int action, int mods);
void				ft_print_rect(t_map **map);
void				ft_check_col(t_map **map, t_circle *crl);
t_stc				*ft_stc(t_stc *stc);
t_circle			*ft_crl(t_circle *circle);

#endif
