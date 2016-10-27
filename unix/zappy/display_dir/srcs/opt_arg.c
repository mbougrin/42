/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 16:00:06 by mblet             #+#    #+#             */
/*   Updated: 2014/06/22 11:47:59 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "display.h"

int		ft_opt_arg_h(t_display *d, int i, char **argv)
{
	if (!ft_strcmp(argv[i], "-h"))
	{
		if (argv[i + 1] != NULL)
		{
			ft_strdel(&d->connect->hostname);
			d->connect->hostname = ft_strdup(argv[i + 1]);
			return (i + 1);
		}
	}
	return (i);
}

int		ft_opt_arg_p(t_display *d, int i, char **argv)
{
	if (!ft_strcmp(argv[i], "-p"))
	{
		if (argv[i + 1] != NULL)
			d->connect->port = ft_strdup(argv[i + 1]);
		else
			return (0);
		return (i + 1);
	}
	return (i);
}
