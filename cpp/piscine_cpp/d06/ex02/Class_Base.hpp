/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_Base.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 20:14:03 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/13 21:31:28 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BASE_HPP
# define CLASS_BASE_HPP

class			Class_Base
{
	public:
		Class_Base(void);
		Class_Base(Class_Base const &src);
		virtual ~Class_Base(void);

		Class_Base&		operator=(Class_Base const &src);
};

#endif
