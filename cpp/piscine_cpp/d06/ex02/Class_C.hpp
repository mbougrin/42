/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_C.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:13:57 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 20:33:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_C_HPP
# define CLASS_C_HPP

# include "Class_Base.hpp"

class			Class_C : public Class_Base
{
	public:
		Class_C(void);
		Class_C(Class_C const &src);
		virtual ~Class_C(void);

		Class_C&		operator=(Class_C const &src);
};

#endif
