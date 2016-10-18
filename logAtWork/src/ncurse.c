/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 13:13:53 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/17 13:58:06 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		refreshWindow(void)
{
	t_stc	*stc = singleton(NULL);

	wrefresh(stc->date);
	wrefresh(stc->time);
	wrefresh(stc->work);
	wrefresh(stc->notWork);
	wrefresh(stc->weekTime);
	wrefresh(stc->monthTime);
	wrefresh(stc->threeMonth);
	wrefresh(stc->all);
	wrefresh(stc->workBreak);
}

//free lst

static void	freeLst(void)
{
	t_stc	*stc = singleton(NULL);
	t_lst	*tmp = stc->lst;
	t_lst	*del = NULL;

	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		ft_strstrdel(del->splitInfo);
		ft_strdel(&del->name);
		free(del);
		del = NULL;
	}
}

//deleting window after close program

void		deleteMainWindow(void)
{
	t_stc	*stc = singleton(NULL);
	freeLst();
	delwin(stc->time);
	delwin(stc->work);
	delwin(stc->notWork);
	delwin(stc->weekTime);
	delwin(stc->monthTime);
	delwin(stc->threeMonth);
	delwin(stc->all);
	delwin(stc->workBreak);
	ft_strdel(&stc->strDate);
	ft_strdel(&stc->year);
	stc->key = 0;
	free(stc);
	stc = NULL;
}

const char *nameDay[] = {"Dimanche", "Lundi", "Mardi", \
								"Mercredi", "Jeudi", "Vendredi", \
								"Samedi"}; 
  
const char *nameMonth[] = {"janvier", "fevrier", "mars" ,"avril", "mai", "juin", \
	                          	"juillet", "aout", "septembre", "octobre", "novembre", \
								"decembre"};

//initialisation date for print date and save name file

static void	initDate(void)
{
	t_stc		*stc = singleton(NULL);
	char		*numberDate;
	char		*numberYear;
	time_t		timestamp;
	struct tm	*t;
	int			len = 0;

	timestamp = time(NULL);
	t = localtime(&timestamp);
	numberDate = ft_itoa(t->tm_mday);
	numberYear = ft_itoa(t->tm_year + 1900);
	stc->year = ft_strdup(numberYear);
	len = ft_strlen(nameDay[t->tm_wday]) + \
		  ft_strlen(nameMonth[t->tm_mon]) + \
		  10;
	stc->strDate = (char *)malloc(sizeof(char) * len);
	ft_strcat(stc->strDate, nameDay[t->tm_wday]);
	ft_strcat(stc->strDate, " ");
	ft_strcat(stc->strDate, numberDate);
	ft_strcat(stc->strDate, " ");
	ft_strcat(stc->strDate, nameMonth[t->tm_mon]);
	ft_strcat(stc->strDate, " ");
	ft_strcat(stc->strDate, numberYear);
	ft_strdel(&numberDate);
	ft_strdel(&numberYear);
	stc->day = t->tm_wday;
	stc->month = t->tm_mon;
	stc->dateNumber = t->tm_mday;
	load();
}

//creation main window ncurse

void		initMainWindow(void)
{
	t_stc	*stc;

	stc = (t_stc *)malloc(sizeof(t_stc));
	stc->date = newwin(1, COLS, 0, 0);
	stc->time = newwin(1, COLS, 1, 0);
	stc->work = newwin(1, COLS, 2, 0);
	stc->notWork = newwin(1, COLS, 3, 0);
	stc->weekTime = newwin(1, COLS, 4, 0);
	stc->monthTime = newwin(1, COLS, 5, 0);
	stc->threeMonth = newwin(1, COLS, 6, 0);
	stc->all = newwin(1, COLS, 7, 0);
	stc->workBreak = newwin(1, COLS, 8, 0);
	stc->strDate = NULL;
	stc->year = NULL;
	stc->day = 0;
	stc->month = 0;
	stc->key = 0;
	stc->dateNumber = 0;
	stc->notWorkTime = 0;
	stc->breakTime = 0;
	stc->clock = 0;
	stc->clockBreak = 0;
	stc->notWorkBool = false;
	stc->stcTime = localtime(&stc->currentTime);
	wbkgd(stc->date, COLOR_PAIR(1));
	wbkgd(stc->time, COLOR_PAIR(1));
	wbkgd(stc->work, COLOR_PAIR(2));
	wbkgd(stc->notWork, COLOR_PAIR(4));
	wbkgd(stc->weekTime, COLOR_PAIR(2));
	wbkgd(stc->monthTime, COLOR_PAIR(2));
	wbkgd(stc->threeMonth, COLOR_PAIR(2));
	wbkgd(stc->all, COLOR_PAIR(1));
	wbkgd(stc->workBreak, COLOR_PAIR(4));
	singleton(stc);
	initList();
	initDate();
}

//initialisation color ncurse lib

void		initColor(void)
{
	init_pair(0, COLOR_WHITE, COLOR_BLUE);
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_RED, COLOR_BLUE);
	init_pair(3, COLOR_YELLOW, COLOR_BLUE);
	init_pair(4, COLOR_GREEN, COLOR_BLUE);
}

// initialise ncurse lib

void		initNcurse(void)
{
	initscr();
	curs_set(false);
	start_color();
	nodelay(stdscr, true);
	noecho();
	raw();
	keypad(stdscr, true);
}
