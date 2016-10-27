/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 08:31:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 09:00:28 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(50),
	_max_energy_points(50),
	_level(1),
	_melee_attack_damage(20),
	_ranged_attack_damage(15),
	_armor(3),
	_name("ClapTrap")
{
	std::cout << "New ClapTrap Created!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) :
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(50),
	_max_energy_points(50),
	_level(1),
	_melee_attack_damage(20),
	_ranged_attack_damage(15),
	_armor(3),
	_name(name)
{
	std::cout << "New ClapTrap Created!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) :
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(50),
	_max_energy_points(50),
	_level(1),
	_melee_attack_damage(20),
	_ranged_attack_damage(15),
	_armor(3),
	_name("ClapTrap")
{ 
	if (this != &src) { *this = src ; }
	std::cout << "New ClapTrap Created!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "New ClapTrap Destructed!" << std::endl;
	return ;
}

ClapTrap&		ClapTrap::operator=(ClapTrap const &src) { if (this != &src) { } return *this; }

std::string		ClapTrap::get_name(void) { return (this->_name); }

int				ClapTrap::get_ranged_damage(void) { return (this->_ranged_attack_damage); }

int				ClapTrap::get_melee_damage(void) { return (this->_melee_attack_damage); }

int				ClapTrap::get_level(void) { return (this->_level); }

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_max_hit_points > (int)(amount + this->_hit_points))
		this->_hit_points += amount;
	else
		this->_hit_points = this->_max_hit_points;
	if (this->_max_energy_points > (int)(amount + this->_energy_points))
		this->_energy_points += amount;
	else
		this->_energy_points = this->_max_energy_points;
	std::cout << "FR4G-TP " << this->get_name() << " beRepaired ";
	std::cout << amount << " Hit Points and ";
	std::cout << amount << " Energy Points!" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if ((this->_hit_points - this->_armor) < (int)amount)
	{
		this->_hit_points = 0;
		std::cout << "FR4G-TP " << this->get_name() << " is dead!" << std::endl;
	}
	else
		this->_hit_points -= (amount - this->_armor);
}

void			ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->get_name() << " attack ";
	std::cout << target << " at melee, causing ";
	std::cout << this->get_melee_damage() << " points of damage !" << std::endl;
}

void			ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->get_name() << " attack ";
	std::cout << target << " at range, causing ";
	std::cout << this->get_ranged_damage() << " points of damage !" << std::endl;
}
