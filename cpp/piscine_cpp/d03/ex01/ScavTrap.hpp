/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 00:48:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 02:46:13 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class		ScavTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		virtual ~ScavTrap(void);

		void				rangedAttack(std::string const &target);
		void				meleeAttack(std::string const &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				challengeNewcomer(std::string const &target);

		std::string			get_name(void);
		int					get_ranged_damage(void);
		int					get_melee_damage(void);
		int					get_level(void);

		ScavTrap&			operator=(ScavTrap const &src);
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
