/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:51:03 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/14 15:49:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_control_d(struct termios term)
{
	ft_end_termcaps(term);
	ft_putendl("exit");
	ft_exit(0);
}

void			ft_prompt(char **envp)
{
	char	*user;
	char	*pwd;
	char	*group;

	user = ft_getenv("USER", envp);
	pwd = ft_getenv("PWD", envp);
	group = ft_getenv("GROUP", envp);
	if (user == NULL || group == NULL || pwd == NULL)
		ft_putstr("42sh$> ");
	else
	{
		ft_putstr(user);
		ft_putchar('@');
		ft_putstr(group);
		ft_putchar(':');
		ft_putstr(pwd);
		ft_putstr(" 42sh$> ");
		ft_strdel(&group);
		ft_strdel(&user);
		ft_strdel(&pwd);
	}
}

void			ft_exit_split_nb(char **split)
{
	int		nb;

	nb = 0;
	if (split[1] == NULL)
	{
		ft_putendl("exit");
		ft_strstrdel(split);
		ft_exit(0);
	}
	nb = ft_atoi(split[1]);
	ft_strstrdel(split);
	ft_putendl("exit");
	ft_exit(nb);
}

void			ft_exit(int nb)
{
	exit(nb);
}
