/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 06:34:35 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/01 17:52:48 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void		ft_resize_next(t_stc **stc, int nb, int *i)
{
	while (i[0] < nb)
	{
		wclear(stc[i[0]]->win);
		mvwin(stc[i[0]]->win, i[3], i[4]);
		wresize(stc[i[0]]->win, i[5], i[6]);
		stc[i[0]]->x = i[5];
		stc[i[0]]->y = i[6];
		stc[i[0]]->val = 0;
		i[4] += i[6];
		i[0]++;
		if (i[0] == i[2])
		{
			i[4] = 0;
			i[3] += i[5];
			i[2] += i[1];
		}
	}
}

void			ft_resize(t_stc **stc, int nb)
{
	int		i[7];

	if (nb == 16)
	{
		i[1] = 4;
		i[2] = 4;
		i[5] = LINES / 4;
		i[6] = COLS / 4;
	}
	else if (nb == 20)
	{
		i[1] = 5;
		i[2] = 5;
		i[5] = LINES / 5;
		i[6] = COLS / 5;
	}
	i[0] = 0;
	i[3] = 0;
	i[4] = 0;
	ft_resize_next(stc, nb, i);
}

void			ft_copy_value(t_grid **grid, t_stc **stc)
{
	int		i;
	int		j;
	int		tmp;

	tmp = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			stc[tmp]->val = grid[i][j].val;
			grid[i][j].mask = 0;
			j++;
			tmp++;
		}
		i++;
	}
}

int				ft_loop(t_grid **grid, t_stc **stc, int key, int nb)
{
	int		ret;

	ret = 0;
	ft_write_space(stc, nb);
	ft_check_key(grid, key);
	ret += score(grid);
	ft_copy_value(grid, stc);
	ft_init_color(stc, nb);
	ft_write_nb(stc, nb);
	ft_refresh(stc, nb);
	return (ret);
}

void			ft_init_ncurse(t_stc **stc, int nb)
{
	ft_init_ncurses();
	init_pair(1, 16, 16);
	bkgd(COLOR_PAIR(1));
	ft_malloc_stc(stc, nb);
	ft_color(stc, nb);
	ft_create_win(stc, nb);
	ft_init_background(stc, nb);
	wrefresh(stdscr);
}
