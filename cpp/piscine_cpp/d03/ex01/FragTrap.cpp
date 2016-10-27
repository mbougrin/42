/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 00:48:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 02:44:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(100),
	_max_energy_points(100),
	_level(1),
	_melee_attack_damage(30),
	_ranged_attack_damage(20),
	_armor(5),
	_name("FragTrap")
{
	std::cout << "New FragTrap Created!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) :
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(100),
	_max_energy_points(100),
	_level(1),
	_melee_attack_damage(30),
	_ranged_attack_damage(20),
	_armor(5),
	_name(name)
{
	std::cout << "New FragTrap Created!" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) :
	_hit_points(100),
	_max_hit_points(100),
	_energy_points(100),
	_max_energy_points(100),
	_level(1),
	_melee_attack_damage(30),
	_ranged_attack_damage(20),
	_armor(5),
	_name("FragTrap")
{
	std::cout << "New FragTrap Created!" << std::endl;
	if (this != &src)
	{
		*this = src ;
	}
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "New FragTrap Destructed!" << std::endl;
	return ;
}

FragTrap&		FragTrap::operator=(FragTrap const &src) { if (this != &src) { } return *this; }

std::string		FragTrap::get_name(void) { return (this->_name); }

int				FragTrap::get_ranged_damage(void) { return (this->_ranged_attack_damage); }

int				FragTrap::get_melee_damage(void) { return (this->_melee_attack_damage); }

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

int				FragTrap::get_level(void) { return (this->_level); }

void			FragTrap::beRepaired(unsigned int amount)
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

void			FragTrap::takeDamage(unsigned int amount)
{
	if ((this->_hit_points - this->_armor) < (int)amount)
	{
		this->_hit_points = 0;
		std::cout << "FR4G-TP " << this->get_name() << " is dead!" << std::endl;
	}
	else
		this->_hit_points -= (amount - this->_armor);
}

void			FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->get_name() << " attack ";
	std::cout << target << " at melee, causing ";
	std::cout << this->get_melee_damage() << " points of damage !" << std::endl;
}

void			FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->get_name() << " attack ";
	std::cout << target << " at range, causing ";
	std::cout << this->get_ranged_damage() << " points of damage !" << std::endl;
}
