/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_network.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 03:57:55 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 04:14:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_NETWORK_HPP
# define CLASS_NETWORK_HPP

# include <net/route.h>
# include <net/if.h>
# include <sys/sysctl.h>
# include <cstdio>
# include <cstdlib>
# include <unistd.h>
# include <string>
# include "IMonitorModule.hpp"

class		Class_network : public IMonitorModule
{
	public:
		Class_network(void);
		Class_network(Class_network const &src);
		virtual ~Class_network(void);

		void					ft_set_network(void);
		long long				ft_get_network(void);

		Class_network&			operator=(Class_network const &src);
	private:
		long long		_result;
};

#endif
