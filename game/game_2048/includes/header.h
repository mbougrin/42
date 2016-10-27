/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:58:04 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/01 18:20:31 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <curses.h>

typedef struct		s_grid
{
	WINDOW			*win;
	int				color;
	int				x;
	int				y;
	short			val;
	char			mask;
}					t_grid;

t_grid				**initgrid(void);
void				freegrid(t_grid **grid);
int					defeat(t_grid **grid);

void				add_number(t_grid **grid, int move);

void				moveleft(t_grid **grid);
void				moverigth(t_grid **grid);
void				movedown(t_grid **grid);
void				moveup(t_grid **grid);

int					score(t_grid **grid);
int					victory(t_grid **grid, int v, int goal);

#endif
