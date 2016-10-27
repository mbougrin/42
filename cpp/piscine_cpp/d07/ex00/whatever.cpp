/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 14:29:42 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/14 16:14:50 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename FIRST>

void		swap(FIRST &a, FIRST &b)
{
	FIRST c(a);

	a = b;
	b = c;
}

template<typename FIRST>

FIRST		max(FIRST a, FIRST b)
{
	return (a > b ? a : b);
}

template<typename FIRST>

FIRST		min(FIRST a, FIRST b)
{
	return (a < b ? a : b);
}

int 	main( void ) 
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
