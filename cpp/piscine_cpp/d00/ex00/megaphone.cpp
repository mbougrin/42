/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 09:10:54 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:34:07 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int					main(int ac, char **av)
{
	int			i;
	int			j;
	std::locale loc;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << std::toupper(av[i][j], loc);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
