/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:11:46 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 19:45:20 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				openerror(void)
{
	t_opt				*opt;

	opt = singleton(NULL);
	ft_putendl("open error");
	if (opt->initterm == true)
		resetterm();
	freeopt();
	_exit(-1);
}

void				forkerror(void)
{
	t_opt				*opt;

	opt = singleton(NULL);
	ft_putendl("fork error");
	if (opt->initterm == true)
		resetterm();
	freeopt();
	_exit(-1);
}

void				gettimeerror(void)
{
	t_opt				*opt;

	opt = singleton(NULL);
	ft_putendl("gettimeofday error");
	if (opt->initterm == true)
		resetterm();
	freeopt();
	_exit(-1);
}

void				staterror(void)
{
	t_opt				*opt;

	opt = singleton(NULL);
	ft_putendl("stat error");
	if (opt->initterm == true)
		resetterm();
	freeopt();
	_exit(-1);
}

void				ioctlerror(void)
{
	t_opt				*opt;

	opt = singleton(NULL);
	ft_putendl("ioctl error");
	if (opt->initterm == true)
		resetterm();
	freeopt();
	_exit(-1);
}
