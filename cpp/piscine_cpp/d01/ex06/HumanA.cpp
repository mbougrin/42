/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 04:46:05 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 05:41:12 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& club) : _name(name), _type(club)
{
	return ;
}

void		HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_type.name << std::endl;
	return ;
}

Weapon		&HumanA::getType(void) const
{
	return ((Weapon &)(this->_type));
}

HumanA::~HumanA(void)
{
	return ;
}
