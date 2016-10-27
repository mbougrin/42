/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 14:05:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 14:05:50 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <iostream>

class IMonitorModule
{
public:
	IMonitorModule(void) {}
	IMonitorModule(IMonitorModule const &src) { (void)src; }
	virtual ~IMonitorModule(void) {}

	//virtual void	set(void) = 0;

private:
	virtual IMonitorModule			&operator=(IMonitorModule const&) { return (*this); }
};

#endif
