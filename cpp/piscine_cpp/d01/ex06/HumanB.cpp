/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 04:45:57 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 06:19:26 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) : _name(str)
{
	return ;
}

void		HumanB::attack(void)
{
		std::cout << this->_name << " attacks with his " << this->_type->name << std::endl;
			return ;
}

void		HumanB::setWeapon(Weapon& club)
{
	this->_type = &club;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}
