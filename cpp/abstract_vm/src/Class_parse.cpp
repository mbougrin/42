/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_parse.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 13:46:43 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/13 13:43:01 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_parse.hpp>
#include <Class_int8.hpp>
#include <Class_int16.hpp>
#include <Class_int32.hpp>
#include <Class_float.hpp>
#include <Class_double.hpp>
#include <stdio.h>
#include <string.h>
#include <climits>
#include <cfloat>
#include <stdlib.h>

eOperandType	Class_parse::ft_type(char *type)
{
	if (strcmp(type, "int8") == 0)
		return (static_cast<eOperandType>(0));
	else if (strcmp(type, "int16") == 0)
		return (static_cast<eOperandType>(1));
	else if (strcmp(type, "int32") == 0)
		return (static_cast<eOperandType>(2));
	else if (strcmp(type, "float") == 0)
		return (static_cast<eOperandType>(3));
	else if (strcmp(type, "double") == 0)
		return (static_cast<eOperandType>(4));
	return (static_cast<eOperandType>(-1));
}

void		Class_parse::ft_push(char *type, char *nb)
{
	std::string 	value(nb);
	int				i = 0;

	while (nb[i] != '\0')
	{
		if ((nb[i] < '0' || nb[i] > '9') && nb[i] != '-' \
			&& nb[i] != '.' && nb[i] != 'e' && nb[i] != '+' && nb[i] != '-')
			throw "Not a good number on command push ex: push int8(42)";
		i++;
	}
	IOperand const *str = createOperand(this->ft_type(type), value);
	this->_lst.push_front(str);
	this->setNb(this->getNb() + 1);
}

void		Class_parse::setNb(unsigned int nb) { this->_nb = nb; }

int			Class_parse::getNb(void) { return this->_nb; }

void		Class_parse::ft_pop(void)
{
	if (this->getNb() == 0)
		throw "Pop on empty stack";
	std::list<IOperand const *>::iterator it = this->_lst.begin();
	delete static_cast<IOperand const *>(*it);
	it = this->_lst.erase(it);
	this->setNb(this->getNb() - 1);
}

void		Class_parse::ft_assert(char *type, char *nb)
{
	if (this->getNb() == 0)
		throw "stack is empty";
	std::list<IOperand const *>::iterator it = this->_lst.begin();
	if (strcmp(dynamic_cast<IOperand const *>(*it)->toString().c_str(), nb) != 0
			|| this->ft_type(type) != dynamic_cast<IOperand const *>(*it)->getType())
		throw "assert is not equal";
}

void		Class_parse::ft_dump(void)
{
	for (std::list<IOperand const *>::iterator it = this->_lst.begin(); it != this->_lst.end(); it++)
		    std::cout << dynamic_cast<IOperand const *>(*it)->toString() << std::endl;
}

void		Class_parse::ft_add(void)
{
	if (this->getNb() >= 2)
	{
		std::list<IOperand const *>::iterator it1 = this->_lst.begin();
		std::list<IOperand const *>::iterator it = it1;
		it1++;
		IOperand const *res = **it + **it1;
		it = this->_lst.erase(it);
		it1 = this->_lst.erase(it1);
		this->_lst.push_front(res);
		this->setNb(this->getNb() - 1);
	}
	else
		throw "add is too few number";
}

void		Class_parse::ft_sub(void)
{
	if (this->getNb() >= 2)
	{
		std::list<IOperand const *>::iterator it1 = this->_lst.begin();
		std::list<IOperand const *>::iterator it = it1;
		it1++;
		IOperand const *res = **it - **it1;
		it = this->_lst.erase(it);
		it1 = this->_lst.erase(it1);
		this->_lst.push_front(res);
		this->setNb(this->getNb() - 1);
	}
	else
		throw "sub is too few number";
}

void		Class_parse::ft_mul(void)
{
	if (this->getNb() >= 2)
	{
		std::list<IOperand const *>::iterator it1 = this->_lst.begin();
		std::list<IOperand const *>::iterator it = it1;
		it1++;
		IOperand const *res = **it * **it1;
		it = this->_lst.erase(it);
		it1 = this->_lst.erase(it1);
		this->_lst.push_front(res);
		this->setNb(this->getNb() - 1);
	}
	else
		throw "mul is too few number";
}

void		Class_parse::ft_div(void)
{
	if (this->getNb() >= 2)
	{
		std::list<IOperand const *>::iterator it1 = this->_lst.begin();
		std::list<IOperand const *>::iterator it = it1;
		it1++;
		IOperand const *res = **it / **it1;
		it = this->_lst.erase(it);
		it1 = this->_lst.erase(it1);
		this->_lst.push_front(res);
		this->setNb(this->getNb() - 1);
	}
	else
		throw "mul is too few number";
}

void		Class_parse::ft_mod(void)
{
	if (this->getNb() >= 2)
	{
		std::list<IOperand const *>::iterator it1 = this->_lst.begin();
		std::list<IOperand const *>::iterator it = it1;
		it1++;
		IOperand const *res = **it % **it1;
		it = this->_lst.erase(it);
		it1 = this->_lst.erase(it1);
		this->_lst.push_front(res);
		this->setNb(this->getNb() - 1);
	}
	else
		throw "mul is too few number";
}

