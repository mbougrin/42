/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfoModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 14:05:58 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 14:06:00 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InfoModule.hpp"

InfoModule::InfoModule(void)
{
	return ;
}

InfoModule::InfoModule(InfoModule const &src) : IMonitorModule(src)
{
	*this = src;
	return ;
}

InfoModule::~InfoModule(void)
{
	return ;
}

void						InfoModule::set(void)
{
	struct utsname			utsname;

	uname(&utsname);
	this->_info = utsname.version;
}

InfoModule					&InfoModule::operator=(InfoModule const &rhs)
{
	if (this != &rhs)
	{
		this->_info = rhs.getInfo();
	}
	return *this;
}

std::string					InfoModule::getInfo(void) const
{
	std::size_t pos = _info.find(":");

	return this->_info.substr(0, pos);
}
