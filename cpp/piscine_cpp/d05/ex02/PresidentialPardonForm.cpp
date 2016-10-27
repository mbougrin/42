/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 04:09:19 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 05:10:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) 
	: Form("PresidentialPardon", 25, 5), _target(name)
{
		return;
}

void				PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
		this->Form::execute(executor);
			std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
		return;
}

PresidentialPardonForm::PresidentialPardonForm(void) { return ; }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) { if (this != &src) { *this = src ; } return ; }

PresidentialPardonForm::~PresidentialPardonForm(void) { return ; }

PresidentialPardonForm&		PresidentialPardonForm::operator=(PresidentialPardonForm const &src) { if (this != &src) { } return *this; }
