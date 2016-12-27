/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:20 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/27 13:02:12 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCONFIG_HPP
# define CLASSCONFIG_HPP

# include <iostream>
# include <Tintin_reporter.hpp>
# include <list>
# include <string>
# include <string.h>
# include <fstream>
# include <sstream>
# include <stdio.h>
# include <ClassProgram.hpp>
# include <sched.h>
# include <thread>

class				ClassConfig
{
	public:
		ClassConfig();
		ClassConfig(ClassConfig const &src);
		ClassConfig &operator=(ClassConfig const &src);
		~ClassConfig();

		void		init(char *conf, Tintin_reporter log);
		void		parse(void);
		void		openfile(void);
		void		printconfig(void);
		void		run(void);
		static int	countspace(const char *str);
		static void	launchbinary(list<ClassProgram*>::iterator i);
	private:
		char						*_conf;
		std::list<string>			_lstconf;
		std::list<ClassProgram*>	_lstprog;
		Tintin_reporter				_log;
};

#endif
