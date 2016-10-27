/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_A.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:13:38 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 20:47:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class_A.hpp"
#include "Class_Base.hpp"

Class_A::Class_A(void) : Class_Base()
{
	return ;
}

Class_A::Class_A(Class_A const &src) : Class_Base()
{
	*this = src;
	return ;
}

Class_A::~Class_A(void)
{
	return ;
}

Class_A&		Class_A::operator=(Class_A const &src)
{
	if (this != &src)
	{
	}
	return *this;
}
