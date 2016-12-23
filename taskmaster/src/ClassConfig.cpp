/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:08 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/23 11:17:38 by mbougrin         ###   ########.fr       */
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
			_lstconf.push_back(string(data));
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
	{
		if (strchr(i->c_str(), '[') != NULL \
				&& strchr(i->c_str(), ']') != NULL)
		{
			string *name = new string(i->c_str());
			name->erase(0, 1);
			name->erase(name->length() - 1, 1);
			std::cout << name->at(name->find(":")) << std::endl;
//			for (i = _lstconf.begin(); i != _lstconf.end(); ++i)
//			{
//				
//			}
			delete name;
		}
		std::cout << *i << std::endl;
	}
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
