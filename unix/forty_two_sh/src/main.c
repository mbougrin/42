/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 09:39:23 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 04:17:22 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_add_shell(char *sh)
{
	char	**tmp;

	tmp = ft_strstrnew(3);
	tmp[0] = ft_strdup("setenv");
	tmp[1] = ft_strdup("SHELL");
	tmp[2] = ft_strdup(sh);
	tmp[3] = NULL;
	ft_setenv(tmp);
}

static void		ft_change_envp(void)
{
	char	*tmp;
	char	*sh;
	int		i;

	tmp = ft_getenv("_=");
	i = ft_strlen(tmp);
	while (i > 0)
	{
		if (tmp[i] == '/')
			break ;
		i--;
	}
	tmp[i - 1] = '\0';
	sh = ft_strjoin(tmp, "42sh");
	tmp[i + 1] = ' ';
	ft_strdel(&tmp);
	ft_add_shell(&sh[2]);
	ft_strdel(&sh);
}

static void		ft_init_term(void)
{
	t_shell		sh;

	sh.nenv = ft_envp(NULL, "return");
	ft_new_term();
	ft_init_prompt(&sh);
	ft_reset_term();
}

int				main(int ac, char **av, char **envp)
{
	char	*tmp;

	if (envp[0] == NULL && ft_envp(envp, NULL) == NULL)
		ft_putendl("ENVP not found");
	else if (ac == 1 && av[1] == NULL)
	{
		tmp = ft_strdup("ls");
		ft_envp(ft_strstrdup(envp), NULL);
		ft_change_envp();
		ft_hash_binary(ft_getenv("PATH"), tmp);
		ft_signal();
		ft_init_term();
	}
	else
		ft_putendl("too many arguments");
	return (0);
}
