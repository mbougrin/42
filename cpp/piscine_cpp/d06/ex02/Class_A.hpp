/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_A.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:14:03 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 20:47:18 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_A_HPP
# define CLASS_A_HPP

# include "Class_Base.hpp"

class			Class_A : public Class_Base
{
	public:
		Class_A(void);
		Class_A(Class_A const &src);
		virtual ~Class_A(void);

		Class_A&		operator=(Class_A const &src);
};

#endif
