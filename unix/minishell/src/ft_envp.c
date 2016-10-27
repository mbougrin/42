/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 03:11:03 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/12 14:12:18 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_unsetenv(const char *name, char **envp)
{
	int		i;

	i = ft_check_setenv(name, envp);
	while (envp[i] != NULL)
	{
		if (envp[i + 1] == NULL)
			break ;
		ft_swap((int *)&envp[i], (int *)&envp[i + 1]);
		i++;
	}
	ft_strdel(&envp[i]);
}

void			ft_envp(char **split, char **envp)
{
	int		i;

	i = 0;
	split = split;
	while (envp[i] != NULL)
	{
		ft_putendl(envp[i]);
		i++;
	}
}

char			*ft_getenv(char *s, char **envp)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	len = ft_strlen(s);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], s, len) == 0)
			return (ft_strsub(envp[i], (len + 1), ft_strlen(envp[i])));
		i++;
	}
	return (NULL);
}
