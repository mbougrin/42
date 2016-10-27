/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:48:07 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:49:13 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_create_win(t_ncs **ncs, int nb)
{
	int		i[7];

	i[1] = SIZE_MAP;
	i[2] = SIZE_MAP;
	i[5] = LINES / SIZE_MAP;
	i[6] = COLS / SIZE_MAP;
	i[3] = 0;
	i[4] = 0;
	i[0] = 0;
	while (i[0] < nb)
	{
		ncs[i[0]]->win = newwin(i[5], i[6], i[3], i[4]);
		ncs[i[0]]->color = 3;
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

void			ft_init_background(t_ncs **ncs, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		wbkgd(ncs[i]->win, COLOR_PAIR(ncs[i]->color));
		i++;
	}
}

void			ft_malloc_ncs(t_ncs **ncs, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ncs[i] = (t_ncs *)malloc(sizeof(t_ncs));
		i++;
	}
}

void			ft_print_menu(t_stc **stc)
{
	WINDOW		*win;

	init_pair(1, 18, 18);
	init_pair(2, 18, 7);
	init_pair(3, 15, 250);
	init_pair(4, 1, 1);
	init_pair(5, 5, 6);
	init_pair(6, COLOR_BLACK, COLOR_BLACK);
	win = newwin(20, 40, (LINES - 20) / 2, (COLS - 40) / 2);
	bkgd(COLOR_PAIR(1));
	wbkgd(win, COLOR_PAIR(2));
	mvwprintw(win, 9, 10, "%s", "waiting start game");
	wrefresh(stdscr);
	wrefresh(win);
	while ((*stc)->shm[0] != '2')
	{
	}
	clear();
	wclear(win);
	wrefresh(win);
	delwin(win);
	bkgd(COLOR_PAIR(6));
	wrefresh(stdscr);
}

void			ft_init_ncurses(void)
{
	initscr();
	curs_set(FALSE);
	start_color();
	noecho();
	raw();
}
