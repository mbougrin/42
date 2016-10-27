/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NameModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 14:06:26 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 14:06:29 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMEMODULE_HPP
# define NAMEMODULE_HPP

# include <iostream>
# include <unistd.h>
# include <sys/utsname.h>
# include <pwd.h>
# include "IMonitorModule.hpp"

class NameModule : public IMonitorModule
{
public:
	NameModule(void);
	~NameModule(void);
	void					set(void);
	std::string				getHostName(void) const;
	std::string				getUserName(void) const;
private:
	NameModule(NameModule const &src);
	NameModule				&operator=(NameModule const &rhs);
	std::string				_hostName;
	std::string				_userName;
};

#endif
