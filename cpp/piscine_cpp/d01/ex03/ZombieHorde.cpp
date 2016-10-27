/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 02:11:40 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 08:17:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

std::string		g_zombie_type[5];
std::string		g_zombie_name[5];

ZombieHorde::ZombieHorde(void)
{
	return ;
}

ZombieHorde::ZombieHorde(int nb) : _nb(nb)
{
	g_zombie_type[0] = "Hunter";
	g_zombie_type[1] = "Cerbère";
	g_zombie_type[2] = "Reaper";
	g_zombie_type[3] = "Zombie";
	g_zombie_type[4] = "Napad";
	g_zombie_name[0] = "Claire";
	g_zombie_name[1] = "Leon";
	g_zombie_name[2] = "Chris";
	g_zombie_name[3] = "Jill";
	g_zombie_name[4] = "Rebecca";
	int		i;

	i = 0;
	while (i < _nb)
	{
		this->_tab[i] = newZombie(g_zombie_name[rand() % 4]);
		i++;
	}
	return ;
}

void		ZombieHorde::announce(void)
{
	int		i;

	i = 0;
	while (i < this->_nb)
	{
		this->_tab[i]->announce();
		i++;
	}
}

ZombieHorde::ZombieHorde(ZombieHorde const &src) { if (this != &src) { } return ; }

ZombieHorde::~ZombieHorde(void)
{
	int			i;

	i = 0;
	while (i < this->_nb)
	{
		delete this->_tab[i];
		i++;
	}
	return ;
}

ZombieHorde&		ZombieHorde::operator=(ZombieHorde const &src) { if (this != &src) { } return *this; }

std::string		ZombieHorde::setZombieType(void) { return (g_zombie_type[rand() % 4]); }

Zombie			*ZombieHorde::newZombie(std::string name)
{
	Zombie		*_new = new Zombie(name, this->setZombieType());
	return (_new);
}
