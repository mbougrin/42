/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 00:48:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 09:00:26 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "New ScavTrap Created!" << std::endl;
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 50;
	this->_max_energy_points = 50;
	this->_level = 1;
	this->_melee_attack_damage = 20;
	this->_ranged_attack_damage = 15;
	this->_armor = 3;
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "New ScavTrap Created!" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 50;
	this->_max_energy_points = 50;
	this->_level = 1;
	this->_melee_attack_damage = 20;
	this->_ranged_attack_damage = 15;
	this->_armor = 3;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "New ScavTrap Created!" << std::endl;
	if (this != &src)
	{
		*this = src ;
	}
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 50;
	this->_max_energy_points = 50;
	this->_level = 1;
	this->_melee_attack_damage = 20;
	this->_ranged_attack_damage = 15;
	this->_armor = 3;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "New ScavTrap Destructed!" << std::endl;
	return ;
}

ScavTrap&		ScavTrap::operator=(ScavTrap const &src) { if (this != &src) { } return *this; }

void			ScavTrap::challengeNewcomer(std::string const &target)
{
	std::string		name[5];

	if (this->_energy_points >= 25)
	{
		this->_energy_points -= 25;
		name[0] = "Take up";
		name[1] = "Take down";
		name[2] = "Take left";
		name[3] = "Take rigth";
		name[4] = "Take a seat";
		std::cout << "FR4G-TP " << this->get_name() << " attacks ";
		std::cout << target << " with " << name[rand() % 4];
		std::cout << " lost 25 points energy!" << std::endl;
	}
	else
		std::cout << "enough energy points!" << std::endl;
}
