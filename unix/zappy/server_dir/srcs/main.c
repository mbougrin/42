/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:27:41 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 04:23:23 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serv.h"

int		main(int ac, char **av)
{
	t_env	e;

	srand(clock());
	init_env(&e);
	get_opt(&e, ac, av);
	srv_create(&e, e.port);
	map_create(&e);
	main_loop(&e);
	return (0);
}
