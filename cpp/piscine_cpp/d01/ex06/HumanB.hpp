/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 04:45:54 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/07 06:19:32 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"
#include <iostream>

class		HumanB
{
	public:
		HumanB(std::string str);
		~HumanB();
		void		setWeapon(Weapon& club);
		void		attack(void);
	private:
		std::string _name;
		Weapon *_type;
};

#endif
