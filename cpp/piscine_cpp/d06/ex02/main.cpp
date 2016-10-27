/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:24:35 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 21:28:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Class_Base*	 generate(void)
{
	static	int nb_tmp;
	int		nb = rand() % 3 + 1;

	nb_tmp = nb;
	if (nb == nb_tmp)
		nb = rand() % 3 + 1;
	if (nb == 1)
	{
		Class_A*	A = new Class_A();
		return (A);
	}
	else if (nb == 2)
	{
		Class_B*	B = new Class_B();
		return (B);
	}
	else if (nb == 3)
	{
		Class_C*	C = new Class_C();
		return (C);
	}
	return (NULL); 
}

void 	identify_from_pointer(Class_Base *p)
{
	Class_A *testA = dynamic_cast<Class_A *>(p);
	if (testA != NULL)
	{
		std::cout << "Class_A identify pointer" << std::endl;
		return ;
	}
	Class_B *testB = dynamic_cast<Class_B *>(p);
	if (testB != NULL)
	{
		std::cout << "Class_B identify pointer" << std::endl;
		return ;
	}
	Class_C *testC = dynamic_cast<Class_C *>(p);
	if (testC != NULL)
	{
		std::cout << "Class_C identify pointer" << std::endl;
		return ;
	}
}

void 	identify_from_reference(Class_Base &p)
{
	Class_A *testA = dynamic_cast<Class_A *>(&p);
	if (testA != NULL)
	{
		std::cout << "Class_A identify reference" << std::endl;
		return ;
	}
	Class_B *testB = dynamic_cast<Class_B *>(&p);
	if (testB != NULL)
	{
		std::cout << "Class_B identify reference" << std::endl;
		return ;
	}
	Class_C *testC = dynamic_cast<Class_C *>(&p);
	if (testC != NULL)
	{
		std::cout << "Class_C identify reference" << std::endl;
		return ;
	}
}

int			main(void)
{
	srand(time(NULL));
	identify_from_pointer(generate());
	Class_Base* tmp = generate();
	Class_Base& tmp1 = *tmp;
	identify_from_reference(tmp1);
	return (0);
}
