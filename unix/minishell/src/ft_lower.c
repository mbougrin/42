/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 21:25:07 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/08 20:10:51 by mbougrin         ###   ########.fr       */
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

static void		ft_lower_lower_cmd(char **envp, char **split, int j)
{
	int		fd;

	fd = ft_open_tmp(split[j]);
	j = dup(0);
	dup2(fd, 0);
	close(fd);
	ft_check_cmd(split, envp);
	dup2(j, 0);
}

void			ft_lower_lower(char **envp, char **split)
{
	int		i;
	int		j;
	int		fd;

	i = 0;
	i = ft_check_split(split, "<<");
	split[i] = NULL;
	j = i + 1;
	if (i != 0 && ft_check_access_cmd(split, envp) == -1)
		ft_lower_lower_cmd(envp, split, j);
	else if (split[j + 1] == NULL)
		ft_read_lower_lower(split);
	else if (ft_check_access_cmd(&split[j + 1], envp) != -1)
		return ;
	else
	{
		fd = ft_open_tmp(split[1]);
		j = dup(0);
		dup2(fd, 0);
		ft_check_cmd(&split[i + 2], envp);
		close(fd);
		dup2(j, 0);
	}
	ft_remove_tmp(envp);
	split[i] = ft_strdup("<<");
}

static void		ft_lower_cmd(char **envp, char **split, int j)
{
	int		fd;

	if ((fd = open(split[j], O_RDONLY)) == -1)
		ft_putendl_fd("open error", 2);
	else
	{
		j = dup(0);
		dup2(fd, 0);
		ft_check_cmd(split, envp);
		close(fd);
		dup2(j, 0);
	}
}

void			ft_lower(char **envp, char **split)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	i = ft_check_split(split, "<");
	split[i] = NULL;
	j = i + 1;
	if (i != 0 && ft_check_access_cmd(split, envp) == -1)
		ft_lower_cmd(envp, split, j);
	else if ((fd = open(split[j], O_RDONLY)) == -1)
		ft_putendl_fd("open error", 2);
	else if (split[j + 1] == NULL)
		ft_read_lower(fd);
	else if (ft_check_access_cmd(&split[j + 1], envp) != -1)
		return ;
	else
	{
		j = dup(0);
		dup2(fd, 0);
		ft_check_cmd(&split[i + 2], envp);
		close(fd);
		dup2(j, 0);
	}
	split[i] = ft_strdup("<");
}
