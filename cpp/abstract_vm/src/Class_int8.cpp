/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_int8.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:17:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/11 15:19:59 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_int8.hpp>
#include <Class_parse.hpp>

int					Class_int8::getPrecision(void) const 
{
	return static_cast<int>(this->_type);
}

std::string const 	&Class_int8::toString(void) const { return this->_value; }

eOperandType		Class_int8::getType(void) const { return this->_type; }

Class_int8::Class_int8(void) { return ; }

	Class_int8::Class_int8(std::string const &nb) 
: _value(nb), 
	_type(static_cast<eOperandType>(0)) 
{
	return ;
}

Class_int8::Class_int8(Class_int8 const &src) { if (this != &src) { } return ; }

Class_int8::~Class_int8(void) { return ; }

IOperand const 	*Class_int8::operator+(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) + atol(this->toString().c_str());
	if (INT8_MIN <= nb && INT8_MAX >= nb)
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
		throw "INT8 add number is not good";
	return NULL;
}

IOperand const 	*Class_int8::operator-(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) - atol(this->toString().c_str());
	if (INT8_MIN <= nb && INT8_MAX >= nb)
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
		throw "INT8 add number is not good";
	return NULL;
}

IOperand const 	*Class_int8::operator*(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	long int nb = atol(rhs.toString().c_str()) * atol(this->toString().c_str());
	if (INT8_MIN <= nb && INT8_MAX >= nb)
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
		throw "INT8 add number is not good";
	return NULL;
}

IOperand const 	*Class_int8::operator/(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atol(this->toString().c_str()) == 0)
		throw "INT8 division by zero";
	long int nb = atol(rhs.toString().c_str()) / atoi(this->toString().c_str());
	if (INT8_MIN <= nb && INT8_MAX >= nb)
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
		throw "INT8 add number is not good";
	return NULL;
}

IOperand const 	*Class_int8::operator%(IOperand const & rhs) const
{
	Class_parse		*parse = new Class_parse();
	if (atol(this->toString().c_str()) == 0)
		throw "INT8 modulo by zero";
	long int nb = atol(rhs.toString().c_str()) % atol(this->toString().c_str());
	if (INT8_MIN <= nb && INT8_MAX >= nb)
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
		throw "INT8 add number is not good";
	return NULL;
}

Class_int8&		Class_int8::operator=(Class_int8 const &src) { if (this != &src) { } return *this; }
