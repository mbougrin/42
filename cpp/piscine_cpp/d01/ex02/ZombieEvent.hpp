/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 02:11:40 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 05:18:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include "Zombie.hpp"

class		ZombieEvent
{
	public:
		ZombieEvent(void);
		ZombieEvent(ZombieEvent const &src);
		virtual ~ZombieEvent(void);

		std::string				setZombieType(void);
		Zombie					*newZombie(std::string name);

		ZombieEvent&			operator=(ZombieEvent const &src);
	private:
};

#endif
