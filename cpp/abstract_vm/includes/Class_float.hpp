/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_float.hpp                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:17:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/06 17:25:25 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_FLOAT_HPP
# define CLASS_FLOAT_HPP

# include <IOperand.hpp>
# include <stdlib.h>
# include <cfloat>
# include <sstream>
# include <iostream>

class		Class_float : public IOperand
{
	public:
		Class_float(std::string const &nb);
		Class_float(Class_float const &src);
		virtual ~Class_float(void);

		int getPrecision(void) const;
		eOperandType getType(void) const;
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		std::string const & toString(void) const;
	

		Class_float&			operator=(Class_float const &src);
	private:
		Class_float(void);
		std::string	const	_value;
		eOperandType		_type;
};

#endif
