/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 18:59:22 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 05:33:08 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class		Form
{
	public:
		class		GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class		GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class		NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		Form(void);
		Form(std::string const name, int grade, int gradeSigned);
		Form(Form const &src);
		~Form(void);

	virtual	void			execute(Bureaucrat const &executor) const;
		std::string		getName(void) const;
		int				getGradeSigned(void);
		int				getGradeExec(void) const;
		void			beSigned(Bureaucrat const &src);
		bool			getSigned(void) const;

		Form&			operator=(Form const &src);
	private:
		bool				_signed;
		const std::string	_name;
		int					_gradeExec;
		int					_gradeSigned;
};

std::ostream 	&operator<<(std::ostream &o, Form &rhs);

#else

class Form;

#endif
