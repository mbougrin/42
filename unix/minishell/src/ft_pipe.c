/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 20:32:20 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/08 23:43:01 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_check_split(char **split, char *s)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		if (ft_strcmp(split[i], s) == 0)
			break ;
		i++;
	}
	return (i);
}

static void		ft_child(char **split, int *fd_tab, char **envp)
{
	close(fd_tab[0]);
	dup2(fd_tab[1], 1);
	close(fd_tab[1]);
	ft_check_cmd(split, envp);
	exit(0);
}

static void		ft_father(char **split, int *fd_tab, char **envp)
{
	close(fd_tab[1]);
	dup2(fd_tab[0], 0);
	close(fd_tab[0]);
	ft_check_cmd(split, envp);
}

void			ft_cmd_pipe(char **envp, char **split)
{
	int				fd_tab[2];
	int				fd_zero;
	int				fd_one;
	pid_t			pid;
	int				i;

	fd_zero = dup(0);
	fd_one = dup(1);
	i = 0;
	i = ft_check_split(split, "|");
	split[i] = NULL;
	if (pipe(fd_tab) == -1)
		ft_putendl("pipe error");
	if ((pid = fork()) < 0)
		ft_putendl("fork error");
	if (pid == 0)
		ft_child(split, fd_tab, envp);
	else
	{
		wait(&pid);
		ft_father(&split[i + 1], fd_tab, envp);
	}
	dup2(fd_one, 1);
	dup2(fd_zero, 0);
	split[i] = ft_strdup("|");
}
