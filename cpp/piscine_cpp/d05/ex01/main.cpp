/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:26:00 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 00:23:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int				main(void)
{
	try
	{
		Bureaucrat test1("test1", 110);
		Bureaucrat test3("test3", 50);
		Form test2("test2", 100, 100);
		std::cout << test1 << std::endl;
		std::cout << test3 << std::endl;

		std::cout << test2 << std::endl;
		test1.signForm(test2);
		test3.signForm(test2);
		std::cout << test2 << std::endl;
		std::cout << test3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
