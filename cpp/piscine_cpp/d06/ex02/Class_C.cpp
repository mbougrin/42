/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_C.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:21:09 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 20:49:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class_C.hpp"
#include "Class_Base.hpp"

Class_C::Class_C(void) : Class_Base()
{
	return ;
}

Class_C::Class_C(Class_C const &src) : Class_Base()
{
	*this = src;
	return ;
}

Class_C::~Class_C(void)
{
	return ;
}

Class_C&		Class_C::operator=(Class_C const &src)
{
	if (this != &src)
	{
	}
	return *this;
}
