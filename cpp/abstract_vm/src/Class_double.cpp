/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_double.cpp                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:17:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/11 15:08:08 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_double.hpp>
#include <Class_parse.hpp>
#include <math.h>

int					Class_double::getPrecision(void) const 
{
	return static_cast<int>(this->_type);
}

std::string const 	&Class_double::toString(void) const { return this->_value; }

eOperandType		Class_double::getType(void) const { return this->_type; }

Class_double::Class_double(void) { return ; }

Class_double::Class_double(std::string const &nb) 
	: _value(nb), 
	_type(static_cast<eOperandType>(4)) 
{
	return ;
}

Class_double::Class_double(Class_double const &src) { if (this != &src) { } return ; }

Class_double::~Class_double(void) { return ; }

IOperand const 	*Class_double::operator+(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	double nb = atof(rhs.toString().c_str()) + atof(this->toString().c_str());
	if (-DBL_MAX <= nb && DBL_MAX >= nb)
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
		throw "DOUBLE add number is not good";
	return NULL;
}

IOperand const 	*Class_double::operator-(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	double nb = atof(rhs.toString().c_str()) - atof(this->toString().c_str());
	if (-DBL_MAX <= nb && DBL_MAX >= nb)
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
		throw "DOUBLE add number is not good";
	return NULL;
}

IOperand const 	*Class_double::operator*(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	double nb = atof(rhs.toString().c_str()) * atof(this->toString().c_str());
	if (-DBL_MAX <= nb && DBL_MAX >= nb)
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
		throw "DOUBLE add number is not good";
	return NULL;
}

IOperand const 	*Class_double::operator/(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atof(this->toString().c_str()) == 0)
		throw "DOUBLE division by zero";
	double nb = atof(rhs.toString().c_str()) / atof(this->toString().c_str());
	if (-DBL_MAX <= nb && DBL_MAX >= nb)
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
		throw "DOUBLE add number is not good";
	return NULL;
}

IOperand const 	*Class_double::operator%(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atof(this->toString().c_str()) == 0)
		throw "DOUBLE modulo by zero";
	double nb = fmod(atof(rhs.toString().c_str()), atof(this->toString().c_str()));
	if ((-DBL_MAX <= nb && DBL_MAX >= nb))
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
		throw "DOUBLE add number is not good";
	return NULL;
}

Class_double&		Class_double::operator=(Class_double const &src) { if (this != &src) { } return *this; }
