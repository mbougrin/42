/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:01:14 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/01 20:31:18 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_color(t_stc **stc, int nb)
{
	int		i;
	int		color;

	i = 0;
	color = 2;
	while (i < nb)
	{
		stc[i]->color = color;
		color++;
		i++;
	}
}

void			ft_check_key(t_grid **grid, int key)
{
	if (key == DOWN)
		movedown(grid);
	if (key == UP)
		moveup(grid);
	if (key == LEFT)
		moveleft(grid);
	if (key == RIGTH)
		moverigth(grid);
	if (key == DOWN || key == UP || key == LEFT || key == RIGTH)
		add_number(grid, key);
}

static int		st_isallow(int key, int rule)
{
	if (!(rule & 1) && (key == UP))
		return (0);
	if (!(rule & 2) && (key == DOWN))
		return (0);
	if (!(rule & 4) && (key == RIGTH))
		return (0);
	if (!(rule & 8) && (key == LEFT))
		return (0);
	return (1);
}

int				ft_first_loop(t_grid **grid, t_stc **stc, int nb)
{
	int		key;
	int		allow;
	int		score;
	int		goal;

	score = 0;
	key = 0;
	goal = 1;
	while ((allow = defeat(grid)) \
			&& (key = getch()) != ESCAPE)
	{
		ft_resize(stc, nb);
		if (st_isallow(key, allow))
			score += ft_loop(grid, stc, key, nb);
		goal = victory(grid, WIN_VALUE, goal);
		if (goal == 0)
			break ;
	}
	return (score);
}
