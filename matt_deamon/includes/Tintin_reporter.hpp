/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tintin_reporter.hpp                                :+:      :+:    :+:   */
/*                                                 	  +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:10:13 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/30 13:22:50 by mbougrin         ###   ########.fr       */
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
# include <stdio.h>

//# define LOGPATH  "/var/log/matt_daemon/"
# define LOGPATH "log/"
//# define LOCKPATH "/var/lock/"
# define LOCKPATH "lock/"
# define NAME "Matt_deamon"
# define LOCKNAME "matt_daemon.lock"

using namespace std; 

class				Tintin_reporter
{

	public:
		Tintin_reporter();
		Tintin_reporter(Tintin_reporter const &src);
		Tintin_reporter &operator=(Tintin_reporter const &src);
		~Tintin_reporter();

		void		writelog(string filename, string info, string str);
};

#endif
