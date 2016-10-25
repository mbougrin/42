/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printNcurse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:11:34 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/24 10:04:33 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

//print date into ncurse

void		printDate(void)
{
	t_stc	*stc = singleton(NULL);

	mvwprintw(stc->date, 0, 0, "%s", "Date: ");
	mvwprintw(stc->date, 0, 15, "%s", stc->strDate);
}

static void	printTimeFormat(WINDOW *win, int hour, int min, int sec)
{
	if (hour < 10)
	{
		mvwprintw(win, 0, 15, "%i", 0);
		mvwprintw(win, 0, 16, "%i", hour);
	}
	else if (hour > 99)
		mvwprintw(win, 0, 14, "%i", hour);
	else
		mvwprintw(win, 0, 15, "%i", hour);
	mvwprintw(win, 0, 17, "%c", ':');
	if (min < 10)
	{
		mvwprintw(win, 0, 18, "%i", 0);
		mvwprintw(win, 0, 19, "%i", min);
	}
	else
		mvwprintw(win, 0, 18, "%i", min);
	mvwprintw(win, 0, 20, "%c", ' ');
	if (sec < 10)
	{
		mvwprintw(win, 0, 21, "%i", 0);
		mvwprintw(win, 0, 22, "%i", sec);
	}
	else
		mvwprintw(win, 0, 21, "%i", sec);

}

//print breakTime into ncurse

void		printBreakTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		time;
	int		hour, min, sec;

	if (stc->notWorkBool == false)
		time = stc->notWorkTime + stc->breakTime;
	if (stc->notWorkBool == true)
		time = (stc->breakTime + stc->notWorkTime) + ((stc->clock / CLOCKS_PER_SEC) \
			   - (stc->clockBreak / CLOCKS_PER_SEC));
	if (MIN_TIME_BREAK <= time)
		wbkgd(stc->notWork, COLOR_PAIR(3));
	if (MAX_TIME_BREAK <= time)
		wbkgd(stc->notWork, COLOR_PAIR(2));
	hour = time / 3600;
	if (hour > 0)
		time -= hour * 3600;
	min = time / 60;
	if (min > 0)
		time -= min * 60;
	sec = time;
	mvwprintw(stc->notWork, 0, 0, "%s", "TimeBreak: ");
	printTimeFormat(stc->notWork, hour, min, sec);
}

//print workTime into ncurse

void		printWorkTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		time = stc->workTime + (stc->clock / CLOCKS_PER_SEC);
	int		hour, min, sec;

	if (MIN_TIME_WORK <= time)
		wbkgd(stc->work, COLOR_PAIR(3));
	if (MAX_TIME_WORK <= time)
		wbkgd(stc->work, COLOR_PAIR(4));
	hour = time / 3600;
	if (hour > 0)
		time -= hour * 3600;
	min = time / 60;
	if (min > 0)
		time -= min * 60;
	sec = time;
	mvwprintw(stc->work, 0, 0, "%s", "TimeWork: ");
	printTimeFormat(stc->work, hour, min, sec);
}

//print Actual Time into ncurse

void		printTime(void)
{
	t_stc	*stc = singleton(NULL);

	stc->stcTime = localtime(&stc->currentTime);
	mvwprintw(stc->time, 0, 0, "%s", "Time: ");
	printTimeFormat(stc->time, stc->stcTime->tm_hour, stc->stcTime->tm_min, \
			stc->stcTime->tm_sec);
}

static int	weekTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		count;
	t_lst	*tmp;
	int		day = stc->day;

	if (day == 0)
		day = 6;
	tmp = stc->lst;
	count = 0;
	if (stc->day == 1)
		return (0);
	while (tmp)
	{
		if (day == 1)
			break ;
		if ((stc->dateNumber - 6) >= ft_atoi(tmp->splitInfo[1]))
			break ;
		if (stc->month == tmp->month \
				&& ft_strcmp(stc->year, tmp->splitInfo[3]) == 0)
		{
			if (ft_strncmp(tmp->name, stc->strDate, ft_strlen(stc->strDate)) != 0)
				count += tmp->timeWork;
		}
		else
			break ;
		day--;
		tmp = tmp->next;
	}
	if (day == 1)
		count += tmp->timeWork;
	return (count);
}

//print Week Time

void		printWeekTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		workTime = stc->workTime + (stc->clock / CLOCKS_PER_SEC);
	int		time = weekTime() + workTime;
	int		hour, min, sec;

	if (MIN_WEEK <= time)
		wbkgd(stc->weekTime, COLOR_PAIR(3));
	if (MAX_WEEK <= time)
		wbkgd(stc->weekTime, COLOR_PAIR(4));
	hour = time / 3600;
	if (hour > 0)
		time -= hour * 3600;
	min = time / 60;
	if (min > 0)
		time -= min * 60;
	sec = time;
	mvwprintw(stc->weekTime, 0, 0, "%s", "WeekTime: ");
	printTimeFormat(stc->weekTime, hour, min, sec);
}

