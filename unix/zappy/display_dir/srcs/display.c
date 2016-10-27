/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 20:29:01 by mblet             #+#    #+#             */
/*   Updated: 2014/06/22 11:48:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "display.h"
#include "ini_display.h"
#include "connect.h"
#include "opt_arg.h"

static void		ft_usage(void)
{
	ft_putendl_fd(USAGE, 2);
}

static void		ft_ini_opt_arg(t_display *d)
{
	d->opt_arg[0] = &ft_opt_arg_h;
	d->opt_arg[1] = &ft_opt_arg_p;
}

static int		ft_check_opt(t_display *d, int argc, char **argv)
{
	int		i;
	int		f;

	i = 1;
	d->connect->port = NULL;
	d->connect->hostname = ft_strdup("localhost");
	while (i < argc)
	{
		f = 0;
		while (f < 2)
		{
			i = d->opt_arg[f](d, i, argv);
			if (i == 0)
				return (i);
			f++;
		}
		i++;
	}
	if (d->connect->port == NULL)
		return (0);
	return (i);
}

void			ft_display(int argc, char **argv)
{
	t_display	*d;

	d = ft_ini_display();
	if (!d)
		return (ft_error("ini_display"));
	ft_ini_opt_arg(d);
	if (!ft_check_opt(d, argc, argv))
		return (ft_usage());
	ft_connect(d);
}
