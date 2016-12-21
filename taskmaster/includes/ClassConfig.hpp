/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:20 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/21 12:28:06 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCONFIG_HPP
# define CLASSCONFIG_HPP

# include <iostream>
# include <Tintin_reporter.hpp>
# include <list>
# include <string>
# include <fstream>

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
