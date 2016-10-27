/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_int8.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:17:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/06 16:01:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_INT8_HPP
# define CLASS_INT8_HPP

# include <IOperand.hpp>
# include <stdlib.h>
# include <sstream>
# include <iostream>

class		Class_int8 : public IOperand
{
	public:
		Class_int8(std::string const &nb);
		Class_int8(Class_int8 const &src);
		virtual ~Class_int8(void);

		int getPrecision(void) const;
		eOperandType getType(void) const;
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		std::string const & toString(void) const;
	

		Class_int8&			operator=(Class_int8 const &src);
	private:
		Class_int8(void);
		std::string	const	_value;
		eOperandType		_type;
};

#endif
