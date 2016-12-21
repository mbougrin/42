/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:20 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/19 14:21:33 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCONFIG_HPP
# define CLASSCONFIG_HPP

# include <iostream>
# include <ClassProgram.hpp>
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

		void		parse(char *conf);
	private:
		std::list<ClassProgram>		lst;
};

#endif
