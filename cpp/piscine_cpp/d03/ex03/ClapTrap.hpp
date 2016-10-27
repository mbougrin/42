/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 08:31:48 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 08:58:18 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class		ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		virtual ~ClapTrap(void);

		void				rangedAttack(std::string const &target);
		void				meleeAttack(std::string const &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		std::string			get_name(void);
		int					get_ranged_damage(void);
		int					get_melee_damage(void);
		int					get_level(void);

		ClapTrap&			operator=(ClapTrap const &src);
	private:
	protected:
		int					_hit_points;
		int					_max_hit_points;
		int					_energy_points;
		int					_max_energy_points;
		int					_level;
		int					_melee_attack_damage;
		int					_ranged_attack_damage;
		int					_armor;
		std::string			_name;
};

#endif
