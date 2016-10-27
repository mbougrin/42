/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_double.hpp                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:17:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/06 17:49:14 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_DOUBLE_HPP
# define CLASS_DOUBLE_HPP

# include <IOperand.hpp>
# include <stdlib.h>
# include <cfloat>
# include <sstream>
# include <iostream>

class		Class_double : public IOperand
{
	public:
		Class_double(std::string const &nb);
		Class_double(Class_double const &src);
		virtual ~Class_double(void);

		int getPrecision(void) const;
		eOperandType getType(void) const;
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		std::string const & toString(void) const;
	

		Class_double&			operator=(Class_double const &src);
	private:
		Class_double(void);
		std::string	const	_value;
		eOperandType		_type;
};

#endif
