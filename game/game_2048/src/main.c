/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:40:52 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/01 20:29:22 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void		ft_free(t_stc **stc, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		free(stc[i]);
		i++;
	}
	free(stc);
}

static int		ft_check_number(void)
{
	int		nb;

	nb = WIN_VALUE;
	while (1)
	{
		nb = nb / 2;
		if (nb == 1)
			return (0);
		if (nb == 3)
		{
			ft_putendl_fd("Not good number WIN_VALUE", 2);
			return (-1);
		}
	}
}

static void		st_printscore(int n)
{
	clear();
	write(1, "\nScore :", 9);
	ft_putnbr(n);
	write(1, "\n", 1);
}

int				main(int ac, char **av)
{
	t_grid	**grid;
	t_stc	**stc;
	int		nb;

	(void)ac;
	(void)av;
	if (ft_check_number() == -1)
		return (0);
	nb = 16;
	srand(time(NULL));
	grid = initgrid();
	stc = (t_stc **)malloc(sizeof(t_stc *) * nb);
	ft_init_ncurse(stc, nb);
	ft_loop(grid, stc, 0, nb);
	st_printscore(ft_first_loop(grid, stc, nb));
	ft_free(stc, nb);
	return (0);
}
