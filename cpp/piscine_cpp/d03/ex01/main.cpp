/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 00:49:00 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 02:45:59 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <ctime>

int					main(void)
{
	FragTrap one("one");
	ScavTrap two("two");

	srand(time(NULL));
	one.meleeAttack(two.get_name());
	two.takeDamage(one.get_melee_damage());
	one.rangedAttack(two.get_name());
	two.takeDamage(one.get_ranged_damage());
	one.beRepaired(42);
	one.vaulthunter_dot_exe(two.get_name());

	two.meleeAttack(one.get_name());
	one.takeDamage(two.get_melee_damage());
	two.rangedAttack(one.get_name());
	one.takeDamage(two.get_ranged_damage());
	two.beRepaired(42);
	two.challengeNewcomer(one.get_name());

	two.meleeAttack(one.get_name());
	one.takeDamage(two.get_melee_damage());
	two.meleeAttack(one.get_name());
	one.takeDamage(two.get_melee_damage());
	two.meleeAttack(one.get_name());
	one.takeDamage(two.get_melee_damage());
	
	two.meleeAttack(one.get_name());
	one.takeDamage(two.get_melee_damage());
	two.meleeAttack(one.get_name());
	one.takeDamage(two.get_melee_damage());
	return (0);
}
