/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 04:46:02 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 05:41:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class		HumanA
{
	public:
		HumanA(std::string name, Weapon& club);
		~HumanA();
		void	attack(void);
		Weapon	&getType(void) const;
	private:
		std::string	_name;
		Weapon	const &_type;
};

#endif
