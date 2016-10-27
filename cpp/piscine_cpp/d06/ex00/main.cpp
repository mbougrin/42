/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:43:41 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/15 17:18:06 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int				main(int ac, char **av)
{
	if (ac == 2)
	{
		Class_convert		Convert;
		double				res = strtod(av[1], NULL);

		Convert.convert_char(res);
		Convert.convert_int(res);
		Convert.convert_float(res, av[1]);
		Convert.convert_double(res, av[1]);
	}
	return (0);
}
