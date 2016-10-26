/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:01:57 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/26 15:03:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_stc					*singleton(t_stc *stc)
{
	static t_stc	*singleton;

	if (stc != NULL)
		singleton = stc;
	return (singleton);
}

void					sig_handler(int sig)
{
	if (sig == SIGINT)
		printsigint();
}

char					*arg(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (ft_strcmp(av[i], "-h") == 0)
			showhelp(av[0]);
		else if (av[i][0] != '-')
			return (av[i]);
		i++;
	}
	free(singleton(NULL));
	exit(-1);
}
