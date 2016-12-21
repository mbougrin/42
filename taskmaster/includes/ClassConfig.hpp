/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:20 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/21 16:57:29 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCONFIG_HPP
# define CLASSCONFIG_HPP

# include <iostream>
# include <Tintin_reporter.hpp>
# include <list>
# include <string>
# include <fstream>
# include <sstream>

class				ClassConfig
{
	public:
		ClassConfig();
		ClassConfig(ClassConfig const &src);
		ClassConfig &operator=(ClassConfig const &src);
		~ClassConfig();

		void		parse(char *conf, Tintin_reporter log);
	private:
	//	std::list<ClassProgram>		lst;
		Tintin_reporter				_log;
};

#endif
