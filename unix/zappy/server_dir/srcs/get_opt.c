/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:24:51 by mbar              #+#    #+#             */
/*   Updated: 2014/06/23 19:02:23 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "serv.h"

static void		ft_usage(void)
{
	ft_putstr_fd("usage: ./serveur -p <port> -x <width> -y <height>", 2);
	ft_putendl_fd(" -n <team> [<team>] -c <nb> -t <t>", 2);
	exit(EXIT_FAILURE);
}

static void		ft_ini_opt_arg(t_env *e)
{
	e->opt_arg[0] = &ft_opt_arg_p;
	e->opt_arg[1] = &ft_opt_arg_x;
	e->opt_arg[2] = &ft_opt_arg_y;
	e->opt_arg[3] = &ft_opt_arg_n;
	e->opt_arg[4] = &ft_opt_arg_c;
	e->opt_arg[5] = &ft_opt_arg_t;
}

static int		ft_check_opt(t_env *e, int argc, char **argv)
{
	int		i;
	int		f;

	i = 1;
	while (i < argc)
	{
		f = 0;
		while (f < 6)
		{
			i = e->opt_arg[f](e, i, argv);
			if (i == 0)
				return (0);
			f++;
		}
		i++;
	}
	return (i);
}

void			get_opt(t_env *e, int ac, char **av)
{
	ft_ini_opt_arg(e);
	if (!ft_check_opt(e, ac, av))
		ft_usage();
}
