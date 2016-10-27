/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 18:59:21 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 01:15:29 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* 		Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* 		Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

std::ostream		&operator<<(std::ostream &o, Form &rhs)
{
	o << rhs.getName() << " was ";
	if (rhs.getSigned() == false)
		o << "not ";
	o << "signed. ";
	o << "grade Execute:" << rhs.getGradeExec() << ". ";
	o << "grade Sign:" << rhs.getGradeSigned() << ".";
   	return o;	
}

void				Form::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() <= _gradeSigned || src.getGrade() <= _gradeExec)
		_signed = true;
	else
		throw GradeTooLowException();
}

bool				Form::getSigned(void) { return (_signed); }

std::string			Form::getName(void) const { return this->_name; }

Form::Form(std::string const name, int grade, int gradeSigned)
	: _signed(false), _name(name), _gradeExec(grade), _gradeSigned(gradeSigned)
{
	if (grade < 1 || gradeSigned < 1)
		throw Form::GradeTooLowException();
	else if (grade > 150 || gradeSigned > 150)
		throw Form::GradeTooHighException();
	return ;
}

Form::Form(void)
{
	return ;
}

Form::Form(Form const &src)
{
	if (this != &src)
		*this = src;
	return ;
}

int			Form::getGradeExec(void) { return (_gradeExec); }

int			Form::getGradeSigned(void) { return (_gradeSigned); }

Form&		Form::operator=(Form const &src)
{
	if (this->_gradeExec < 1)
		throw Form::GradeTooLowException();
	else if (this->_gradeExec > 150)
		throw Form::GradeTooHighException();
	if (this != &src)
	{
//		this->_gradeExec = src.getGradeExec();
//		this->_gradeSigned = src.getGradeSigned();
	}
	return *this;
}

Form::~Form(void)
{
	return ;
}
