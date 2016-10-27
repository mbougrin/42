/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 05:44:57 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/16 05:45:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int>		test(4);
	std::cout << "tab size : " << test.getSize() << std::endl;
	try {
		test[0] = 1;
		test[1] = 2;
		test[2] = 3;
		test[3] = 4;
		test[4] = 5;
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "test[0] : " << test[0] << std::endl;
		std::cout << "test[1] : " << test[1] << std::endl;
		std::cout << "test[2] : " << test[2] << std::endl;
		std::cout << "test[3] : " << test[3] << std::endl;
		std::cout << "test[4] : " << test[4] << std::endl;
	} catch ( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}

	Array<int>		a(5);
	std::cout << "[a]" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << i << " : " << a[i] << std::endl;

	std::cout << std::endl;

	Array<int>		aCopie(a);
	std::cout << "[aCopie]" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << i << " : " << aCopie[i] << std::endl;

	std::cout << std::endl;

	a[0] = 145;
	a[1] = 23;
	a[2] = 341;
	std::cout << "[a]" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << i << " : " << a[i] << std::endl;

	std::cout << std::endl;

	std::cout << "[aCopie]" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << i << " : " << aCopie[i] << std::endl;

	return 0;
}

