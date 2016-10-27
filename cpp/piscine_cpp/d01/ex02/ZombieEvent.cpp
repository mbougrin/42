/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 02:11:40 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 05:57:42 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string		g_zombie_type[5];

ZombieEvent::ZombieEvent(void)
{
	g_zombie_type[0] = "Hunter";
	g_zombie_type[1] = "Cerbère";
	g_zombie_type[2] = "Reaper";
	g_zombie_type[3] = "Zombie";
	g_zombie_type[4] = "Napad";
	return ;
}

ZombieEvent::ZombieEvent(ZombieEvent const &src) { if (this != &src) { } return ; }

ZombieEvent::~ZombieEvent(void) { return ; }

ZombieEvent&		ZombieEvent::operator=(ZombieEvent const &src) { if (this != &src) { } return *this; }

std::string		ZombieEvent::setZombieType(void) { return (g_zombie_type[rand() % 4]); }

Zombie			*ZombieEvent::newZombie(std::string name)
{
	Zombie		*_new = new Zombie(name, this->setZombieType());
	return (_new);
}
