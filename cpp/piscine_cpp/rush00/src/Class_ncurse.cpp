/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_ncurse.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:49:43 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/12 19:00:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_ncurse.hpp>

Class_ncurse::Class_ncurse(void)
{
	initscr();
	curs_set(FALSE);
	start_color();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_CYAN, COLOR_BLACK);
	init_pair(9, COLOR_MAGENTA, COLOR_BLACK);
	return ;
}

Class_ncurse::Class_ncurse(Class_ncurse const &src) { if (this != &src) { *this = src ; } return ; }

void		Class_ncurse::ft_delwin(void) { delwin(this->_win); }

Class_ncurse::~Class_ncurse(void)
{
	endwin();
	return ;
}

void				Class_ncurse::game_over(void)
{
	if (LINES < 20 || COLS < 40)
	{
		endwin();
		exit(0);
	}
	bkgd(COLOR_PAIR(0));
	this->_win = newwin(20, 40, (LINES - 20) / 2, (COLS - 40) / 2);

	wbkgd(this->_win, COLOR_PAIR(1));

	this->_new_game = newwin(1, 20, ((LINES - 20) / 2) + 4, ((COLS - 40) / 2) + 10);
	mvwprintw(this->_win, 9, 15, "%s", "game over");
	wrefresh(stdscr);
	wrefresh(this->_win);
	sleep(2);
	delwin(this->_win);
}

