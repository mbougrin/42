/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 11:55:24 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 15:16:05 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void		optinit(char **env)
{
	t_opt	*opt;

	opt = (t_opt *)malloc(sizeof(t_opt));
	opt->slave = 0;
	opt->master = 0;
	opt->pid = 0;
	opt->fd = 0;
	opt->q = false;
	opt->initterm = false;
	opt->filename = NULL;
	opt->path = NULL;
	opt->shell = NULL;
	opt->env = env;
	singleton(opt);
}

static void		envparse(void)
{
	t_opt	*opt;

	opt = singleton(NULL);
	opt->path = ft_getenv("PWD");
	opt->shell = ft_getenv("SHELL");
}

void			argparse(int ac, char **av, char **env)
{
	int		i;
	t_opt	*opt;

	optinit(env);
	envparse();
	opt = singleton(NULL);
	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-q") == 0)
			opt->q = true;
		else if (ft_strcmp(av[i], "-a") == 0)
			opt->filename = ft_strdup(av[i + 1]);
		else
			opt->filename = ft_strdup(av[i]);
		i++;
	}
	if (opt->filename == NULL)
		opt->filename = ft_strdup("typescript");
}
