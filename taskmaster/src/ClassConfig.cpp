/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:08 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/23 13:39:09 by mbougrin         ###   ########.fr       */
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
}

void			ClassConfig::parse(void)
{
	openfile();
	list<string>::iterator i;
	for (i = _lstconf.begin(); i != _lstconf.end(); ++i)
	{
		if (strchr(i->c_str(), '[') != NULL \
				&& strchr(i->c_str(), ']') != NULL)
		{
			string *line = new string(i->c_str());
			line->erase(0, 1);
			int	len = line->length();
			line->erase(len - 1, 1);
			int	find = line->find(":");
			string *name = new string(line->substr(find + 1, len));
			string *action = new string(line->substr(0, find));
			std::cout << *name << " " << *action << std::endl;

			ClassProgram _new = ClassProgram();
			while (1)
			{
				i++;
				if (i == _lstconf.end())
					break ;
				if (strchr(i->c_str(), '[') != NULL \
					&& strchr(i->c_str(), ']') != NULL)
					break ;
				int len = i->length();
				int find = i->find("=");
				string *name = new string(i->substr(0, find));
				string *info = new string(i->substr(find + 1, len));

				std::cout << *name << " " << *info << std::endl;
				delete name;
				delete info;
			}
			_lstprog.push_back(_new);
			delete action;
			delete name;
			if (i == _lstconf.end())
				break ;
		}
		std::cout << *i << std::endl;
	}
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
