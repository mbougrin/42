/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_B.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:14:01 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 20:50:18 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_B_HPP
# define CLASS_B_HPP

# include "Class_Base.hpp"

class			Class_B : public Class_Base
{
	public:
		Class_B(void);
		Class_B(Class_B const &src);
		virtual ~Class_B(void);

		Class_B&		operator=(Class_B const &src);
};

#endif
