/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:08:00 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/10 10:34:02 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class		NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const &src);
		virtual ~NinjaTrap(void);

		void				ninjaShoebox(ClapTrap& clap);
		void				ninjaShoebox(NinjaTrap& ninja);
		void				ninjaShoebox(FragTrap& frag);
		void				ninjaShoebox(ScavTrap& scav);
		NinjaTrap&			operator=(NinjaTrap const &src);
	private:
};

#endif
