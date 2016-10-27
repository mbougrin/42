/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:24:59 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/01 02:57:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "header.h"

static void		st_setnull(t_grid **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			grid[i][j].val = 0;
			grid[i][j].mask = 0;
			j++;
		}
		i++;
	}
}

t_grid			**initgrid(void)
{
	t_grid	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_grid*) * 4);
	while ((new[i] = malloc(sizeof(t_grid) * 4)) && i < 4)
		i++;
	if (i < 4)
		return (NULL);
	st_setnull(new);
	new[rand() % 4][rand() % 2].val = (rand() % 5) ? 2 : 4;
	new[rand() % 4][rand() % 2 + 2].val = (rand() % 15) ? 2 : 4;
	return (new);
}
