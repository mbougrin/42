/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_arg2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:27:35 by mblet             #+#    #+#             */
/*   Updated: 2014/06/22 12:26:16 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serv.h"

int		ft_opt_arg_n(t_env *e, int i, char **argv)
{
	int		n;

	if (!ft_strcmp(argv[i], "-n"))
	{
		n = i;
		if (argv[i + 1] == NULL)
			return (0);
		while (argv[n + 1] != NULL && argv[n + 1][0] != '-')
		{
			ft_creat_team(e, argv[n + 1]);
			n++;
		}
		return (n);
	}
	return (i);
}

int		ft_opt_arg_c(t_env *e, int i, char **argv)
{
	if (!ft_strcmp(argv[i], "-c"))
	{
		if (argv[i + 1] != NULL)
		{
			e->data.max_client = ft_atoi(argv[i + 1]);
			e->data.nb_client = ft_atoi(argv[i + 1]);
		}
		else
			return (0);
		return (i + 1);
	}
	return (i);
}

int		ft_opt_arg_t(t_env *e, int i, char **argv)
{
	if (!ft_strcmp(argv[i], "-t"))
	{
		if (argv[i + 1] != NULL)
		{
			e->data.d_time = ft_atoi(argv[i + 1]);
		}
		else
			return (0);
		return (i + 1);
	}
	return (i);
}