int					Class_ncurse::ft_print_menu(void)
{
	if (LINES < 20 || COLS < 40)
	{
		endwin();
		exit(0);
	}
	bkgd(COLOR_PAIR(0));
	this->_win = newwin(20, 40, (LINES - 20) / 2, (COLS - 40) / 2);

	wbkgd(this->_win, COLOR_PAIR(1));

	this->_new_game = newwin(1, 20, ((LINES - 20) / 2) + 4, ((COLS - 40) / 2) + 10);
	this->_high_score = newwin(1, 20, ((LINES - 20) / 2) + 9, ((COLS - 40) / 2) + 10);
	this->_exit = newwin(1, 20, ((LINES - 20) / 2) + 14, ((COLS - 40) / 2) + 10);

	wbkgd(this->_new_game, COLOR_PAIR(4));
	wbkgd(this->_high_score, COLOR_PAIR(1));
	wbkgd(this->_exit, COLOR_PAIR(1));

	int key = 0;
	int	nb = 0;
	while (key != 27)
	{
		key = 0;
		mvwprintw(this->_new_game, 0, 6, "%s", "new game");
		mvwprintw(this->_high_score, 0, 5, "%s", "high score");
		mvwprintw(this->_exit, 0, 8, "%s", "exit");
		wrefresh(stdscr);
		wrefresh(this->_win);
		wrefresh(this->_new_game);
		wrefresh(this->_high_score);
		wrefresh(this->_exit);
		key = getch();
		if (259 == key)
		{
			nb--;
			if (nb < 0)
				nb = 2;
			else if (nb > 2)
				nb = 0;
			if (nb == 0)
			{
				wbkgd(this->_new_game, COLOR_PAIR(4));
				wbkgd(this->_high_score, COLOR_PAIR(1));
				wbkgd(this->_exit, COLOR_PAIR(1));
			}
			else if (nb == 1)
			{
				wbkgd(this->_new_game, COLOR_PAIR(1));
				wbkgd(this->_high_score, COLOR_PAIR(4));
				wbkgd(this->_exit, COLOR_PAIR(1));
			}
			else if (nb == 2)
			{
				wbkgd(this->_new_game, COLOR_PAIR(1));
				wbkgd(this->_high_score, COLOR_PAIR(1));
				wbkgd(this->_exit, COLOR_PAIR(4));
			}
		}
		else if (258 == key)
		{
			nb++;
			if (nb < 0)
				nb = 2;
			else if (nb > 2)
				nb = 0;
			if (nb == 0)
			{
				wbkgd(this->_new_game, COLOR_PAIR(4));
				wbkgd(this->_high_score, COLOR_PAIR(1));
				wbkgd(this->_exit, COLOR_PAIR(1));
			}
			else if (nb == 1)
			{
				wbkgd(this->_new_game, COLOR_PAIR(1));
				wbkgd(this->_high_score, COLOR_PAIR(4));
				wbkgd(this->_exit, COLOR_PAIR(1));
			}
			else if (nb == 2)
			{
				wbkgd(this->_new_game, COLOR_PAIR(1));
				wbkgd(this->_high_score, COLOR_PAIR(1));
				wbkgd(this->_exit, COLOR_PAIR(4));
			}
		}
		else if (key == 10)
		{
			if (nb == 2)
				break ;
			if (nb == 0)
			{
				clear();
				delwin(this->_win);
				delwin(this->_new_game);
				delwin(this->_high_score);
				delwin(this->_exit);
				this->_time = time(NULL);
				return (1);
			}
			else if (nb == 1)
			{
				int		fd;
				if ((fd = open("high_score.txt", O_RDONLY)) != -1)
				{
					clear();
					char	buff[1024];
					int ret = read(fd, buff, 1024);
					wbkgd(this->_high_score, COLOR_PAIR(1));
					mvwprintw(this->_new_game, 0, 0, "%s", "                    ");
					mvwprintw(this->_high_score, 0, 0, "%s", "                    ");
					mvwprintw(this->_exit, 0, 0, "%s", "                    ");
					wrefresh(this->_new_game);
					wrefresh(this->_high_score);
					wrefresh(this->_exit);

					mvwprintw(this->_new_game, 0, 8, "%s", buff);
					int		i;

					i = 0;
					while (buff[i] != '\0')
					{
						if (buff[i] == '\n')
							break ;
						i++;
					}
					i++;
					if (ret > i)
						mvwprintw(this->_high_score, 0, 8, "%s", &buff[i]);
					else
						mvwprintw(this->_high_score, 0, 8, "%s", "0");
					while (buff[i] != '\0')
					{
						if (buff[i] == '\n')
							break ;
						i++;
					}
					if (buff[i] != '\0')
						i++;
					if (buff[i] != '\0')
						mvwprintw(this->_exit, 0, 8, "%s", &buff[i]);
					else
						mvwprintw(this->_exit, 0, 8, "%s", "0");

					wrefresh(this->_new_game);
					wrefresh(this->_high_score);
					wrefresh(this->_exit);
					sleep(3);
					wclear(this->_win);
					wclear(this->_new_game);
					wclear(this->_high_score);
					wclear(this->_exit);
					wbkgd(this->_high_score, COLOR_PAIR(4));
					close(fd);
				}
			}
		}
	}
	delwin(this->_win);
	delwin(this->_new_game);
	delwin(this->_high_score);
	delwin(this->_exit);
	return (0);
}

void				Class_ncurse::save(int nb)
{
	int		fd;

	if ((fd = open("high_score.txt", O_RDWR | O_CREAT | O_APPEND, 0644)) != -1)
	{
		std::string s;
		std::stringstream out;
		out << nb;
		s = out.str();
		write(fd, s.c_str(), strlen(s.c_str()));
		write(fd, "\n", 1);
		close(fd);
	}
}

void				Class_ncurse::ft_print_score(Player &src)
{
	time_t times = time(NULL);
	this->_win = newwin(1, COLS, 0, 0);
	wbkgd(this->_win, COLOR_PAIR(1));
	mvwprintw(this->_win, 0, 0, "%s", "life:");
	mvwprintw(this->_win, 0, 6, "%i", src.getLife());
	mvwprintw(this->_win, 0, 12, "%s", "score:");
	mvwprintw(this->_win, 0, 18, "%i", src.getScore());
	mvwprintw(this->_win, 0, 22, "%s", "time:");
	mvwprintw(this->_win, 0, 30, "%i", (times - this->_time));
	wrefresh(this->_win);
}

Class_ncurse&		Class_ncurse::operator=(Class_ncurse const &src) { if (this != &src) { } return *this; }
