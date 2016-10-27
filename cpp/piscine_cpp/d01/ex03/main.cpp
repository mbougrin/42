/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:07:20 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 06:45:14 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <cstdlib>

int				randomChump(void)
{
	return (rand() % 4);
}

int				main(void)
{
	srand(time(NULL));
	ZombieHorde		*undead = new ZombieHorde(10);

	undead->announce();
	delete undead;
	return (0);
}
