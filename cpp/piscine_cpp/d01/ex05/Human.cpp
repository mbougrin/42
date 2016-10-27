/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 02:33:13 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 04:37:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include "Brain.hpp" 
#include <sstream>
#include <iostream>

Human::Human(void) : _brain(*(new Brain()))
{
	return ;
}

Brain			&Human::getBrain(void)
{
	return (Brain &)(this->_brain);
}

std::string		Human::identify(void) const
{
	return this->_brain.identify();
}

Human::~Human(void)
{
	delete &getBrain();
	return ;
}
