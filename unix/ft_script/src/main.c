/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 10:17:04 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 23:29:06 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		checkend(int pid)
{
	t_opt	*opt;

	opt = singleton(NULL);
	if (pid)
		kill(pid, SIGUSR1);
	writeend();
	resetterm();
	freeopt();
	_exit(0);
}

t_opt		*singleton(t_opt *opt)
{
	static t_opt	*tmp;

	if (opt != NULL)
		tmp = opt;
	return (tmp);
}

void		freeopt(void)
{
	t_opt	*opt;

	opt = singleton(NULL);
	ft_strdel(&opt->filename);
	ft_strdel(&opt->path);
	ft_strdel(&opt->shell);
	free(opt);
}

int			main(int ac, char **av, char **env)
{
	argparse(ac, av, env);
	writebegin();
	script();
	return (0);
}
