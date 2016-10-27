/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_float.cpp                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:17:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/11 15:10:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_float.hpp>
#include <Class_parse.hpp>
#include <math.h>

int					Class_float::getPrecision(void) const 
{
	return static_cast<int>(this->_type);
}

std::string const 	&Class_float::toString(void) const { return this->_value; }

eOperandType		Class_float::getType(void) const { return this->_type; }

Class_float::Class_float(void) { return ; }

Class_float::Class_float(std::string const &nb) 
	: _value(nb), 
	_type(static_cast<eOperandType>(3)) 
{
	return ;
}

Class_float::Class_float(Class_float const &src) { if (this != &src) { } return ; }

Class_float::~Class_float(void) { return ; }

IOperand const 	*Class_float::operator+(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	double nb = atof(rhs.toString().c_str()) + atof(this->toString().c_str());
	if (-FLT_MAX <= nb && FLT_MAX >= nb)
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
		throw "FLOAT add number is not good";
	return NULL;
}

IOperand const 	*Class_float::operator-(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	double nb = atof(rhs.toString().c_str()) - atof(this->toString().c_str());
	if (-FLT_MAX <= nb && FLT_MAX >= nb)
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
		throw "FLOAT add number is not good";
	return NULL;
}

IOperand const 	*Class_float::operator*(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	double nb = atof(rhs.toString().c_str()) * atof(this->toString().c_str());
	if (-FLT_MAX <= nb && FLT_MAX >= nb)
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
		throw "FLOAT add number is not good";
	return NULL;
}

IOperand const 	*Class_float::operator/(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atof(this->toString().c_str()) == 0)
		throw "FLOAT division by zero";
	double nb = atof(rhs.toString().c_str()) / atof(this->toString().c_str());
	if (-FLT_MAX <= nb && FLT_MAX >= nb)
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
		throw "FLOAT add number is not good";
	return NULL;
}

IOperand const 	*Class_float::operator%(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atof(this->toString().c_str()) == 0)
		throw "FLOAT modulo by zero";
	double nb = fmod(atof(rhs.toString().c_str()), atof(this->toString().c_str()));
	if ((-FLT_MAX <= nb && FLT_MAX >= nb))
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
		throw "FLOAT add number is not good";
	return NULL;
}

Class_float&		Class_float::operator=(Class_float const &src) { if (this != &src) { } return *this; }
