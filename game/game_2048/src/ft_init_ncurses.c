/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ncurses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 06:33:21 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/01 06:45:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_malloc_stc(t_stc **stc, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		stc[i] = (t_stc *)malloc(sizeof(t_stc));
		i++;
	}
}

void			ft_init_ncurses(void)
{
	initscr();
	curs_set(FALSE);
	start_color();
	noecho();
	raw();
	keypad(stdscr, TRUE);
}

void			ft_refresh(t_stc **stc, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		wrefresh(stc[i]->win);
		i++;
	}
}

void			ft_create_win_next(t_stc **stc, int nb, int *i)
{
	while (i[0] < nb)
	{
		stc[i[0]]->win = newwin(i[5], i[6], i[3], i[4]);
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

void			ft_create_win(t_stc **stc, int nb)
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
	ft_create_win_next(stc, nb, i);
}
