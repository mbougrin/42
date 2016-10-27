/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:48:34 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/28 19:50:16 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	st_joincase(t_grid **grid, int i, int j)
{
	int		ret;

	ret = grid[i][j].val;
	grid[i][j].val = 0;
	return (ret);
}

static void	st_mergecol(t_grid **grid, int j)
{
	int		i;
	int		k;

	i = 0;
	while (i < 3)
	{
		k = 1;
		while (i + k < 4)
		{
			if (grid[i][j].val == grid[i + k][j].val \
					|| (!grid[i][j].val && grid[i + k][j].val))
			{
				grid[i][j].val += st_joincase(grid, i + k, j);
				grid[i][j].mask = 1;
			}
			if (grid[i + k][j].val)
				k = 1000;
			k++;
		}
		i++;
	}
}

void		moveup(t_grid **grid)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		st_mergecol(grid, i);
		i++;
	}
}
