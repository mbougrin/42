/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 00:48:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 01:55:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class		FragTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		virtual ~FragTrap(void);

		void				rangedAttack(std::string const &target);
		void				meleeAttack(std::string const &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				vaulthunter_dot_exe(std::string const &target);

		std::string			get_name(void);
		int					get_ranged_damage(void);
		int					get_melee_damage(void);
		int					get_level(void);

		FragTrap&			operator=(FragTrap const &src);
	private:
		int					_hit_points;
		const int			_max_hit_points;
		int					_energy_points;
		const int			_max_energy_points;
		int					_level;
		const int			_melee_attack_damage;
		const int			_ranged_attack_damage;
		const int			_armor;
		std::string			_name;
};

#endif
