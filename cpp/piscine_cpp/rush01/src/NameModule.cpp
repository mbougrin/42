/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NameModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 14:06:16 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 14:06:20 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NameModule.hpp"

NameModule::NameModule(void)
{
	return ;
}

NameModule::NameModule(NameModule const &src) : IMonitorModule(src)
{
	*this = src;
	return ;
}

NameModule::~NameModule(void)
{
	return ;
}

NameModule					&NameModule::operator=(NameModule const &rhs)
{
	if (this != &rhs)
	{
		this->_hostName = rhs.getHostName();
		this->_userName = rhs.getUserName();
	}
	return *this;
}

void						NameModule::set(void)
{
	uid_t					uid = getuid();
	struct passwd			*passwd = getpwuid(uid);
	struct utsname			utsname;

	uname(&utsname);
	this->_hostName = utsname.nodename;
	this->_userName = passwd->pw_name;
}

std::string					NameModule::getHostName(void) const
{
	return this->_hostName;
}

std::string					NameModule::getUserName(void) const
{
	return this->_userName;
}
