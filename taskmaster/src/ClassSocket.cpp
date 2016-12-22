/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassSocket.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:34:47 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/22 14:38:04 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClassSocket.hpp>

int					ClassSocket::_sd;
struct s_fds		*ClassSocket::_fds;
int					ClassSocket::_client;
Tintin_reporter		ClassSocket::_log;
ClassConfig			ClassSocket::_configuration;
bool				ClassSocket::_v;
extern 				char **environ;

ClassSocket::ClassSocket(void)
{
	_fds = NULL;
	_sd = 0;
	_port = 4242;
	_client = 0;
	_log.init();
	createsocket();
	return ;
}

ClassSocket::ClassSocket(int port) : _port(port)
{
	_fds = NULL;
	_sd = 0;
	_client = 0;
	_log.init();
	createsocket();
	return ;
}

ClassSocket::ClassSocket(int port, char *conf, bool verbose) 
	: _port(port), _conf(conf)
{
	_v = verbose;
	_fds = NULL;
	_sd = 0;
	_client = 0;
	_log.setVerbose(verbose);
	_log.init();
	_configuration.init(_conf, _log);
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

void 				my_itoa(int value, std::string& buf, int base)
{
	int i = 30;

	buf = "";
	for (; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;

}

void				ClassSocket::reading(void)
{
	char		buffer[127];

	while (1)
	{
		int	 ret;

		ret = read(0, buffer, 127);
		buffer[ret] = '\0';
		std::cout << buffer;
		if (strchr(buffer, '\n') == NULL)
			std::cout << std::endl;
		bzero(buffer, 127);
	}

}

void				ClassSocket::mainloop(void)
{
	string		str;
	string		ptr;
	pid_t		pid = getpid();

	my_itoa(pid, ptr, 10);
	_log.writelog("INFO", "Entering Daemon mode.");
	str = string("Started. PID: ");
	_log.writelog("INFO", str + ptr);
	if (_v == true)
	{
		std::cout << "Entergin Daemon mode." << std::endl;
		std::cout << str << ptr << std::endl;
	}
	if (_v == true)
	{
		std::thread _thread(ClassSocket::reading);
		_thread.detach();
	}
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
		if (_v == true)
			std::cout << "Client disconnected." << std::endl;
		_log.writelog("LOG", "Client disconnected.");
		_client--;
	}
	else
	{
		if (strcmp(_fds[cs].buf_read, "quit\n") == 0)
		{
			if (_v == true)
				std::cout << "Request quit." << std::endl;
			_log.writelog("INFO", "Request quit.");
			_log.clear();
			exit(-1);
		}
		else if (strcmp(_fds[cs].buf_read, "status\n") == 0)
			std::cout << "status" << std::endl;
		else if (strcmp(_fds[cs].buf_read, "start\n") == 0)
			std::cout << "start" << std::endl;
		else if (strcmp(_fds[cs].buf_read, "stop\n") == 0)
			std::cout << "stop" << std::endl;
		else if (strcmp(_fds[cs].buf_read, "reload\n") == 0)
			std::cout << "reload" << std::endl;
		if (_v == true && strchr(_fds[cs].buf_read, '\n') == NULL)
			std::cout << _fds[cs].buf_read << std::endl;
		else if (_v == true)
			std::cout << _fds[cs].buf_read;
		_log.writelog("LOG", _fds[cs].buf_read);
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
		if (_v == true)
			std::cout << "Error accept fail." << std::endl;
		_log.writelog("ERROR", "Error accept fail.");
		exit(-1);
	}
	ClassSocket::cleanclient(&_fds[cs]);
	if (_client >= MAX_USER)
	{
		close(cs);
		stringstream	ss;
		if (_v == true)
			std::cout << "Error full client " << _client << "/" << \
				MAX_USER << std::endl;
		ss << "Error full client " << _client << "/" << MAX_USER;
		_log.writelog("ERROR", ss.str());
		return ;
	}
	if (_v == true)
		std::cout << "Client connected." << std::endl;
	_log.writelog("LOG", "Client connected.");
	_fds[cs].type = FD_CLIENT;
	_fds[cs].fct_read = &ClassSocket::clientread;
	_fds[cs].fct_write = &ClassSocket::clientwrite;
	_client++;
}

void				ClassSocket::createsocket(void)
{
	struct rlimit		rlp;
	struct sockaddr_in	sin;

	if (_v == true)
		std::cout << "Creating server." << std::endl;
	_log.writelog("INFO", "Creating server.");
	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
	{
		if (_v == true)
			std::cout << "Error getrlimit fail." << std::endl;
		_log.writelog("ERROR", "Error getrlimit fail.");
		exit(-1);
	}
	_maxsd = rlp.rlim_cur;
	_fds = (struct s_fds *)malloc(sizeof(struct s_fds) * _maxsd);
	if ((_sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		if (_v == true)
			std::cout << "Error socket fail." << std::endl;
		_log.writelog("ERROR", "Error socket fail.");
		exit(-1);
	}
	sin.sin_port = htons(_port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	if (::bind(_sd, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		if (_v == true)
			std::cout << "Error bind fail." << std::endl;
		_log.writelog("ERROR", "Error bind fail.");
		exit(-1);
	}
	if (listen(_sd, 42) == -1)
	{
		if (_v == true)
			std::cout << "Error listen fail." << std::endl;
		_log.writelog("ERROR", "Error listen fail.");
		exit(-1);
	}
	_fds[_sd].type = FD_SERV;
	_fds[_sd].fct_read = &ClassSocket::acceptclient;
	if (_v == true)
		std::cout << "Server created." << std::endl;
	_log.writelog("INFO", "Server created.");
}
