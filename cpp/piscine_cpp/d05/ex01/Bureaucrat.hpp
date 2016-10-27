/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:26:07 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/13 22:25:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class		Bureaucrat
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
		Bureaucrat(void);
		Bureaucrat(std::string const name, int nb);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		void			signForm(Form &src);
		std::string		getName(void) const;
		int				getGrade(void) const;
		void			upgrade(void);
		void			downgrade(void);

		Bureaucrat&		operator=(Bureaucrat const &src);
	private:
		const std::string		_name;
		int						_grade;
};

std::ostream 	&operator<<(std::ostream &o, Bureaucrat &rhs);

#else

class Bureaucrat;

#endif
