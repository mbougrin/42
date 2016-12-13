/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:33:07 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/08 13:01:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>
#include <iostream>

void					my_signal(void)
{
	int 		i;

	i = 0;
	while (i < 32)
		signal( i++, &Tintin_reporter::sighandler );
	//signal( SIGINT, &Tintin_reporter::sighandler );
	//signal( SIGQUIT, &Tintin_reporter::sighandler );
	//signal( SIGILL, &Tintin_reporter::sighandler );
	//signal( SIGTRAP, &Tintin_reporter::sighandler );
	//signal( SIGABRT, &Tintin_reporter::sighandler );
	//signal( SIGBUS, &Tintin_reporter::sighandler );
	//signal( SIGFPE, &Tintin_reporter::sighandler );
	//signal( SIGKILL, &Tintin_reporter::sighandler );
	//signal( SIGUSR1, &Tintin_reporter::sighandler );
	//signal( SIGSEGV, &Tintin_reporter::sighandler );
	//signal( SIGUSR2, &Tintin_reporter::sighandler );
	//signal( SIGPIPE, &Tintin_reporter::sighandler );
	//signal( SIGALRM, &Tintin_reporter::sighandler );
	//signal( SIGTERM, &Tintin_reporter::sighandler );
	//signal( SIGTSTP, &Tintin_reporter::sighandler );
	//signal( SIGTTIN, &Tintin_reporter::sighandler );
	//signal( SIGTTOU, &Tintin_reporter::sighandler );
	//signal( SIGURG, &Tintin_reporter::sighandler );
	//signal( SIGXCPU, &Tintin_reporter::sighandler );
	//signal( SIGXFSZ, &Tintin_reporter::sighandler );
	//signal( SIGVTALRM, &Tintin_reporter::sighandler );
	//signal( SIGPROF, &Tintin_reporter::sighandler );
	//signal( SIGSYS, &Tintin_reporter::sighandler );
}

int						main(int ac, char **av)
{
	if (ac == 1)
	{
		ClassSocket		socket = ClassSocket(4242);
		my_signal();
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
				ClassSocket		socket = ClassSocket(atoi(av[i + 1]));
				my_signal();
				socket.mainloop();
				exit(EXIT_SUCCESS);
			}
		}
		std::cout << av[0] << " -p port" << std::endl;
	}
	return (0);
}
