/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_cpu.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:22:14 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/18 02:12:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CPU_HPP
# define CLASS_CPU_HPP

# include <sys/sysctl.h>
# include <sys/types.h>
# include <mach/mach.h>
# include <mach/processor_info.h>
# include <mach/mach_host.h>
# include <stdio.h>
# include <iostream>
# include <stdlib.h>
# include "IMonitorModule.hpp"

class		Class_cpu : public IMonitorModule
{
	public:
		Class_cpu(void);
		Class_cpu(Class_cpu const &src);
		~Class_cpu(void);

		std::string		getName(void);
		void			setName(void);
		natural_t		getNBCpu(void);
		double			Tcpu_system(void);
		double			Tcpu_user(void);
		double			Tcpu_idle(void);
		double			cpu_system(int nb);
		double			cpu_user(int nb);
		double			cpu_idle(int nb);
		void			setCpu(void);
		void			convertCpu(void);

		Class_cpu&		operator=(Class_cpu const &src);
	private:
		std::string	_name;
		natural_t	_nbProc;
		uint64_t	_totalSystemTime[4];
		uint64_t	_totalUserTime[4];
		uint64_t	_totalIdleTime[4];
		uint64_t	_TtotalSystemTime[4];
		uint64_t	_TtotalUserTime[4];
		uint64_t	_TtotalIdleTime[4];
		double		_system[4];
		double		_user[4];
		double		_idle[4];
		double		_Tsystem;
		double		_Tuser;
		double		_Tidle;
};

#endif
