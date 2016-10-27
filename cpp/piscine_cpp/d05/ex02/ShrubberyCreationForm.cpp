/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 04:09:03 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 05:24:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: Form("Shrubbery", 145, 137), _target(name)
{
	return ;
}

void				ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->Form::execute(executor);
	std::ofstream	out_file((this->_target + "_shrubbery").c_str());
	out_file << "                      / / /\n                   /        /  /     //    /\n                /                 /         /  /\n                                /\n                               /                //\n               /          /            /              /\n               /            '/,        /               /\n               /              'b      *\n                /              '$    //                //\n               /    /           $:   /:               /\n             //      /  //      */  @):        /   / /\n                          /     :@,@):   ,/**:'   /\n              /      /,         :@@*: //**'      /   /\n                       '/o/    /:(@'/@*\"'  /\n               /  /       'bq,//:,@@*'   ,*      /  /\n                          ,p$q8,:@)'  /p*'      /\n                   /     '  / '@@Pp@@*'    /  /\n                    /  / //    Y7'.'     /  /\n                              :@):.\n                             .:@:'.\n                           .::(@:.      -Sam Blumenstein-" << std::endl;
	out_file.close();
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(void) { return ; }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) { if (this != &src) { *this = src ; } return ; }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { return ; }

ShrubberyCreationForm&		ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) { if (this != &src) { } return *this; }
