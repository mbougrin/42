/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 14:06:35 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 14:06:37 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeModule.hpp"

TimeModule::TimeModule(void)
{
	return ;
}

TimeModule::TimeModule(TimeModule const &src) : IMonitorModule(src)
{
	*this = src;
	return ;
}

TimeModule::~TimeModule(void)
{
	return ;
}

TimeModule					&TimeModule::operator=(TimeModule const &rhs)
{
	if (this != &rhs)
	{
		this->_time = rhs.getTime();
	}
	return *this;
}

void						TimeModule::set(void)
{
	time_t						currentTime = time(NULL);

	this->_time = ctime(&currentTime);
}

std::string					TimeModule::getTime(void) const
{
	return this->_time.substr(0, _time.size() - 1);
}
