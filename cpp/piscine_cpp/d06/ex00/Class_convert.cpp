/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_convert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:43:27 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/15 17:19:59 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class_convert.hpp"
#include <cstring>

void			Class_convert::convert_char(double c)
{
	if (c >= CHAR_MIN && CHAR_MAX >= c)
	{
//		if (c == 0)
//			std::cout << "char: '\\0'" << std::endl;
		if (c == 7)
			std::cout << "char: '\\a'" << std::endl;
		else if (c == 8)
			std::cout << "char: '\\b'" << std::endl;
		else if (c == 9)
			std::cout << "char: '\\t'" << std::endl;
		else if (c == 10)
			std::cout << "char: '\\n'" << std::endl;
		else if (c == 11)
			std::cout << "char: '\\v'" << std::endl;
		else if (c == 12)
			std::cout << "char: '\\f'" << std::endl;
		else if (c == 13)
			std::cout << "char: '\\r'" << std::endl;
		else if (c == 33)
			std::cout << "char: '\\e'" << std::endl;
		else if (c >= 32 && c <= 126)
			std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void			Class_convert::convert_int(double c)
{
	if (c >= INT_MIN && INT_MAX >= c)
		std::cout << "int: " << static_cast<int>(c) << "" << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void			Class_convert::convert_float(double c, char *str)
{
	int		i = 0;
	int		count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	
	if (c >= -FLT_MAX && FLT_MAX >= c)
	{
		if (count == 0 && strlen(str) < 7)
			std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	}
	else
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
}

void			Class_convert::convert_double(double c, char *str)
{
	int		i = 0;
	int		count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count = 1;
		i++;
	}

	if (c >= -DBL_MAX && DBL_MAX >= c)
	{
		if (count == 0 && strlen(str) < 7)
			std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(c) << std::endl;
	}
	else
		std::cout << "double: " << static_cast<double>(c) << std::endl;
}

Class_convert::Class_convert(void)
{
	return ;
}

Class_convert::Class_convert(Class_convert const &src)
{
	*this = src;
	return ;
}

Class_convert::~Class_convert(void)
{
	return ;
}

Class_convert&		Class_convert::operator=(Class_convert const &src)
{
	if (this != &src)
	{

	}
	return *this;
}
