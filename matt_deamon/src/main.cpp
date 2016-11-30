/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:33:07 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/29 13:50:04 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>
#include <iostream>

int						main(int ac, char **av)
{
	if (ac == 1)
	{
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
				ClassSocket		socket = ClassSocket(atoi(av[i + 1]));
				socket.mainloop();
				break ;
			}
		}
		std::cout << av[0] << " -p port" << std::endl;
	}
	return (0);
}
