/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:32:33 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/03 14:56:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <iostream>

enum eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

class IOperand
{
	public:
		virtual int getPrecision( void ) const = 0;
		virtual eOperandType getType( void ) const = 0;
		virtual IOperand const * operator+( IOperand const & rhs ) const = 0;
		virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
		virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
		virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
		virtual IOperand const * operator%( IOperand const & rhs ) const = 0;
		virtual std::string const & toString( void ) const = 0;
		virtual ~IOperand( void ) {}
};

#endif