static int	monthTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		count;
	t_lst	*tmp;

	tmp = stc->lst;
	count = 0;
	while (tmp)
	{
		if (stc->month == tmp->month \
				&& ft_strcmp(stc->year, tmp->splitInfo[3]) == 0)
		{
			if (ft_strcmp(tmp->name, stc->strDate) != 0)
				count += tmp->timeWork;
		}
		else
			break ;
		tmp = tmp->next;
	}
	return (count);
}

//print month time

void		printMonthTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		workTime = stc->workTime + (stc->clock / CLOCKS_PER_SEC);
	int		time = monthTime() + workTime;
	int		hour, min, sec;

	if (MIN_MONTH <= time)
		wbkgd(stc->monthTime, COLOR_PAIR(3));
	if (MAX_MONTH <= time)
		wbkgd(stc->monthTime, COLOR_PAIR(4));
	hour = time / 3600;
	if (hour > 0)
		time -= hour * 3600;
	min = time / 60;
	if (min > 0)
		time -= min * 60;
	sec = time;
	mvwprintw(stc->monthTime, 0, 0, "%s", "MonthTime: ");
	printTimeFormat(stc->monthTime, hour, min, sec);

}

static int	threeMonthTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		count;
	t_lst	*tmp;

	tmp = stc->lst;
	count = 0;
	while (tmp)
	{
		if (stc->month - 3 < tmp->month \
				&& ft_strcmp(stc->year, tmp->splitInfo[3]) == 0)
		{
			if (ft_strcmp(tmp->name, stc->strDate) != 0)
				count += tmp->timeWork;
		}
		else
			break ;
		tmp = tmp->next;
	}
	return (count);
}

//print three month time

void		printThreeMonthTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		workTime = stc->workTime + (stc->clock / CLOCKS_PER_SEC);
	int		time = threeMonthTime() + workTime;
	int		hour, min, sec;

	if (MIN_THREE_MONTH <= time)
		wbkgd(stc->threeMonth, COLOR_PAIR(3));
	if (MAX_THREE_MONTH <= time)
		wbkgd(stc->threeMonth, COLOR_PAIR(4));
	hour = time / 3600;
	if (hour > 0)
		time -= hour * 3600;
	min = time / 60;
	if (min > 0)
		time -= min * 60;
	sec = time;
	mvwprintw(stc->threeMonth, 0, 0, "%s", "ThreeMonth: ");
	printTimeFormat(stc->threeMonth, hour, min, sec);

}

static int	allTime(t_lst *alst)
{
	t_stc	*stc = singleton(NULL);
	int		count;
	t_lst	*tmp;

	tmp = alst;
	count = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, stc->strDate) != 0)
			count += tmp->timeWork;
		tmp = tmp->next;
	}
	return (count);
}

//print all time

void		printAllTime(void)
{
	t_stc	*stc = singleton(NULL);
	int		workTime = stc->workTime + (stc->clock / CLOCKS_PER_SEC);
	int		time = allTime(stc->lst) + workTime;
	int		hour, min, sec;

	hour = time / 3600;
	if (hour > 0)
		time -= hour * 3600;
	min = time / 60;
	if (min > 0)
		time -= min * 60;
	sec = time;
	mvwprintw(stc->all, 0, 0, "%s", "AllTime: ");
	printTimeFormat(stc->all, hour, min, sec);
}

static int	allBreakTime(t_lst *alst)
{
	t_stc	*stc = singleton(NULL);
	int		count;
	t_lst	*tmp;

	tmp = alst;
	count = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, stc->strDate) != 0)
			count += tmp->timeBreak;
		tmp = tmp->next;
	}
	return (count);
}

// pourcentage work break

void		printWorkBreak(void)
{
	t_stc	*stc = singleton(NULL);
	int		workTime = stc->workTime + (stc->clock / CLOCKS_PER_SEC);
	int		time = allTime(stc->lst) + workTime;
	int		breakTime = allBreakTime(stc->lst);
	int	result = (time / 100); 
	int	i = 100;
	int	ret = 0;

	if (stc->notWorkBool == false)
		breakTime += stc->notWorkTime + stc->breakTime;
	if (stc->notWorkBool == true)
		breakTime = (stc->breakTime + stc->notWorkTime) + \
					((stc->clock / CLOCKS_PER_SEC) \
			   		- (stc->clockBreak / CLOCKS_PER_SEC));
	while (1)
	{
		ret = result * i;
		if (ret < breakTime)
			break;
		i--;
	}
	if (i >= MIN_WORKBREAK)
		wbkgd(stc->workBreak, COLOR_PAIR(3));
	if (i >= MAX_WORKBREAK)
		wbkgd(stc->workBreak, COLOR_PAIR(2));
	mvwprintw(stc->workBreak, 0, 0, "%s", "Work/Break: ");
	mvwprintw(stc->workBreak, 0, 15, "%i", i);
	mvwprintw(stc->workBreak, 0, 17, "%c", '%');
}
