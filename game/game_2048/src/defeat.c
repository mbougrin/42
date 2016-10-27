/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defeat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:35:20 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/01 20:07:13 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	st_test(int val1, int val2)
{
	if ((val1 == val2) || (val1 && !val2))
		return (1);
	return (0);
}

int			defeat(t_grid **grid)
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i > 0 && st_test(grid[i][j].val, grid[i - 1][j].val))
				ret = (ret & 1) ? ret : ret + 1;
			else if (i < 3 && st_test(grid[i][j].val, grid[i + 1][j].val))
				ret = (ret & 2) ? ret : ret + 2;
			else if (j > 0 && st_test(grid[i][j].val, grid[i][j - 1].val))
				ret = (ret & 4) ? ret : ret + 4;
			else if (j < 3 && st_test(grid[i][j].val, grid[i][j + 1].val))
				ret = (ret & 8) ? ret : ret + 8;
			j++;
		}
		i++;
	}
	return (ret);
}
