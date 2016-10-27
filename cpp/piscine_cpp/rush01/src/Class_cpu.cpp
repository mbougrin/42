/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_cpu.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:22:17 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/18 02:12:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class_cpu.hpp"

double		Class_cpu::Tcpu_system(void) { return this->_Tsystem; }

double		Class_cpu::Tcpu_user(void) { return this->_Tuser; }

double		Class_cpu::Tcpu_idle(void) { return this->_Tidle; }

double		Class_cpu::cpu_system(int nb) { return this->_system[nb]; }

double		Class_cpu::cpu_user(int nb) { return this->_user[nb]; }

double		Class_cpu::cpu_idle(int nb) { return this->_idle[nb]; }

natural_t	Class_cpu::getNBCpu(void) { return this->_nbProc; }

std::string	Class_cpu::getName(void) { return this->_name; }

void		Class_cpu::setName(void)
{
	char buf[100];
	size_t buflen = 100;
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
	this->_name = buf;	
}

void		Class_cpu::convertCpu(void)
{
	uint64_t TtotalSystemTime = 0;
	uint64_t TtotalUserTime = 0;
	uint64_t TtotalIdleTime = 0;
	for (natural_t i = 0 ; i < this->_nbProc ; i++)
	{
		uint64_t totalSystemTime = this->_totalSystemTime[i] - this->_TtotalSystemTime[i];
		uint64_t totalUserTime = this->_totalUserTime[i] - this->_TtotalUserTime[i];
		uint64_t totalIdleTime = this->_totalIdleTime[i] - this->_TtotalIdleTime[i];
		uint64_t total = totalSystemTime + totalUserTime + totalIdleTime;
		TtotalSystemTime += totalSystemTime;
		TtotalUserTime += totalUserTime;
		TtotalIdleTime += totalIdleTime;
		double onePercent = total / 100.0f;
		this->_system[i] = (static_cast<double>(totalSystemTime) / onePercent);
		this->_user[i] = (static_cast<double>(totalUserTime) / onePercent);
		this->_idle[i] = (static_cast<double>(totalIdleTime) / onePercent);
	}
	uint64_t total = TtotalSystemTime + TtotalUserTime + TtotalIdleTime;
	double onePercent = total / 100.0f;
	this->_Tsystem =  (static_cast<double>(TtotalSystemTime) / onePercent);
	this->_Tuser = (static_cast<double>(TtotalUserTime) / onePercent);
	this->_Tidle = (static_cast<double>(TtotalIdleTime) / onePercent);
}

void		Class_cpu::setCpu(void)
{
	processor_cpu_load_info_t cpuLoad;
	mach_msg_type_number_t processorMsgCount;
	natural_t processorCount;

	int ret = host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &processorCount, (processor_info_array_t *)&cpuLoad, &processorMsgCount);
	if (ret != 0)
	{
		std::cout << "Error: failed to scan processor info" << std::endl;
		exit(0);
	}
	this->_nbProc = processorCount;
	for (natural_t i = 0; i < processorCount; i++) 
	{
		this->_TtotalSystemTime[i] = this->_totalSystemTime[i];
		this->_TtotalUserTime[i] = this->_totalUserTime[i];
		this->_TtotalIdleTime[i] = this->_totalIdleTime[i];
	}
	for (natural_t i = 0; i < processorCount; i++) 
	{
		this->_totalSystemTime[i] = 0;
		this->_totalUserTime[i] = 0;
		this->_totalIdleTime[i] = 0;
	}
	for (natural_t i = 0; i < processorCount; i++) 
	{
		uint64_t system = 0, user = 0, idle = 0;
		system = cpuLoad[i].cpu_ticks[CPU_STATE_SYSTEM];
		user = cpuLoad[i].cpu_ticks[CPU_STATE_USER] + cpuLoad[i].cpu_ticks[CPU_STATE_NICE];
		idle = cpuLoad[i].cpu_ticks[CPU_STATE_IDLE];
		this->_totalSystemTime[i] = system;
		this->_totalUserTime[i] = user;
		this->_totalIdleTime[i] = idle;
	}
}

Class_cpu::Class_cpu(void) { return ; }

Class_cpu::Class_cpu(Class_cpu const &src) { *this = src; return ; }

Class_cpu::~Class_cpu(void) { return ; }

Class_cpu&	Class_cpu::operator=(Class_cpu const &src) { if (this != &src) { } return *this; }
