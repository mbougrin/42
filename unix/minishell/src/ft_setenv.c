/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:31:22 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/12 11:03:37 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int				ft_check_setenv(const char *name, char **envp)
{
	int		i;
	int		j;

	i = 0;
	while (envp[i] != NULL)
	{
		j = 0;
		while (name[j])
		{
			if (name[j] != envp[i][j])
				break ;
			j++;
		}
		if (envp[i][j] == '=')
			break ;
		i++;
	}
	if (envp[i] == NULL)
		return (0);
	return (i);
}

static char		**ft_add_envp(const char *name, const char *value, char **envp)
{
	char	**tmp_envp;
	char	*path;
	char	*tmp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	tmp = ft_strjoin(name, "=");
	path = ft_strjoin(tmp, value);
	ft_strdel(&tmp);
	while (envp[len] != NULL)
		len++;
	tmp_envp = ft_strstrnew(len + 2);
	while (envp[i] != NULL)
	{
		tmp_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	tmp_envp[i] = path;
	tmp_envp[i + 1] = NULL;
	ft_strstrdel(envp);
	return (tmp_envp);
}

static void		ft_add_value(const char *name, const char *value, char **envp)
{
	int		len;
	int		i;
	char	*tmp;

	i = ft_check_setenv(name, envp);
	len = ft_strlen(envp[i]);
	tmp = envp[i];
	envp[i] = ft_strjoin(envp[i], &value[ft_strlen(name) + 1]);
	ft_strdel(&tmp);
}

static int		ft_check_cmp(const char *name, const char *value)
{
	int		i;

	i = 0;
	while (value[i] != '\0')
	{
		if (value[i] != name[i])
			break ;
		i++;
	}
	if (value[i] == '=')
		return (i);
	return (0);
}

char			**ft_setenv(const char *name, const char *value, char **envp)
{
	char	*tmp;
	int		i;

	if (value == NULL)
	{
		i = ft_check_setenv(name, envp);
		ft_strdel(&envp[i]);
		envp[i] = ft_strjoin(name, "=");
	}
	else if (ft_check_setenv(name, envp) == 0)
		envp = ft_add_envp(name, value, envp);
	else if (ft_check_cmp(name, value) != 0)
		ft_add_value(name, value, envp);
	else
	{
		i = ft_check_setenv(name, envp);
		tmp = ft_strjoin(name, "=");
		ft_strdel(&envp[i]);
		envp[i] = ft_strjoin(tmp, value);
		ft_strdel(&tmp);
	}
	return (envp);
}
