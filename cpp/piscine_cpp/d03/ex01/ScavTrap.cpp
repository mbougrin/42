/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 00:48:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 02:47:29 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(50),
	_max_energy_points(50),
	_level(1),
	_melee_attack_damage(20),
	_ranged_attack_damage(15),
	_armor(3),
	_name("ScavTrap")
{
	std::cout << "New ScavTrap Created!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) :
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
	std::cout << "New ScavTrap Created!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) :
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(50),
	_max_energy_points(50),
	_level(1),
	_melee_attack_damage(20),
	_ranged_attack_damage(15),
	_armor(3),
	_name("ScavTrap")
{
	std::cout << "New ScavTrap Created!" << std::endl;
	if (this != &src)
	{
		*this = src ;
	}
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "New ScavTrap Destructed!" << std::endl;
	return ;
}

ScavTrap&		ScavTrap::operator=(ScavTrap const &src) { if (this != &src) { } return *this; }

std::string		ScavTrap::get_name(void) { return (this->_name); }

int				ScavTrap::get_ranged_damage(void) { return (this->_ranged_attack_damage); }

int				ScavTrap::get_melee_damage(void) { return (this->_melee_attack_damage); }

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

int				ScavTrap::get_level(void) { return (this->_level); }

void			ScavTrap::beRepaired(unsigned int amount)
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

void			ScavTrap::takeDamage(unsigned int amount)
{
	if ((this->_hit_points - this->_armor) < (int)amount)
	{
		this->_hit_points = 0;
		std::cout << "FR4G-TP " << this->get_name() << " is dead!" << std::endl;
	}
	else
		this->_hit_points -= (amount - this->_armor);
}

void			ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->get_name() << " attack ";
	std::cout << target << " at melee, causing ";
	std::cout << this->get_melee_damage() << " points of damage !" << std::endl;
}

void			ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->get_name() << " attack ";
	std::cout << target << " at range, causing ";
	std::cout << this->get_ranged_damage() << " points of damage !" << std::endl;
}
