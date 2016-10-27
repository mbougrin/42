/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:04:28 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/28 18:01:07 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "header.h"

/*
**	This function can loop into infinite if
**	they are used on an full line. This is ok now, but maybe not later
*/
static void	st_up(t_grid **grid)
{
	int		i;

	i = rand() % 4;
	while (grid[3][i].val)
		i = rand() % 4;
	grid[3][i].val = (rand() % 4) ? 2 : 4;
}

static void	st_down(t_grid **grid)
{
	int		i;

	i = rand() % 4;
	while (grid[0][i].val)
		i = rand() % 4;
	grid[0][i].val = (rand() % 4) ? 2 : 4;
}

static void	st_left(t_grid **grid)
{
	int		i;

	i = rand() % 4;
	while (grid[i][3].val)
		i = rand() % 4;
	grid[i][3].val = (rand() % 4) ? 2 : 4;
}

static void	st_rigth(t_grid **grid)
{
	int		i;

	i = rand() % 4;
	while (grid[i][0].val)
		i = rand() % 4;
	grid[i][0].val = (rand() % 4) ? 2 : 4;
}

void		add_number(t_grid **grid, int move)
{
	if (move == UP)
		st_up(grid);
	else if (move == DOWN)
		st_down(grid);
	else if (move == LEFT)
		st_left(grid);
	else if (move == RIGTH)
		st_rigth(grid);
}
