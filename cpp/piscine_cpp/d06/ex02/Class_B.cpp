/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_B.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:21:11 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 20:49:28 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class_B.hpp"
#include "Class_Base.hpp"

Class_B::Class_B(void) : Class_Base()
{
	return ;
}

Class_B::Class_B(Class_B const &src) : Class_Base()
{
	*this = src;
	return ;
}

Class_B::~Class_B(void)
{
	return ;
}

Class_B&		Class_B::operator=(Class_B const &src)
{
	if (this != &src)
	{
	}
	return *this;
}
