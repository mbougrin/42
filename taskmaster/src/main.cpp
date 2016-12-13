/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:33:07 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/13 12:55:53 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

void					my_signal(void)
{
	int 	i;

	i = 0;
	while (i < 32)
		signal(i++, &Tintin_reporter::sighandler);
}

int						main(int ac, char **av)
{
	char	*port = NULL;
	char	*conf = NULL;

	printf("salut");
	for (int i = 0 ; av[i] ; ++i)
	{
		if (strncmp(av[i], "-p", strlen(av[i])) == 0)
			port = av[i + 1];
		if (strncmp(av[i], "-c", strlen(av[i])) == 0)
			conf = av[i + 1];
	}
	if (conf == NULL || ac == 1)
	{
		write(1, av[0], strlen(av[0]));
		write(1, "\t-c configurationFile\n\t\t-p port\n", 30);
		return (-1);
	}
/*	if (port == NULL)
	{
		ClassSocket		socket = ClassSocket(4242);
		my_signal();
		socket.mainloop();
	}
	else
	{
		ClassSocket		socket = ClassSocket(atoi(port));
		my_signal();
		socket.mainloop();
		exit(EXIT_SUCCESS);
	}
*/	return (0);
}
