/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 00:25:35 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 00:44:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <time.h>

class		Pony
{
	public:
		Pony(void);
		Pony(std::string name);
		Pony(Pony const &src);
		virtual ~Pony(void);

		std::string		get_name(void);

		Pony&			operator=(Pony const &src);
	private:
		std::string		_name;
};

#endif
