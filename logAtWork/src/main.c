/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:44:16 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/17 11:41:13 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

//singleton struct stc pattern design

t_stc		*singleton(t_stc *stc)
{
	static t_stc *singleton;

	if (stc != NULL)
		singleton = stc;
	else
		return (singleton);
	return (NULL);
}

static void	print(void)
{
	printDate();
	printTime();
	printWorkTime();
	printBreakTime();
	printWeekTime();
	printMonthTime();
	printThreeMonthTime();
	printAllTime();
	printWorkBreak();
}

void		loop(void)
{
	t_stc 	*stc = singleton(NULL);
	int		saveCount = 60;

	stc->currentTime = time(NULL);
	bkgd(COLOR_PAIR(1));
	wrefresh(stdscr);
	while (stc->key != 27)
	{
		stc->key = getch();
		stc->currentTime = time(NULL);
		stc->clock = clock();
		checkKey();
		print();
		refreshWindow();
		if (stc->clock / CLOCKS_PER_SEC == saveCount)
		{
			save();
			saveCount += AUTO_SAVE;
		}
	}
}

int			main(void)
{
	initNcurse();
	initColor();
	initMainWindow();
	loop();
	deleteMainWindow();
	endwin();
	return (0);
}
