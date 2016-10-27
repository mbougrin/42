/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 04:09:10 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 05:10:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) 
	: Form("Robotomy Request", 72, 45), _target(name), _halftime(true){
		return;
}

void				RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->Form::execute(executor);
	if (this->_halftime) {
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << this->_target << " robotomized failure." << std::endl;
	}
	this->_halftime = !this->_halftime;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(void) { return ; }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) { if (this != &src) { *this = src ; } return ; }

RobotomyRequestForm::~RobotomyRequestForm(void) { return ; }

RobotomyRequestForm&		RobotomyRequestForm::operator=(RobotomyRequestForm const &src) { if (this != &src) { } return *this; }
