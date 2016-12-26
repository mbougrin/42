/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:08 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/26 18:50:53 by mbougrin         ###   ########.fr       */
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

void			ClassConfig::printconfig(void)
{
	list<ClassProgram*>::iterator i;
	for (i = _lstprog.begin(); i != _lstprog.end(); ++i)
	{
		std::cout 	<< (*i)->getName() << " name\n"
					<< (*i)->getCmd() << " cmd\n"
					<< (*i)->getProc() << " proc\n"
					<< (*i)->getUmask() << " umask\n"
					<< (*i)->getWorkingdir() << " workdir\n"
					<< (*i)->getAutostart() << " autostart\n"
					<< (*i)->getAutorestart() << " autorestart\n"
					<< (*i)->getStartretry() << " startrety\n"
					<< (*i)->getStarttime() << " starttime\n"
					<< (*i)->getStoptime() << " stoptime\n"
					<< (*i)->getStopsignal() << " stopsignal\n"
					<< (*i)->getStdin() << " stdin\n"
					<< (*i)->getStderr() << " stderr\n";

		const std::list<int>tmpint = (*i)->getExitcode();
		list<int>::const_iterator	k;
		std::cout << "exitcode" << std::endl;
		for (k = tmpint.begin() ; k != tmpint.end() ; ++k)
		{
			std::cout << *k << std::endl;
		}

		const std::list<string>tmp = (*i)->getEnv();
		list<string>::const_iterator	j;
		std::cout << "env" << std::endl;
		for (j = tmp.begin() ; j != tmp.end() ; ++j)
		{
			std::cout << *j << std::endl;
		}
		std::cout << std::endl;
	}
}

extern char		**environ;

void			ClassConfig::run(void)
{
	list<ClassProgram*>::iterator i;
//	for (i = _lstprog.begin(); i != _lstprog.end(); ++i)
//	{
		i = _lstprog.begin();
		pid_t	pid;

		if ((pid = fork()) < 0)
			exit(-1);
		if (pid == 0)
		{
			char **ptr;
		   ptr 	= (char **)malloc(sizeof(char *) * 3);


			ptr[0] = strdup("/bin/ls");
			ptr[1] = strdup("-l");
			
			ptr[2] = NULL;

			execve((*i)->getCmd().c_str(), ptr, environ);
			std::cout << "ok" << std::endl;
			return ;
		}
		else
			wait(NULL);
//	}
}

void			ClassConfig::init(char *conf, Tintin_reporter log)
{
	_conf = conf;
	_log = log;
	parse();
	printconfig();
	run();
}

void			ClassConfig::parse(void)
{
	openfile();
	list<string>::iterator i;
	for (i = _lstconf.begin(); i != _lstconf.end(); i++)
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

			ClassProgram *_new = new ClassProgram();
			_new->setName(*name);
			while (1)
			{
				i++;
				if (i == _lstconf.end())
					break ;
				if (strchr(i->c_str(), '[') != NULL \
					&& strchr(i->c_str(), ']') != NULL)
				{
					i--;
					break ;
				}
				int findcomment = i->find(";");
				int len = i->length();
				if (findcomment != -1)
					i->erase(findcomment, len);
				len = i->length();
				int find = i->find("=");
				if (find == -1)
					break ;
				string *name = new string(i->substr(0, find));
				string *info = new string(i->substr(find + 1, len));

				if (strncmp(name->c_str(), "command", name->length()) == 0)
					_new->setCmd(*info);
				else if (strncmp(name->c_str(), "numprocs", name->length()) == 0)
					_new->setProc(atoi(info->c_str()));
				else if (strncmp(name->c_str(), "directory", name->length()) == 0)
					_new->setWorkingdir(*info);
				else if (strncmp(name->c_str(), "startretries", \
							name->length()) == 0)
					_new->setStartretry(atoi(info->c_str()));
				else if (strncmp(name->c_str(), "startsec", name->length()) == 0)
					_new->setStarttime(atoi(info->c_str()));
				else if (strncmp(name->c_str(), "stopwaitsecs", \
							name->length()) == 0)
					_new->setStoptime(atoi(info->c_str()));
				else if (strncmp(name->c_str(), "stopsignal", name->length()) == 0)
					_new->setStopsignal(*info);
				else if (strncmp(name->c_str(), "stderr_logfile", \
							name->length()) == 0)
					_new->setStderr(*info);
				else if (strncmp(name->c_str(), "stdout_logfile", \
						name->length()) == 0)
					_new->setStdin(*info);
				else if (strncmp(name->c_str(), "umask", name->length()) == 0)
					_new->setUmask((mode_t)atoi(info->c_str()));
				else if (strncmp(name->c_str(), "autostart", name->length()) == 0)
				{
					if (strncmp(info->c_str(), "true", info->length()) == 0)
						_new->setAutostart(true);
				}
				else if (strncmp(name->c_str(), "env", name->length()) == 0)
				{
					while (1)
					{
						int	next = info->find(",");
						if (next == -1)
							break ;
						_new->setEnv( string(info->substr(0, next)));
						info->erase(0, next + 1);
					}
					_new->setEnv( string(info->substr(0, info->length())));
				}
				else if (strncmp(name->c_str(), "exitcodes", name->length()) == 0)
				{
					while (1)
					{
						int	next = info->find(",");
						if (next == -1)
							break ;
						_new->setExitcode(atoi(info->c_str()));
						info->erase(0, next + 1);
					}
					_new->setExitcode(atoi(info->c_str()));
				}
				else if (strncmp(name->c_str(), "autorestart", name->length()) == 0)
					_new->setAutorestart(*info);

				delete name;
				delete info;
			}
			_lstprog.push_back(_new);
			delete action;
			delete name;
			if (i == _lstconf.end())
				break ;
		}
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
