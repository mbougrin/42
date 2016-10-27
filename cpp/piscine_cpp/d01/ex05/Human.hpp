/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 04:42:35 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 04:42:37 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include "Brain.hpp" 

class		Human
{
	public:
		Human();
		~Human();
		std::string identify(void) const;
		Brain		&getBrain(void);
	private:
		Brain const &_brain;
};

#endif
