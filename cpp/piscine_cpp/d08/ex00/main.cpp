/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 12:08:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/17 15:28:05 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int				main(void)
{
	int		i = 42;
	int		tab[5] = {0, 1, 3, 41, 42};
	easyfind(tab, i);
	i = 1;
	easyfind(tab, i);
	i = 12;
	easyfind(tab, i);
	i = 32;
	easyfind(tab, i);
	return (0);
}
