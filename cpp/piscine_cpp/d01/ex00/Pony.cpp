/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 00:25:35 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 00:44:51 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void) { return ; }

Pony::Pony(std::string name) : _name(name)
{
	std::cout << name << " is born!!!" << std::endl;
	return ;
}

std::string		Pony::get_name(void) { return (this->_name); }

Pony::Pony(Pony const &src) { if (this != &src) { } return ; }

Pony::~Pony(void)
{
	std::cout << this->_name << " is dead!!!" << std::endl;
	return ;
}

Pony&		Pony::operator=(Pony const &src) { if (this != &src) { } return *this; }
