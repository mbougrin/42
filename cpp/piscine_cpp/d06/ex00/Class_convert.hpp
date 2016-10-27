/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_convert.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:43:24 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 17:39:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONVERT_HPP
# define CLASS_CONVERT_HPP

# include "main.hpp"

class		Class_convert
{
	public:
		Class_convert(void);
		Class_convert(Class_convert const &src);
		~Class_convert(void);

		void			convert_char(double c);
		void			convert_int(double c);
		void			convert_float(double c, char *str);
		void			convert_double(double c, char *str);

		Class_convert&		operator=(Class_convert const &src);
};

#endif
