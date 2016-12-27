/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:41:08 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/27 11:46:07 by mbougrin         ###   ########.fr       */
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

int				ClassConfig::countspace(const char *str) const
{
	int		count = 0;

	for (int i = 0 ; str[i] != '\0' ; ++ i)
	{
		if (str[i] == ' ')
			count++;
	}
	return (count);
}

void			ClassConfig::run(void)
{
	int		ret = 0;
	list<ClassProgram*>::iterator i;
	for (i = _lstprog.begin(); i != _lstprog.end(); ++i)
	{
	//	i = _lstprog.begin();
		int	check = 0;
		if ((*i)->getAutostart() == true)
		{
			while (check < (*i)->getStartretry())
			{
				pid_t	pid;
		
				sleep((*i)->getStarttime());
				if ((pid = fork()) < 0)
					exit(-1);
				if (pid == 0)
				{
					char 	**av = NULL;
					char	**env = NULL;
					string	*tmp = new string((*i)->getCmd().c_str());
					int		len = countspace(tmp->c_str());
					int		count = 0;

					av = (char **)malloc(sizeof(char *) * (len + 2));
					while (1)
					{
						int find = tmp->find(' ');
						if (find == -1)
							break ;
						av[count] = strdup(tmp->substr(0, find).c_str());
						std::cout << av[count] << " av" << std::endl;
						std::cout << *tmp << " tmp" << std::endl;
						tmp->erase(0, find + 1);
						std::cout << *tmp << " tmp" << std::endl;
						count++;
					}
					if (count == 0)
					{
						av[0] = strdup(tmp->c_str());
						av[1] = NULL;
					}
					else
					{
						av[count] = strdup(tmp->substr(0, tmp->length()).c_str());
						av[count + 1] = NULL;
					}
					delete tmp;

					const std::list<string>tmplst = (*i)->getEnv();
					list<string>::const_iterator	j;
					env = (char **)malloc(sizeof(char *) * (tmplst.size() + 1));
					count = 0;
					for (j = tmplst.begin() ; j != tmplst.end() ; ++j)
					{
						env[count] = strdup(j->c_str());
						count++;
					}
					env[count] = NULL;

					umask((*i)->getUmask());
					chdir((*i)->getWorkingdir().c_str());
			//		freopen((*i)->getStdin().c_str(), "w", stdout);
			//		freopen((*i)->getStderr().c_str(), "w", stderr);
					//TODO parseur arg		OK
					//parseur env			OK
					//thread binary
					//umask 				OK
					//starttime 			OK
					//runing or not			OK
					//working dir 			OK
					//start retry			OK
					//fropen stdin			OK
					//fropen stderr			OK
					//check autostart		OK
					//processor set
					(*i)->setRun(true);
					ret = execve((*i)->getCmd().c_str(), av, env);
					count = 0;
					while (av[count] != NULL)
					{
						free(av[count]);
						av[count] = NULL;
						count++;
					}
					free(av);
					av = NULL;

					if (env != NULL)
					{
						count = 0;
						while (env[count] != NULL)
						{
							free(env[count]);
							env[count] = NULL;
							count++;
						}
						free(env);
						env = NULL;
					}
				}
				else
					wait(NULL);
				check++;
				if (ret != -1)
					break ;
			}
			if (check == (*i)->getStartretry() || ret == -1)
				(*i)->setRun(false);
		}
	}
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
