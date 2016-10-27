/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 04:45:51 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 05:50:19 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str) : name(str)
{
	return ;
}

void	Weapon::setType(std::string ptr)
{
	this->name = ptr;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}
