/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 15:11:54 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/09 19:32:17 by mbougrin         ###   ########.fr       */
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

		int				toInt(void) const;
		float			toFloat(void) const;
		int 			getRawBits(void) const;
		void			setRawBits(int const raw);
		Fixed&			operator=(Fixed const &src);
	private:
		static const int		_bits;
		int						_nb;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &src);

#endif
