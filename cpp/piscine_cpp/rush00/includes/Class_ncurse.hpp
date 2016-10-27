/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_ncurse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:49:43 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/12 17:55:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_NCURSE_HPP
# define CLASS_NCURSE_HPP

# include <curses.h>
# include <iostream>
# include <unistd.h>
//# include <Class_player.hpp>
# include "../includes/Player.hpp"
# include <sys/stat.h> 
# include <fcntl.h>
# include <sstream>
# include <cstdlib>
# include <string.h>

class		Class_ncurse
{
	public:
		Class_ncurse(void);
		Class_ncurse(Class_ncurse const &src);
		virtual ~Class_ncurse(void);

		int						ft_print_menu(void);
		void					ft_print_score(Player &src);
		void					ft_delwin(void);
		void					game_over(void);
		void					save(int nb);

		Class_ncurse&			operator=(Class_ncurse const &src);
	private:
		WINDOW			*_win;
		WINDOW			*_new_game;
		WINDOW			*_high_score;
		WINDOW			*_exit;
		time_t			_time;
};

#endif
