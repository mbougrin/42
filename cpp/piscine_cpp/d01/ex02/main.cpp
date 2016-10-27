/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:07:20 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 05:57:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <cstdlib>

std::string		g_zombie_name[5];

int				randomChump(void)
{
	return (rand() % 4);
}

int				main(void)
{
	srand(time(NULL));
	g_zombie_name[0] = "Claire";
	g_zombie_name[1] = "Leon";
	g_zombie_name[2] = "Chris";
	g_zombie_name[3] = "Jill";
	g_zombie_name[4] = "Rebecca";
	Zombie		*undead = ZombieEvent().newZombie(g_zombie_name[randomChump()]);

	undead->announce();
	delete undead;
	return (0);
}
