/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:08:00 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 10:33:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
	this->_hit_points = 60;
	this->_max_hit_points = 60;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_level = 1;
	this->_melee_attack_damage = 60;
	this->_ranged_attack_damage = 5;
	this->_armor = 0;
	std::cout << "New NinjaTrap Created!" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string name)
{
	this->_name = name;
	this->_hit_points = 60;
	this->_max_hit_points = 60;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_level = 1;
	this->_melee_attack_damage = 60;
	this->_ranged_attack_damage = 5;
	this->_armor = 0;
	std::cout << "New NinjaTrap Created!" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
	if (this != &src) { *this = src ; }
	this->_hit_points = 60;
	this->_max_hit_points = 60;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_level = 1;
	this->_melee_attack_damage = 60;
	this->_ranged_attack_damage = 5;
	this->_armor = 0;
	std::cout << "New NinjaTrap Created!" << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "New NinjaTrap Destructed!" << std::endl;
	return ;
}

NinjaTrap&		NinjaTrap::operator=(NinjaTrap const &src) { if (this != &src) { } return *this; }

void			NinjaTrap::ninjaShoebox(ClapTrap& clap)
{
	std::cout << this->_name << " attack with ambush " << clap.get_name() << std::endl;
}

void			NinjaTrap::ninjaShoebox(NinjaTrap& ninja)
{
	std::cout << this->_name << " attack with mutilate " << ninja.get_name() << std::endl;
}

void			NinjaTrap::ninjaShoebox(FragTrap& frag)
{
	std::cout << this->_name << " attack with hemorrhage " << frag.get_name() << std::endl;
}

void			NinjaTrap::ninjaShoebox(ScavTrap& scav)
{
	std::cout << this->_name << " attack with eviscerate " << scav.get_name() << std::endl;
}
