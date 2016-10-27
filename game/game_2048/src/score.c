/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:48:07 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/01 17:50:47 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		score(t_grid **grid)
{
	int		ret;
	int		i;
	int		j;

	ret = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j].mask == 1)
				ret += grid[i][j].val;
			j++;
		}
		i++;
	}
	return (ret);
}
