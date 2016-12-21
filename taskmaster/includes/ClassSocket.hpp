/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassSocket.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:38:22 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/21 12:00:17 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_SOCKET_HPP
# define CLASS_SOCKET_HPP

# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# include <thread>
# include <pthread.h>

# include <sys/socket.h>
# include <stdlib.h>
# include <netinet/in.h>

# include <iostream>
# include <stdlib.h>

# include <sys/resource.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <string>
# include <iostream>
# include <sstream>

# include <signal.h>
# include <string.h>

# include <Tintin_reporter.hpp>
# include <ClassConfig.hpp>
# include <ClassProgram.hpp>

# define BUF_SIZE		1024

# define MAX_USER		3

# define FD_FREE		0
# define FD_SERV		1
# define FD_CLIENT		2

struct							s_fds
{
	int							type;
	void						(*fct_read)(int);
	void						(*fct_write)(int);
	char						buf_read[BUF_SIZE + 1];
	char						buf_write[BUF_SIZE + 1];
};

class							ClassSocket
{
	public:
		ClassSocket();
		ClassSocket(int port);
		ClassSocket(int port, char *conf, bool verbose);
		ClassSocket(ClassSocket const &src);
		ClassSocket &operator=(ClassSocket const &src);
		~ClassSocket();

		void					initfd(void);
		void					do_select(void);
		void					check_fd(void);
		void					mainloop(void);

		static	void			reading(void);
	
		static void				cleanclient(struct s_fds *fds);
		static void				clientread(int cs);
		static void				clientwrite(int cs);
		static void				acceptclient(int i);
		void					createsocket(void);
	private:
		int						_maxsd;
		int						_dmax;
		int						_r;
		int						_port;
		fd_set					_writefd;
		fd_set					_readfd;
		char					*_conf;

		static bool				_v;
		static Tintin_reporter	_log;
		static ClassConfig		_configuration;
		static int				_sd;
		static struct s_fds 	*_fds;
		static int				_client;
};

#endif
