/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 02:33:26 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 04:34:24 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain(void)
{
	return ;
}

std::string		Brain::identify(void) const
{
		std::stringstream data;
		data << std::hex << this;
		return (data.str());
}

Brain::~Brain(void)
{
	return ;
}
