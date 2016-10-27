/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 02:11:32 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 05:22:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) { return ; }

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) { return ; }

Zombie::Zombie(Zombie const &src) { if (this != &src) { } return ; }

Zombie::~Zombie(void) { return ; }

Zombie&		Zombie::operator=(Zombie const &src) { if (this != &src) { } return *this; }

void		Zombie::announce(void)
{
	std::cout << "<" << this->_name << " (" << this->_type;
	std::cout << ")> Braiiiiiiinnnssss..." << std::endl;
}
