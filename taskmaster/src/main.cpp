/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:33:07 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/09 11:38:01 by mbougrin         ###   ########.fr       */
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
