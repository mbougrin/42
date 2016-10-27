/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:03:48 by mblet             #+#    #+#             */
/*   Updated: 2014/06/22 12:25:53 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serv.h"

int		ft_opt_arg_p(t_env *e, int i, char **argv)
{
	if (!ft_strcmp(argv[i], "-p"))
	{
		if (argv[i + 1] != NULL)
			e->port = ft_atoi(argv[i + 1]);
		else
			return (0);
		return (i + 1);
	}
	return (i);
}

int		ft_opt_arg_x(t_env *e, int i, char **argv)
{
	if (!ft_strcmp(argv[i], "-x"))
	{
		if (argv[i + 1] != NULL)
			e->data.size_x = ft_atoi(argv[i + 1]);
		else
			return (0);
		return (i + 1);
	}
	return (i);
}

int		ft_opt_arg_y(t_env *e, int i, char **argv)
{
	if (!ft_strcmp(argv[i], "-y"))
	{
		if (argv[i + 1] != NULL)
			e->data.size_y = ft_atoi(argv[i + 1]);
		else
			return (0);
		return (i + 1);
	}
	return (i);
}
