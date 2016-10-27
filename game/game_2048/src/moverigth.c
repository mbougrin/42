/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moverigth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:59:59 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/28 18:03:29 by sle-guil         ###   ########.fr       */
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

static void	st_mergecol(t_grid **grid, int i)
{
	int		j;
	int		k;

	j = 3;
	while (j > 0)
	{
		k = 1;
		while (j - k >= 0)
		{
			if (grid[i][j].val == grid[i][j - k].val \
					|| (!grid[i][j].val && grid[i][j - k].val))
			{
				grid[i][j].val += st_joincase(grid, i, j - k);
				grid[i][j].mask = 1;
			}
			if (grid[i][j - k].val)
				k = 1000;
			k++;
		}
		j--;
	}
}

void		moverigth(t_grid **grid)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		st_mergecol(grid, i);
		i++;
	}
}
