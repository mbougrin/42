/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 04:09:10 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/14 05:30:37 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


# include <iostream>
# include <fstream>
# include "Form.hpp"

class		RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm(void);

		void							execute(Bureaucrat const &executor) const;

		RobotomyRequestForm&			operator=(RobotomyRequestForm const &src);
	private:
		std::string			_target;
		mutable bool		_halftime;

};

#endif
