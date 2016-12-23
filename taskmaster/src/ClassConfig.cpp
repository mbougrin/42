/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:08 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/23 10:08:30 by mbougrin         ###   ########.fr       */
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

void			ClassConfig::openfile(void)
{
	ifstream 		file(_conf);
	char			data[256];
	stringstream 	ss;

	if (!file.is_open())
	{
		std::cout << "open error file config" << std::endl;
		_log.writelog("ERROR", "open error file config");
		exit(-1);
	}
	while (file.getline(data, 256))
	{
		if (data[0] != ';' && data[0] != ' ' && data[0] != '\0')
		{
			ss = data;
			_lstconf.push_back(ss.str());
			std::cout << ss.str() << std::endl;
		}
		bzero(data, 256);
	}
	file.close();
}

void			ClassConfig::init(char *conf, Tintin_reporter log)
{
	_conf = conf;
	_log = log;
	parse();
	list<string>::iterator i;
	for (i = _lstconf.begin(); i != _lstconf.end(); ++i)
		std::cout << *i << std::endl;
}

void			ClassConfig::parse(void)
{
	openfile();
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
