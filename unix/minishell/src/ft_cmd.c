/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 03:24:54 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/26 13:59:12 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_execve_cmd(char *cmd, char **split, char **envp)
{
	pid_t	pid;

	pid = 0;
	if ((pid = fork()) < 0)
	{
		ft_putendl_fd("fork error", 2);
		ft_exit(-1);
	}
	ft_signal_pid(pid);
	if (pid == 0)
		execve(cmd, split, envp);
	else
		wait(NULL);
}

static void		ft_permission_denied(char *cmd, char *name)
{
	ft_putstr("42sh: permission denied: ");
	ft_putendl(name);
	ft_strdel(&cmd);
}

static int		ft_access_cmd(char **path, char **split, char **envp)
{
	char	*tmp;
	char	*cmd;
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		tmp = ft_strjoin("/", split[0]);
		cmd = ft_strjoin(path[i], tmp);
		ft_strdel(&tmp);
		if (access(cmd, X_OK) != 0 && access(cmd, F_OK) == 0)
		{
			ft_permission_denied(cmd, split[0]);
			return (-1);
		}
		if (access(cmd, F_OK | X_OK) == 0)
		{
			ft_execve_cmd(cmd, split, envp);
			ft_strdel(&cmd);
			return (i);
		}
		ft_strdel(&cmd);
		i++;
	}
	return (i);
}

static int		ft_cmd_root(char **split, char **envp)
{
	int		i;

	i = 0;
	if (access(split[0], F_OK | X_OK) == 0)
	{
		i = 1;
		ft_execve_cmd(split[0], split, envp);
	}
	else if (access(split[0], X_OK) != 0 && access(split[0], F_OK) == 0)
	{
		i = 1;
		ft_putstr("42sh: permission denied: ");
		ft_putendl(split[0]);
	}
	else if (ft_strstr(split[0], "./") != NULL)
	{
		ft_putstr("42sh: no such file or directory: ");
		ft_putendl(split[0]);
		i = 1;
	}
	return (i);
}

void			ft_check_cmd(char **split, char **envp)
{
	char	*tmp;
	char	**path;
	int		i;

	i = 0;
	tmp = ft_getenv("PATH", envp);
	path = ft_strsplit(tmp, ':');
	ft_strdel(&tmp);
	i = ft_access_cmd(path, split, envp);
	if (i != -1)
	{
		if (path[i] == NULL && ft_cmd_root(split, envp) == 0 && i != -1)
		{
			ft_putstr("42sh: command not found: ");
			ft_putendl(split[0]);
		}
	}
	ft_strstrdel(path);
}
