/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:15:42 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/01 20:31:11 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "main.h"
#include "ft_ncurses.h"

static int	st_prompt(void)
{
	char	c;

	clear();
	c = 0;
	ft_putstr("Who let the terminal out ?\n\n");
	while (c != 'y' && c != 'n')
	{
		ft_putstr("\nVictory ! Would you like to continue ?\n");
		ft_putstr("Press y or n\n");
		c = getch();
	}
	if (c == 'y')
		return (1);
	return (0);
}

int			victory(t_grid **grid, int v, int goal)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i][j].val == v * goal)
			{
				if (st_prompt())
					return (goal + 1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (goal);
}
