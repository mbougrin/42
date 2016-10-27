/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_int16.cpp                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 00:51:24 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/11 15:15:17 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_int16.hpp>
#include <Class_parse.hpp>

int					Class_int16::getPrecision(void) const 
{
	return static_cast<int>(this->_type);
}

std::string const 	&Class_int16::toString(void) const { return this->_value; }

eOperandType		Class_int16::getType(void) const { return this->_type; }

Class_int16::Class_int16(void) { return ; }

Class_int16::Class_int16(std::string const &nb) 
	: _value(nb), 
	_type(static_cast<eOperandType>(1)) 
{
	return ;
}

Class_int16::Class_int16(Class_int16 const &src) { if (this != &src) { } return ; }

Class_int16::~Class_int16(void) { return ; }

IOperand const 	*Class_int16::operator+(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) + atol(this->toString().c_str());
	if (INT16_MIN <= nb && INT16_MAX >= nb)
	{
		std::stringstream out;
		out << nb;
		std::string const value = out.str();
		if (rhs.getPrecision() > this->getPrecision())
		{
			IOperand const *ret = parse->createOperand(rhs.getType(), value);
			delete parse;
			return ret;
		}
		else
		{
			IOperand const *ret = parse->createOperand(this->getType(), value);
			delete parse;
			return ret;
		}
	}
	else
		throw "INT16 add number is not good";
	return NULL;
}

IOperand const 	*Class_int16::operator-(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) - atol(this->toString().c_str());
	if (INT16_MIN <= nb && INT16_MAX >= nb)
	{
		std::stringstream out;
		out << nb;
		std::string const value = out.str();
		if (rhs.getPrecision() > this->getPrecision())
		{
			IOperand const *ret = parse->createOperand(rhs.getType(), value);
			delete parse;
			return ret;
		}
		else
		{
			IOperand const *ret = parse->createOperand(this->getType(), value);
			delete parse;
			return ret;
		}
	}
	else
		throw "INT16 add number is not good";
	return NULL;
}

IOperand const 	*Class_int16::operator*(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) * atol(this->toString().c_str());
	if (INT16_MIN <= nb && INT16_MAX >= nb)
	{
		std::stringstream out;
		out << nb;
		std::string const value = out.str();
		if (rhs.getPrecision() > this->getPrecision())
		{
			IOperand const *ret = parse->createOperand(rhs.getType(), value);
			delete parse;
			return ret;
		}
		else
		{
			IOperand const *ret = parse->createOperand(this->getType(), value);
			delete parse;
			return ret;
		}
	}
	else
		throw "INT16 add number is not good";
	return NULL;
}

IOperand const 	*Class_int16::operator/(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atoi(this->toString().c_str()) == 0)
		throw "INT16 division by zero";
	long int nb = atol(rhs.toString().c_str()) / atol(this->toString().c_str());
	if (INT16_MIN <= nb && INT16_MAX >= nb)
	{
		std::stringstream out;
		out << nb;
		std::string const value = out.str();
		if (rhs.getPrecision() > this->getPrecision())
		{
			IOperand const *ret = parse->createOperand(rhs.getType(), value);
			delete parse;
			return ret;
		}
		else
		{
			IOperand const *ret = parse->createOperand(this->getType(), value);
			delete parse;
			return ret;
		}
	}
	else
		throw "INT16 add number is not good";
	return NULL;
}

IOperand const 	*Class_int16::operator%(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atoi(this->toString().c_str()) == 0)
		throw "INT16 modulo by zero";
	long int nb = atol(rhs.toString().c_str()) % atol(this->toString().c_str());
	if (INT16_MIN <= nb && INT16_MAX >= nb)
	{
		std::stringstream out;
		out << nb;
		std::string const value = out.str();
		if (rhs.getPrecision() > this->getPrecision())
		{
			IOperand const *ret = parse->createOperand(rhs.getType(), value);
			delete parse;
			return ret;
		}
		else
		{
			IOperand const *ret = parse->createOperand(this->getType(), value);
			delete parse;
			return ret;
		}
	}
	else
		throw "INT16 add number is not good";
	return NULL;
}

Class_int16&	Class_int16::operator=(Class_int16 const &src) { if (this != &src) { } return *this; }
