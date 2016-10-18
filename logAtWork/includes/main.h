/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:44:10 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/17 13:56:37 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGATWORK
# define LOGATWORK

//include lib Perso
# include <libft.h>
//include lib ncurse
# include <curses.h>
//include time lib
# include <time.h>
//open read include
# include <sys/stat.h>
# include <fcntl.h>
//include opendir
# include <dirent.h>

# define MIN_TIME_WORK 25200
# define MAX_TIME_WORK 36000

# define MIN_TIME_BREAK 5400 
# define MAX_TIME_BREAK 7200

# define MIN_WEEK 126000
# define MAX_WEEK 252000

# define MIN_MONTH 504000
# define MAX_MONTH 1008000

# define MIN_THREE_MONTH 1512000
# define MAX_THREE_MONTH 3024000

# define MIN_WORKBREAK 18
# define MAX_WORKBREAK 20

# define AUTO_SAVE 60

//initialisation ncurse lib
void			initNcurse(void);
//initialisation color ncurse
void			initColor(void);
//initialisation main window
void			initMainWindow(void);
//main loop ncurse
void			loop(void);
//delete main window and free stc
void			deleteMainWindow(void);
//refresh all window
void			refreshWindow(void);
//print Actual Time into ncurse
void			printTime(void);
//print WorkTime into ncurse
void			printWorkTime(void);
//print breakTime into ncurse
void			printBreakTime(void);
//print date into ncurse
void			printDate(void);
//print week time
void			printWeekTime(void);
//print month time
void			printMonthTime(void);
//print three month time
void			printThreeMonthTime(void);
//print all time
void			printAllTime(void);
//check key ncurse
void			checkKey(void);
//save data into file
void			save(void);
//load data into file today
void			load(void);
//initialisation historique into list
void			initList(void);
// print work break pourcentage
void			printWorkBreak(void);

typedef struct		s_lst
{
	char			**splitInfo;
	char			*name;
	int				month;
	int				day;
	int				timeWork;
	int				timeBreak;
	struct s_lst	*next;
}					t_lst;

//struct window and data
typedef struct	s_stc
{
	bool		notWorkBool;
	int			key;
	int			day;
	int			month;
	int			dateNumber;
	char		*strDate;
	char		*year;
	clock_t		notWorkTime;
	clock_t		breakTime;
	clock_t		workTime;
	clock_t		clock;
	clock_t		clockBreak;
	time_t		currentTime;
	WINDOW		*date;
	WINDOW		*time;
	WINDOW		*work;
	WINDOW		*notWork;
	WINDOW		*weekTime;
	WINDOW		*monthTime;
	WINDOW		*threeMonth;
	WINDOW		*all;
	WINDOW		*workBreak;
	struct tm	*stcTime;
	t_lst		*lst;
}				t_stc;

//singleton struct s_stc
t_stc			*singleton(t_stc *stc);
//create and add info lst
void			addInfoLst(t_lst **alst);
//sort lst per year
void			sortYear(t_lst **alst);
//sort lst per month
void			sortMonth(t_lst **alst);
//sort lst per day
void			sortDay(t_lst **alst);

#endif
