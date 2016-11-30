/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassSocket.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:34:47 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/30 13:15:50 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClassSocket.hpp>

int					ClassSocket::_sd;
struct s_fds		*ClassSocket::_fds;
int					ClassSocket::_client;
Tintin_reporter		ClassSocket::_log;
extern 				char **environ;

ClassSocket::ClassSocket(void)
{
	_fds = NULL;
	_sd = 0;
	_port = 4242;
	_client = 0;
	createsocket();
	return ;
}

ClassSocket::ClassSocket(int port) : _port(port)
{
	_fds = NULL;
	_sd = 0;
	_client = 0;
	createsocket();
	return ;
}

ClassSocket::ClassSocket(ClassSocket const &src)
{
	if (this != &src)
	{

	}
	return ;
}

ClassSocket::~ClassSocket(void)
{
	free(_fds);
	close(_sd);
	return ;
}

ClassSocket			&ClassSocket::operator=(ClassSocket const &src)
{
	if (this != &src)
	{

	}
	return (*this);
}

void				ClassSocket::initfd(void)
{
	int			i;

	i = 0;
	_dmax = 0;
	FD_ZERO(&_writefd);
	FD_ZERO(&_readfd);
	while (i < _maxsd)
	{
		if (_fds[i].type != FD_FREE)
		{
			FD_SET(i, &_readfd);
			if (strlen(_fds[i].buf_write) > 0)
				FD_SET(i, &_writefd);
			_dmax = (i > _dmax) ? i : _dmax;
		}
		++i;
	}
}

void				ClassSocket::do_select(void)
{
	_r = select(_dmax + 1, &_readfd, &_writefd, NULL, NULL);
}

void				ClassSocket::check_fd(void)
{
	int		i = 0;

	while ((i < _maxsd) && (_r > 0))
	{
		if (FD_ISSET(i, &_readfd))
			_fds[i].fct_read(i);
		if (FD_ISSET(i, &_writefd))
			_fds[i].fct_write(i);
		if (FD_ISSET(i, &_readfd) || \
				FD_ISSET(i, &_writefd))
			_r--;
		i++;
	}
}

void				ClassSocket::mainloop(void)
{
	while (1)
	{
		initfd();
		do_select();
		check_fd();
	}
}

void				ClassSocket::cleanclient(struct s_fds *fds)
{
	fds->type = FD_FREE;
	fds->fct_read = NULL;
	fds->fct_write = NULL;
}

void				ClassSocket::clientread(int cs)
{
	int					r;

	r = recv(cs, _fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		ClassSocket::cleanclient(&_fds[cs]);
		close(cs);
		_client--;
		std::cout << "leave client " << _client << "/" << MAX_USER << std::endl;
	}
	else
	{
		if (strcmp(_fds[cs].buf_read, "quit\n") == 0)
		{
			_log.writelog(FILENAME, "INFO", "Quitting.");
			exit(-1);
		}
		_log.writelog(FILENAME, "LOG", _fds[cs].buf_read);
		std::cout << _fds[cs].buf_read;
		bzero(_fds[cs].buf_read, 1024);
	}
}

void				ClassSocket::clientwrite(int cs)
{
	(void)cs;
}

void				ClassSocket::acceptclient(int i)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;

	(void)i;
	csin_len = sizeof(csin);
	if ((cs = accept(_sd, (struct sockaddr *)&csin, &csin_len)) == -1)
	{
		std::cout << "accept error" << std::endl;
		exit(-1);
	}
	ClassSocket::cleanclient(&_fds[cs]);
	if (_client >= MAX_USER)
	{
		close(cs);
		std::cout << "full client " << _client << "/" << MAX_USER << std::endl;
		return ;
	}
	_fds[cs].type = FD_CLIENT;
	_fds[cs].fct_read = &ClassSocket::clientread;
	_fds[cs].fct_write = &ClassSocket::clientwrite;
	std::cout << "new client" << std::endl;
	_client++;
}

void				ClassSocket::createsocket(void)
{
	struct rlimit		rlp;
	struct sockaddr_in	sin;
	pid_t 				child;
	//int					status;	

/*	if (setpgid(getpid(), getpid() < 0))
	{
		std::cout << "setpgid error" << std::endl;
		exit(-1);
	}
	if (tcsetpgrp(STDIN_FILENO, getpgrp()) < 0)
	{
		std::cout << "tcsetpgrp error" << std::endl;
		exit(-1);
	}
	if ((child = fork()) < 0)
	{
		std::cout << "fork error" << std::endl;
		exit(-1);
	}
	if (child == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		signal(SIGTTIN, SIG_DFL);
		signal(SIGTTOU, SIG_DFL);
		signal(SIGCHLD, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		if (setpgid(0, 0) < 0)
		{
			std::cout << "setpgid error" << std::endl;
			exit(-1);
		}
		if (tcsetpgrp(STDIN_FILENO, getpgrp()) < 0)
		{
			std::cout << "tcsetpgrp error" << std::endl;
			exit(-1);
		}
		exit(2);
	}
	else
	{
		if (setpgid(child, child) < 0)
		{
			std::cout << "setpgid error" << std::endl;
			exit(-1);
		}
	}
	if (tcsetpgrp(STDIN_FILENO, getpgid(child)) < 0)
	{
		std::cout << "tcsetpgrp error" << std::endl;
		exit(-1);
	}
	if (kill(child, SIGCONT) < 0)
	{
		std::cout << "kill error" << std::endl;
		exit(-1);
	}
	wait(&status);
	if (tcsetpgrp(STDIN_FILENO, getpgrp()) < 0)
	{
		std::cout << "tcsetpgrp error" << std::endl;
		exit(-1);
	}*/
	pid_t	parent;

	signal (SIGCHLD, exit);
	signal (SIGCHLD, exit);
	signal (SIGCHLD, exit);
	if (getppid() == 1)
	{
		return ;
	}
	child = fork();
	if (child < 0)
		exit(1);
	if (child > 0)
		exit(0);
	parent = getppid();
	signal(SIGCHLD, SIG_DFL);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	signal(SIGTERM, SIG_DFL);
	umask(0);
	pid_t sid = setsid();
	if (sid < 0)
		exit(1);
	if (chdir("/") < 0)
		exit(1);
	freopen( "/dev/null", "r", stdin);
	freopen( "/dev/null", "w", stdout);
	freopen( "/dev/null", "w", stderr);

	kill(parent, SIGUSR1);
//	if (WIFSTOPPED(status))



	_log.writelog(FILENAME, "INFO", "Started.");
	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
	{
		std::cout << "getrlimit error" << std::endl;
		exit(-1);
	}
	_maxsd = rlp.rlim_cur;
	_fds = (struct s_fds *)malloc(sizeof(struct s_fds) * _maxsd);
	_log.writelog(FILENAME, "INFO", "Creating server.");
	if ((_sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		std::cout << "socket error" << std::endl;
		exit(-1);
	}
	sin.sin_port = htons(_port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	bind(_sd, (const struct sockaddr *)&sin, sizeof(sin));
	listen(_sd, 42);
	_fds[_sd].type = FD_SERV;
	_fds[_sd].fct_read = &ClassSocket::acceptclient;
	_log.writelog(FILENAME, "INFO", "Server created.");
}
