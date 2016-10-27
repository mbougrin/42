/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_int32.hpp                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:17:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/06 16:29:30 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_INT32_HPP
# define CLASS_INT32_HPP

# include <IOperand.hpp>
# include <stdlib.h>
# include <sstream>
# include <iostream>

class		Class_int32 : public IOperand
{
	public:
		Class_int32(std::string const &nb);
		Class_int32(Class_int32 const &src);
		virtual ~Class_int32(void);

		int getPrecision(void) const;
		eOperandType getType(void) const;
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		std::string const & toString(void) const;
	

		Class_int32&			operator=(Class_int32 const &src);
	private:
		Class_int32(void);
		std::string	const	_value;
		eOperandType		_type;
};

#endif
