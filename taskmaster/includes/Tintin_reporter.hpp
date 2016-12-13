/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tintin_reporter.hpp                                :+:      :+:    :+:   */
/*                                                 	  +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:10:13 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/09 14:56:06 by mbougrin         ###   ########.fr       */
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
 
# define LOGPATH  "/var/log/taskmaster/"
# define LOCKPATH "/var/lock/"

# define NAME "taskmaster"

# define LOCKNAME "taskmaster.lock"
# define FILENAME "taskmaster.log"

using 				namespace std; 

class				Tintin_reporter
{

	public:
		Tintin_reporter();
		Tintin_reporter(Tintin_reporter const &src);
		Tintin_reporter &operator=(Tintin_reporter const &src);
		~Tintin_reporter();

		void			writelog(string info, string str);
		static void		sighandler(int nb);
	private:
		int				_fd;
};

#endif
