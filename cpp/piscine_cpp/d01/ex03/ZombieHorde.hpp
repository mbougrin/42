/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 02:11:40 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 08:14:08 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include "Zombie.hpp"

class		ZombieHorde
{
	public:
		ZombieHorde(void);
		ZombieHorde(int nb);
		ZombieHorde(ZombieHorde const &src);
		virtual ~ZombieHorde(void);

		void					announce(void);
		std::string				setZombieType(void);
		Zombie					*newZombie(std::string name);

		ZombieHorde&			operator=(ZombieHorde const &src);
	private:
		int						_nb;
		Zombie					**_tab;
};

#endif
