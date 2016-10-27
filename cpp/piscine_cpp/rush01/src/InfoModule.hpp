/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfoModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 14:06:07 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 14:06:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOMODULE_HPP
# define INFOMODULE_HPP

# include <iostream>
# include <sys/utsname.h>
# include "IMonitorModule.hpp"

class InfoModule : public IMonitorModule
{
public:
	InfoModule(void);
	~InfoModule(void);
	void					set(void);
	std::string				getInfo(void) const;
private:
	InfoModule(InfoModule const &src);
	InfoModule				&operator=(InfoModule const &rhs);
	std::string				_info;
};

#endif
