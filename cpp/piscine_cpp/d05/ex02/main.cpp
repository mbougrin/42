/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:26:00 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 05:40:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main( void )
{
	Bureaucrat	t("mbougrin", 1);
	std::cout << t << std::endl;

	ShrubberyCreationForm	scf(t.getName());
	t.signForm(scf);
	t.executeForm(scf);

	RobotomyRequestForm		rrf(t.getName());
	t.signForm(rrf);
	t.executeForm(rrf);

	PresidentialPardonForm	ppf(t.getName());
	t.signForm(ppf);
	t.executeForm(ppf);
	return (0);
}
