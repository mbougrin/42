/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassProgram.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:42:51 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/22 14:43:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClassProgram.hpp>

ClassProgram::ClassProgram(void)
{
	_name = NULL;
	_cmd = NULL;
	_proc = 0;
	_umask = 0;
	_workingdir = NULL;
	_autostart = false;
	_startretry = 0;
	_starttime = 0;
	_stoptime = 0;
	_stopsignal = NULL;
	_stdin = NULL;
	_stderr = NULL;
	return ;
}

ClassProgram::ClassProgram(ClassProgram const &src)
{
	if (this != &src)
	{

	}
	return ;
}

void				ClassProgram::setName(const string &name)
{
	_name = new string(name);
}

const string		&ClassProgram::getName(void) const
{
	return (*_name);
}

void				ClassProgram::setCmd(const string &cmd)
{
	_cmd = new string(cmd);
}

const string		&ClassProgram::getCmd(void) const
{
	return (*_cmd);
}

void				ClassProgram::setProc(int nb)
{
	_proc = nb;
}

int					ClassProgram::getProc(void) const
{
	return (_proc);
}

void				ClassProgram::setUmask(mode_t mask)
{
	_umask = mask;
}

mode_t				ClassProgram::getUmask(void) const
{
	return (_umask);
}

void				ClassProgram::setWorkingdir(const string &str)
{
	_workingdir = new string(str);
}

const string		&ClassProgram::getWorkingdir(void) const
{
	return (*_workingdir);
}

void				ClassProgram::setAutostart(bool autostart)
{
	_autostart = autostart;
}

bool				ClassProgram::getAutostart(void) const
{
	return (_autostart);
}

void				ClassProgram::setAutorestart(bool autorestart)
{
	_autorestart = autorestart;
}

bool				ClassProgram::getAutorestart(void) const
{
	return (_autorestart);
}


void				ClassProgram::setExitcode(int nb)
{
	_exitcode.push_front(nb);
}

const list<int>		&ClassProgram::getExitcode(void) const
{
	return (_exitcode);
}

void				ClassProgram::setStartretry(int nb)
{
	_startretry = nb;
}

int					ClassProgram::getStartretry(void) const
{
	return (_startretry);
}

void				ClassProgram::setStarttime(int nb)
{
	_starttime = nb;
}

int					ClassProgram::getStarttime(void) const
{
	return (_starttime);
}

void				ClassProgram::setStoptime(int nb)
{
	_stoptime = nb;
}

int					ClassProgram::getStoptime(void) const
{
	return (_stoptime);
}

void				ClassProgram::setStopsignal(const string &str)
{
	_stopsignal = new string(str);
}

const string		&ClassProgram::getStopsignal(void) const
{
	return (*_stopsignal);
}

void				ClassProgram::setStdin(const string &str)
{
	_stdin = new string(str);
}

const string		&ClassProgram::getStdin(void) const
{
	return (*_stdin);
}

void				ClassProgram::setStderr(const string &str)
{
	_stderr = new string(str);
}

const string		&ClassProgram::getStderr(void) const
{
	return (*_stderr);
}

void				ClassProgram::setEnv(const string &str)
{
	_env.push_front(str);
}

const list<string>	&ClassProgram::getEnv(void) const
{
	return (_env);
}

void				ClassProgram::noleaks(void)
{
	delete	_name;
	delete	_cmd;
	delete	_workingdir;
	delete	_stopsignal;
}

ClassProgram 		&ClassProgram::operator=(ClassProgram const &src)
{
	if (this != &src)
	{

	}
	return (*this);
}

ClassProgram::~ClassProgram(void)
{
	return ;
}
