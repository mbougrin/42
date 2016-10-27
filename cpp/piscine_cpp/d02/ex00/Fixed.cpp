/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 15:11:53 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/09 19:09:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _nb(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &src)
	{
		*this = src;
	}
	return ;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; return ; }

Fixed&		Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->setRawBits(src.getRawBits());
	}
	return (*this);
}

int 		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb);
}

void		Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}
