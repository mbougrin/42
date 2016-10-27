/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_int32.cpp                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:17:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/11 15:17:29 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_int32.hpp>
#include <Class_parse.hpp>

int					Class_int32::getPrecision(void) const 
{
	return static_cast<int>(this->_type);
}

std::string const 	&Class_int32::toString(void) const { return this->_value; }

eOperandType		Class_int32::getType(void) const { return this->_type; }

Class_int32::Class_int32(void) { return ; }

Class_int32::Class_int32(std::string const &nb) 
	: _value(nb), 
	_type(static_cast<eOperandType>(2)) 
{
	return ;
}

Class_int32::Class_int32(Class_int32 const &src) { if (this != &src) { } return ; }

Class_int32::~Class_int32(void) { return ; }

IOperand const 	*Class_int32::operator+(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) + atol(this->toString().c_str());
	if (INT32_MIN <= nb && INT32_MAX >= nb)
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
		throw "INT32 add number is not good";
	return NULL;
}

IOperand const 	*Class_int32::operator-(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) - atol(this->toString().c_str());
	if (INT32_MIN <= nb && INT32_MAX >= nb)
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
		throw "INT32 add number is not good";
	return NULL;
}

IOperand const 	*Class_int32::operator*(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) * atol(this->toString().c_str());
	if (INT32_MIN <= nb && INT32_MAX >= nb)
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
		throw "INT32 add number is not good";
	return NULL;
}

IOperand const 	*Class_int32::operator/(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atoi(this->toString().c_str()) == 0)
		throw "INT32 division by zero";
	long int nb = atol(rhs.toString().c_str()) / atol(this->toString().c_str());
	if (INT32_MIN <= nb && INT32_MAX >= nb)
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
		throw "INT32 add number is not good";
	return NULL;
}

IOperand const 	*Class_int32::operator%(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atoi(this->toString().c_str()) == 0)
		throw "INT32 modulo by zero";
	long int nb = atol(rhs.toString().c_str()) % atol(this->toString().c_str());
	if (INT32_MIN <= nb && INT32_MAX >= nb)
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
		throw "INT32 add number is not good";
	return NULL;
}

Class_int32&		Class_int32::operator=(Class_int32 const &src) { if (this != &src) { } return *this; }
