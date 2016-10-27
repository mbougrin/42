/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_ram.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:22:14 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/17 16:55:53 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_RAM_HPP
# define CLASS_RAM_HPP

# include <sys/types.h>
# include <sys/sysctl.h>
# include <iostream>
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include "IMonitorModule.hpp"

class		Class_ram : public IMonitorModule
{
	public:
		Class_ram(void);
		Class_ram(Class_ram const &src);
		~Class_ram(void);

		std::string		getConvert(void);
		void			setConvert(const char *str);
		void			setUsedMemory(void);
		int64_t			getPMemory(void);
		long long		getFreeMemory(void);
		long long		getUsedMemory(void);
		Class_ram&		operator=(Class_ram const &src);
	private:
		int 		_mib[2];
		std::string _convert;
		int64_t 	_pmemory;
		size_t		_length;
		long long	_freeMemory;
		long long	_usedMemory;
};

#endif
