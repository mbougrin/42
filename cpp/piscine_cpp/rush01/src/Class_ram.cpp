/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_ram.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:22:17 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/18 02:06:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class_ram.hpp"

std::string Class_ram::getConvert(void) { return this->_convert; }

void		Class_ram::setConvert(const char *str) { this->_convert = str; }

long long	Class_ram::getFreeMemory(void)
{
	if (this->_convert == "octel")
		return this->_freeMemory;
	else if (this->_convert == "Koctel")
		return this->_freeMemory / 1024;
	else if (this->_convert == "Moctel")
		return this->_freeMemory / 1048576;
	else if (this->_convert == "Goctel")
		return this->_freeMemory / 1073741824;
	return (0);
}

long long	Class_ram::getUsedMemory(void)
{
	if (this->_convert == "octel")
		return this->_usedMemory;
	else if (this->_convert == "Koctel")
		return this->_usedMemory / 1024;
	else if (this->_convert == "Moctel")
		return this->_usedMemory / 1048576;
	else if (this->_convert == "Goctel")
		return this->_usedMemory / 1073741824;
	return (0);
}

void		Class_ram::setUsedMemory(void)
{
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
			KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
				(host_info64_t)&vm_stats, &count))
	{
		this->_freeMemory = (int64_t)vm_stats.free_count * (int64_t)page_size;
		this->_usedMemory = ((int64_t)vm_stats.active_count +
				(int64_t)vm_stats.inactive_count +
				(int64_t)vm_stats.wire_count) *  (int64_t)page_size;
	}
}

int64_t		Class_ram::getPMemory(void)
{
	if (this->_convert == "octel")
		return this->_pmemory;
	else if (this->_convert == "Koctel")
		return this->_pmemory / 1024;
	else if (this->_convert == "Moctel")
		return this->_pmemory / 1000000;
	else if (this->_convert == "Goctel")
		return this->_pmemory / 1073741824;
	return (0);
}

Class_ram::Class_ram(void)
{
	this->_mib[0] = CTL_HW;
	this->_mib[1] = HW_MEMSIZE;
	this->_length = sizeof(int64_t);
	sysctl(this->_mib, 2, &this->_pmemory, &this->_length, NULL, 0);
	return ; 
}

Class_ram::Class_ram(Class_ram const &src) { *this = src; return ; }

Class_ram::~Class_ram(void) { return ; }

Class_ram&	Class_ram::operator=(Class_ram const &src) { if (this != &src) { } return *this; }
