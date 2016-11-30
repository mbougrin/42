/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:33:07 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/30 17:39:48 by mbougrin         ###   ########.fr       */
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


static void				runlock(void)
{
//	if ((fd = open("/var/lock/matt_daemon.lock", O_RDWR | O_CREAT, 0644)) < 0)
//	{
//		std::cout << "file is locked" << std::endl;
//		exit(-1);
//	}
//	memset (&lock, 0, sizeof(lock));
//	lock.l_type = F_WRLCK;
//	fcntl (fd, F_SETLKW, &lock);
//	if (flock(fd, LOCK_EX) == -1)
//	{
//		std::cout << "file is locked" << std::endl;
//		exit(-1);
//	}
}
static void				exitlock(void)
{
//	if (flock(fd, LOCK_UN) == -1)
//	{
//		std::cout << "flock error" << std::endl;
//		exit(-1);
//	}
//	lock.l_type = F_UNLCK;
//	fcntl (fd, F_SETLKW, &lock);
//	close(fd);
}

int						main(int ac, char **av)
{
	if (ac == 1)
	{
int						fd;
struct flock 			lock;
	if ((fd = open("/var/lock/matt_daemon.lock", O_WRONLY | O_CREAT, 0644)) < 0)
	{
		std::cout << "file is locked" << std::endl;
		exit(-1);
	}
	memset (&lock, 0, sizeof(lock));
	lock.l_type = F_WRLCK;
	fcntl (fd, F_SETLKW, &lock);
		runlock();
		background();
		ClassSocket		socket = ClassSocket(4242);
		socket.mainloop();
		exitlock();
	lock.l_type = F_UNLCK;
	fcntl (fd, F_SETLKW, &lock);
	close(fd);
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
