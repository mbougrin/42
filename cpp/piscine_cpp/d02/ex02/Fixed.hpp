/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 15:11:54 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/09 22:54:51 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class		Fixed
{
	public:
		Fixed(void);
		Fixed(int nb);
		Fixed(float nb);
		Fixed(Fixed const &src);
		virtual ~Fixed(void);

		Fixed			operator*(Fixed const &src) const;
		Fixed			operator/(Fixed const &src) const;
		Fixed			operator+(Fixed const &src) const;
		Fixed			operator-(Fixed const &src) const;

		int				operator>(Fixed const &src) const;
		int				operator<(Fixed const &src) const;
		int				operator>=(Fixed const &src) const;
		int				operator<=(Fixed const &src) const;
		int				operator==(Fixed const &src) const;
		int				operator!=(Fixed const &src) const;

		int				toInt(void) const;
		float			toFloat(void) const;
		int 			getRawBits(void) const;
		void			setRawBits(int const raw);

		Fixed &					operator++( void );
		Fixed &					operator--( void );

	 	Fixed					operator++( int );
		Fixed					operator--( int );

		static Fixed &			max( Fixed & a, Fixed & b );
		static Fixed const &	max( Fixed const & a, Fixed const & b );
		static Fixed &			min( Fixed & a, Fixed & b);
		static Fixed const &	min( Fixed const & a, Fixed const & b );

		Fixed&			operator=(Fixed const &src);
	private:
		static const int		_bits;
		int						_nb;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &src);

#endif
