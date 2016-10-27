/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 15:11:54 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/09 19:09:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class		Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		virtual ~Fixed(void);

		int 			getRawBits(void) const;
		void			setRawBits(int const raw);
		Fixed&			operator=(Fixed const &src);
	private:
		static const int		_bits;
		int						_nb;
};

#endif
