/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 02:08:20 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 02:11:38 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int				main(void)
{
	std::string 	brain = "HI THIS IS BRAIN";
	std::string*	ptr = &brain;
	std::string&	def = brain;
	
	std::cout << *ptr << std::endl;
	std::cout << def << std::endl;
	return (0);
}
