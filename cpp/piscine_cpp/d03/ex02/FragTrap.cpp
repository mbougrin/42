/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 00:48:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 09:00:29 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "New FragTrap Created!" << std::endl;
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 100;
	this->_max_energy_points = 100;
	this->_level = 1;
	this->_melee_attack_damage = 30;
	this->_ranged_attack_damage = 20;
	this->_armor = 5;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "New FragTrap Created!" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 100;
	this->_max_energy_points = 100;
	this->_level = 1;
	this->_melee_attack_damage = 30;
	this->_ranged_attack_damage = 20;
	this->_armor = 5;
	return ;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "New FragTrap Created!" << std::endl;
	if (this != &src)
	{
		*this = src ;
	}
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 100;
	this->_max_energy_points = 100;
	this->_level = 1;
	this->_melee_attack_damage = 30;
	this->_ranged_attack_damage = 20;
	this->_armor = 5;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "New FragTrap Destructed!" << std::endl;
	return ;
}

FragTrap&		FragTrap::operator=(FragTrap const &src) { if (this != &src) { } return *this; }

void			FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	std::string		name[5];

	if (this->_energy_points >= 25)
	{
		this->_energy_points -= 25;
		name[0] = "Fire shooting";
		name[1] = "Earth shooting";
		name[2] = "Water shooting";
		name[3] = "Lightning shooting";
		name[4] = "Shadow shooting";
		std::cout << "FR4G-TP " << this->get_name() << " attacks ";
		std::cout << target << " with " << name[rand() % 4];
		std::cout << " lost 25 points energy!" << std::endl;
	}
	else
		std::cout << "enough energy points!" << std::endl;
}
