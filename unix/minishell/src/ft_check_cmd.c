/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 21:04:26 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/07 02:54:03 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_access_cmd(char **path, char **split)
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
		if (access(cmd, F_OK | X_OK) == 0)
		{
			ft_strdel(&cmd);
			return (-1);
		}
		else if (access(cmd, F_OK) == 0 && access(cmd, X_OK) != 0)
		{
			ft_putstr("42sh: permission denied: ");
			ft_putendl(split[0]);
			return (1);
		}
		ft_strdel(&cmd);
		i++;
	}
	return (i);
}

static int		ft_cmd_root(char **split)
{
	int		i;

	i = 0;
	if (access(split[0], F_OK | X_OK) == 0)
		i = -1;
	else if (access(split[0], F_OK) == 0 && access(split[0], X_OK) != 0)
	{
		ft_putstr("42sh: permission denied: ");
		ft_putendl(split[0]);
		i = 1;
	}
	else if (ft_strstr(split[0], "./") != NULL)
	{
		ft_putstr("42sh: no such file or directory: ");
		ft_putendl(split[0]);
		i = 1;
	}
	return (i);
}

int				ft_check_access_cmd(char **split, char **envp)
{
	char	*tmp;
	char	**path;
	int		i;

	i = 0;
	tmp = ft_getenv("PATH", envp);
	path = ft_strsplit(tmp, ':');
	ft_strdel(&tmp);
	i = ft_access_cmd(path, split);
	if (i != -1 && path[i] == NULL && (i = ft_cmd_root(split) == 0))
	{
		ft_putstr("42sh: command not found: ");
		ft_putendl(split[0]);
	}
	ft_strstrdel(path);
	return (i);
}
