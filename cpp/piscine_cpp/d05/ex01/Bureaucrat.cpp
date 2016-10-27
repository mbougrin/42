/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:26:04 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 02:35:05 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* 		Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* 		Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

void				Bureaucrat::upgrade(void)
{
	this->_grade--;
	if (this->_grade < 0)
		throw Bureaucrat::GradeTooLowException();
}

void			Bureaucrat::signForm(Form &src) {
	try {
		src.beSigned(*this);
		std::cout << this->_name << " signs " << src.getName() << std::endl;
	} catch (std::exception & e) {
		std::cout << this->_name << " cannot sign " << src.getName();
		std::cout << " because " << e.what() << std::endl;
	}
	return;
}

void				Bureaucrat::downgrade(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream		&operator<<(std::ostream &o, Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
   return o;	
}

int					Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::string			Bureaucrat::getName(void) const
{
	return this->_name;
}

Bureaucrat::Bureaucrat(std::string const name, int nb)
	: _name(name), _grade(nb)
{
	if (nb < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (nb > 150)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

Bureaucrat::Bureaucrat(void)
{
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	if (this != &src)
		*this = src;
	return ;
}

Bureaucrat&		Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	if (this != &src)
		this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}
