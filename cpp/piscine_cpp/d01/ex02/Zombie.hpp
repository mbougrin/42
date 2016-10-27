/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 02:11:32 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 05:22:57 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class		Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name, std::string type);
		Zombie(Zombie const &src);
		virtual ~Zombie(void);

		void			announce(void);

		Zombie&			operator=(Zombie const &src);
	private:
		std::string		_name;
		std::string		_type;
};

#endif
