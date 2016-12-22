/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:08 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/22 12:19:39 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClassConfig.hpp>

ClassConfig::ClassConfig(void)
{
	return ;
}

ClassConfig::ClassConfig(ClassConfig const &src)
{
	if (this != &src)
	{

	}
	return ;
}

void			ClassConfig::parse(char *conf, Tintin_reporter log)
{
	ifstream 		file(conf);
	char			data[256];

	_log = log;
	if (!file.is_open())
		exit(-1);

	while (file.getline(data, 256))
	{
		if (data[0] != ';' && data[0] != ' ')
			_ss << data << "\n";
		bzero(data, 256);
	}
	file.close();
	std::cout << _ss.str() << std::endl;
}

ClassConfig		&ClassConfig::operator=(ClassConfig const &src)
{
	if (this != &src)
	{

	}
	return (*this);
}

ClassConfig::~ClassConfig(void)
{
	return ;
}
