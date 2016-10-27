/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:24:01 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/01 17:54:08 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NCURSES_H
# define FT_NCURSES_H

# include <header.h>

# define UP 259
# define DOWN 258
# define LEFT 260
# define RIGTH 261
# define ESCAPE 27

typedef struct	s_stc
{
	WINDOW		*win;
	int			color;
	int			x;
	int			y;
	int			val;
}				t_stc;

void			ft_malloc_stc(t_stc **stc, int nb);
void			ft_init_ncurses(void);
void			ft_create_win(t_stc **stc, int nb);
void			ft_init_color(t_stc **stc, int nb);
void			ft_init_background(t_stc **stc, int nb);
void			ft_refresh(t_stc **stc, int nb);
void			ft_write_nb(t_stc **stc, int nb);
void			ft_color(t_stc **stc, int nb);
void			ft_write_space(t_stc **stc, int nb);
void			ft_resize(t_stc **stc, int nb);
void			ft_copy_value(t_grid **grid, t_stc **stc);
int				ft_loop(t_grid **grid, t_stc **stc, int key, int nb);
void			ft_init_ncurse(t_stc **stc, int nb);
void			ft_check_key(t_grid **grid, int key);
int				ft_first_loop(t_grid **grid, t_stc **stc, int nb);

#endif
