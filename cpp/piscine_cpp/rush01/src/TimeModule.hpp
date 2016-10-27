/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 14:06:45 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 14:06:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include <iostream>
# include <ctime>
# include "IMonitorModule.hpp"

class TimeModule : public IMonitorModule
{
public:
	TimeModule(void);
	~TimeModule(void);
	void					set(void);
	std::string				getTime(void) const;
private:
	TimeModule(TimeModule const &src);
	TimeModule				&operator=(TimeModule const &rhs);
	std::string				_time;
};

#endif
