/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:08 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/21 12:28:56 by mbougrin         ###   ########.fr       */
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
	_log = log;
	ifstream file(conf);
	char	data[256];

	if (!file.is_open())
		exit(-1);

	while (file.getline(data, 256))
	{
		_log.writelog("LOG", data);
		std::cout << data << std::endl;
	}
	file.close();
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
