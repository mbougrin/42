/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:33:07 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/02 14:34:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>
#include <iostream>

static void				background(void)
{
	pid_t 				child;

	pid_t	parent;

	signal(SIGCHLD, exit);
	signal(SIGUSR1, exit);
	signal(SIGALRM, exit);
	if (getppid() == 1)
		return ;
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
}

void					my_signal(void)
{
	signal( SIGHUP, &Tintin_reporter::sighandler );
	signal( SIGINT, &Tintin_reporter::sighandler );
	signal( SIGQUIT, &Tintin_reporter::sighandler );
	signal( SIGILL, &Tintin_reporter::sighandler );
	signal( SIGTRAP, &Tintin_reporter::sighandler );
	signal( SIGABRT, &Tintin_reporter::sighandler );
	signal( SIGBUS, &Tintin_reporter::sighandler );
	signal( SIGFPE, &Tintin_reporter::sighandler );
	signal( SIGUSR1, &Tintin_reporter::sighandler );
	signal( SIGSEGV, &Tintin_reporter::sighandler );
	signal( SIGUSR2, &Tintin_reporter::sighandler );
	signal( SIGPIPE, &Tintin_reporter::sighandler );
	signal( SIGALRM, &Tintin_reporter::sighandler );
	signal( SIGTERM, &Tintin_reporter::sighandler );
//	signal( SIGSTKFLT, &Tintin_reporter::sighandler );
	signal( SIGTSTP, &Tintin_reporter::sighandler );
	signal( SIGTTIN, &Tintin_reporter::sighandler );
	signal( SIGTTOU, &Tintin_reporter::sighandler );
	signal( SIGURG, &Tintin_reporter::sighandler );
	signal( SIGXCPU, &Tintin_reporter::sighandler );
	signal( SIGXFSZ, &Tintin_reporter::sighandler );
	signal( SIGVTALRM, &Tintin_reporter::sighandler );
	signal( SIGPROF, &Tintin_reporter::sighandler );
//	signal( SIGPWR, &Tintin_reporter::sighandler );
	signal( SIGSYS, &Tintin_reporter::sighandler );
}

int						main(int ac, char **av)
{
	if (ac == 1)
	{
		background();
		my_signal();
		ClassSocket		socket = ClassSocket(4242);
		socket.mainloop();
	}
	else if (ac != 3)
		std::cout << av[0] << " -p port" << std::endl;
	else
	{
		for (int i = 0 ; i < ac ; ++i)
		{
			if (strcmp(av[i], "-p") == 0 && av[i + 1] != NULL)
			{
				background();
				ClassSocket		socket = ClassSocket(atoi(av[i + 1]));
				socket.mainloop();
				break ;
			}
		}
		std::cout << av[0] << " -p port" << std::endl;
	}
	return (0);
}
