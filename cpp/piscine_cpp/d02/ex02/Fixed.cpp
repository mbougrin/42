/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 15:11:53 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/09 23:00:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _nb(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int nb) : _nb(nb << Fixed::_bits)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float nb) : _nb((int)roundf(nb * (1 << (Fixed::_bits))))
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

float		Fixed::toFloat(void) const
{
	return ((float)this->_nb / (1 << (Fixed::_bits)));
}

int			Fixed::toInt(void) const
{
	return (this->_nb) >> Fixed::_bits;
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_nb = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return (o);
}

int				Fixed::operator>(Fixed const &src) const
{
	if (src.getRawBits() > this->getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator<(Fixed const &src) const
{
	if (src.getRawBits() < this->getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator>=(Fixed const &src) const
{
	if (src.getRawBits() >= this->getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator<=(Fixed const &src) const
{
	if (src.getRawBits() <= this->getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator==(Fixed const &src) const
{
	if (src.getRawBits() == this->getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator!=(Fixed const &src) const
{
	if (src.getRawBits() != this->getRawBits())
		return (1);
	return (0);
}

Fixed			Fixed::operator*(Fixed const &src) const
{
	Fixed		ret(src.toFloat() * this->toFloat());
	return (ret);
}

Fixed			Fixed::operator/(Fixed const &src) const
{
	Fixed		ret(src.toFloat() / this->toFloat());
	return (ret);
}

Fixed			Fixed::operator+(Fixed const &src) const
{
	Fixed		ret(src.toFloat() + this->toFloat());
	return (ret);
}

Fixed			Fixed::operator-(Fixed const &src) const
{
	Fixed		ret(src.toFloat() - this->toFloat());
	return (ret);
}

Fixed		&Fixed::operator++(void)
{
	this->_nb += 1;
	return (*this);
}

Fixed &			Fixed::operator--( void )
{
	this->_nb -= 1;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed	res(*this);
	++(*this);
	return (res);
}

Fixed			Fixed::operator--(int)
{
	Fixed	res(*this);
	--(*this);
	return (res);
}

Fixed &			Fixed::max( Fixed & a, Fixed & b )
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const &	Fixed::max( Fixed const & a, Fixed const & b )
{
	if (a < b)
		return (a);
	return (b);
}


Fixed &			Fixed::min( Fixed & a, Fixed & b )
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const &	Fixed::min( Fixed const & a, Fixed const & b )
{
	if (a > b)
		return (a);
	return (b);
}
