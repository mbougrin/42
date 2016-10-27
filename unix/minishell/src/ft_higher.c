/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_higher.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 02:54:21 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/14 17:07:59 by mbougrin         ###   ########.fr       */
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

void			ft_higher_higher(char **envp, char **split)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	i = ft_check_split(split, ">>");
	split[i] = NULL;
	j = i + 1;
	if (split[0] == NULL || ft_check_access_cmd(split, envp) != -1)
		return ;
	if ((fd = open(split[j], O_WRONLY | O_RDONLY | O_CREAT \
					| O_APPEND, 0644)) == -1)
		ft_putendl_fd("open error", 2);
	else
	{
		j = dup(1);
		dup2(fd, 1);
		ft_check_cmd(split, envp);
		close(fd);
		dup2(j, 1);
	}
	split[i] = ft_strdup(">>");
}

void			ft_higher(char **envp, char **split)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	i = ft_check_split(split, ">");
	split[i] = NULL;
	j = i + 1;
	if (split[0] == NULL || ft_check_access_cmd(split, envp) != -1)
		return ;
	if ((fd = open(split[j], O_WRONLY | O_RDONLY | O_CREAT \
					| O_TRUNC, 0644)) == -1)
		ft_putendl_fd("open error", 2);
	else
	{
		j = dup(1);
		dup2(fd, 1);
		ft_check_cmd(split, envp);
		close(fd);
		dup2(j, 1);
	}
	split[i] = ft_strdup(">");
}
