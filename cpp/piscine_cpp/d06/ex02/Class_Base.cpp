/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_Base.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:13:38 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 20:40:15 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Class_Base::Class_Base(void)
{
	return ;
}

Class_Base::Class_Base(Class_Base const &src)
{
	*this = src;
	return ;
}

Class_Base::~Class_Base(void)
{
	return ;
}

Class_Base&		Class_Base::operator=(Class_Base const &src)
{
	if (this != &src)
	{
	}
	return *this;
}
