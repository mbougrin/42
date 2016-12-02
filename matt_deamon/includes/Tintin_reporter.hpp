/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tintin_reporter.hpp                                :+:      :+:    :+:   */
/*                                                 	  +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:10:13 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/02 14:40:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TINTIN_REPORTER_HPP
# define TINTIN_REPORTER_HPP

# include <iostream>
# include <ctime>
# include <fstream> 
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/file.h>
 
# define LOGPATH  "/var/log/matt_daemon/"
# define LOCKPATH "/var/lock/"

# define NAME "Matt_deamon"

# define LOCKNAME "matt_daemon.lock"
# define FILENAME "matt_daemon.log"

using namespace std; 

class				Tintin_reporter
{

	public:
		Tintin_reporter();
		Tintin_reporter(Tintin_reporter const &src);
		Tintin_reporter &operator=(Tintin_reporter const &src);
		~Tintin_reporter();

		void		writelog(string info, string str);
		static void 		sighandler(int nb);
	private:
		int				_fd;
};

#endif