void		Class_parse::ft_print(void)
{
	std::list<IOperand const *>::iterator it = this->_lst.begin();

	if (this->getNb() > 0)
	{
		if (dynamic_cast<IOperand const *>(*it)->getPrecision() == 0)
		{
			if (atoi(dynamic_cast<IOperand const *>(*it)->toString().c_str()) >= 32 \
				&& atoi(dynamic_cast<IOperand const *>(*it)->toString().c_str()) <= 126)
			std::cout << static_cast<char>(atoi(dynamic_cast<IOperand const *>(*it)->toString().c_str())) << std::endl;
		}
		else
			throw "print is not a int8 number";
	}
	else
		throw "print on empty stack";
}

void		Class_parse::ft_parse(std::string const &line)
{
	char	*cmd = NULL;
	char	*arg = NULL;
	char	*type = NULL;
	char	*nb = NULL;

	if (this->getNb() == -1)
		throw "error command after exit";	
	if (line[0] == ';')
		return ;
	if (line == "exit")
	{
		this->setNb(-1);
		return ;
	}
	cmd = strtok(const_cast<char *>(line.c_str()), " ");
	if (cmd == NULL)
		return ;
	arg = strtok(NULL, " ");
	if (arg != NULL && arg[0] == ';')
		arg = NULL;
	if ((arg == NULL && strcmp(cmd, "push") == 0) || (arg == NULL && strcmp(cmd, "assert") == 0))
		throw "arg is a empty";
	if (arg == NULL)
	{
		if (strcmp(cmd, "pop") == 0)
			this->ft_pop();
		else if (strcmp(cmd, "dump") == 0)
			this->ft_dump();
		else if (strcmp(cmd, "add") == 0)
			this->ft_add();
		else if (strcmp(cmd, "sub") == 0)
			this->ft_sub();
		else if (strcmp(cmd, "mul") == 0)
			this->ft_mul();
		else if (strcmp(cmd, "div") == 0)
			this->ft_div();
		else if (strcmp(cmd, "mod") == 0)
			this->ft_mod();
		else if (strcmp(cmd, "print") == 0)
			this->ft_print();
		else
			throw "Bad command";
		return ;
	}
	else if (arg != NULL && strchr(arg, '(') != NULL && strchr(arg, ')') != NULL)
	{
		type = strtok(arg, "(");
		nb = strtok(NULL, ")");
		if (nb == NULL)
			throw "Not a good number ex: push int8(42)";
		if (strcmp(cmd, "push") == 0 && this->ft_type(type) != static_cast<eOperandType>(-1))
			return ft_push(type, nb);
		else if (strcmp(cmd, "assert") == 0 && this->ft_type(type) != static_cast<eOperandType>(-1))
			return ft_assert(type, nb);
		else
			throw "Not a good type try int8, int16, int32, float or double ex: push int8(42)";
	}
	if (arg != NULL && (strcmp(cmd, "push") == 0 || strcmp(cmd, "assert") == 0) \
			&& (strchr(arg, '(') == NULL || strchr(arg, ')') == NULL))
		throw "Not a good syntax ex: push int8(42)";
	else
		throw "Bad command";
}

IOperand const *Class_parse::createOperand(eOperandType type, std::string const &value) const
{
	return (this->*_ptr_function[type])(value);
}

Class_parse::Class_parse(void)
{
	this->_nb = 0;
	this->_ptr_function[0] = &Class_parse::createInt8;
	this->_ptr_function[1] = &Class_parse::createInt16;
	this->_ptr_function[2] = &Class_parse::createInt32;
	this->_ptr_function[3] = &Class_parse::createFloat;
	this->_ptr_function[4] = &Class_parse::createDouble;
	return ; 
}

IOperand const *Class_parse::createInt8(std::string const &value) const
{
	int nb = atoi(value.c_str());
	if (INT8_MIN <= nb && INT8_MAX >= nb)
	{
		std::stringstream out;
		out << nb;
		std::string const value1 = out.str();
		Class_int8	*str = new Class_int8(value1);
		return str;
	}
	else
		throw "INT8 number is not good";
	return NULL;
}

IOperand const *Class_parse::createInt16(std::string const &value) const
{
	long int nb = atol(value.c_str());
	if (INT16_MIN <= nb && INT16_MAX >= nb)
	{
		std::stringstream out;
		out << nb;
		std::string const value1 = out.str();
		Class_int16	*str = new Class_int16(value1);
		return str;
	}
	else
		throw "INT16 number is not good";
	return NULL;
}

IOperand const *Class_parse::createInt32(std::string const &value) const
{
	long int nb = atol(value.c_str());
	if (INT32_MIN <= nb && INT32_MAX >= nb)
	{
		std::stringstream out;
		out << nb;
		std::string const value1 = out.str();
		Class_int32	*str = new Class_int32(value1);
		return str;
	}
	else
		throw "INT32 number is not good";
	return NULL;
}

IOperand const *Class_parse::createFloat(std::string const &value) const
{
	double nb = atof(value.c_str());
	if (-FLT_MAX <= nb && FLT_MAX >= nb)
	{
		Class_float	*str = new Class_float(value);
		return str;
	}
	else
		throw "FLOAT number is not good";
	return NULL;
}

IOperand const *Class_parse::createDouble(std::string const &value) const
{
	double nb = atof(value.c_str());
	if (-DBL_MAX <= nb && DBL_MAX >= nb)
	{
		Class_double	*str = new Class_double(value);
		return str;
	}
	else
		throw "DOUBLE number is not good";
	return NULL;
}

Class_parse::Class_parse(Class_parse const &src) { if (this != &src) { } return ; }

Class_parse::~Class_parse(void) { return ; }

Class_parse&		Class_parse::operator=(Class_parse const &src) { if (this != &src) { } return *this; }
