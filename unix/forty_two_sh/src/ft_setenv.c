/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:46:10 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 04:11:50 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static int		ft_envp_len(char **envp)
{
	int		i;

	i = 1;
	while (envp[i])
		i++;
	return (i);
}

static int		ft_check_envp(char **envp, char *s)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], s) != NULL)
		{
			if (envp[i][0] == s[0])
			{
				if (envp[i][ft_strlen(s)] == '=')
					return (i);
			}
		}
		i++;
	}
	return (-1);
}

static void		ft_add_envp(char **envp, char **split)
{
	char	**tmp;
	char	*s_tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_envp_len(envp);
	tmp = envp;
	envp = ft_strstrnew(len + 2);
	while (tmp[i])
	{
		envp[i] = ft_strdup(tmp[i]);
		i++;
	}
	if (split[2] != NULL)
	{
		s_tmp = ft_strjoin(split[1], "=");
		envp[i] = ft_strjoin(s_tmp, split[2]);
		ft_strdel(&s_tmp);
	}
	else if (split[2] == NULL)
		envp[i] = ft_strjoin(split[1], "=");
	envp[i + 1] = NULL;
	ft_envp(envp, "add");
}

static void		ft_modify_envp(char **envp, char **split, int count)
{
	char	*tmp;
	char	*del_tmp;

	ft_strdel(&envp[count]);
	if (split[2] == NULL)
	{
		del_tmp = envp[count];
		envp[count] = ft_strjoin(split[1], "=");
		ft_strdel(&del_tmp);
	}
	else
	{
		del_tmp = envp[count];
		tmp = ft_strjoin(split[1], "=");
		envp[count] = ft_strjoin(tmp, split[2]);
		ft_strdel(&tmp);
		ft_strdel(&del_tmp);
	}
	ft_envp(ft_strstrdup(envp), "add");
}

void			ft_setenv(char **split)
{
	char	**envp;
	int		count;
	int		i;

	if (ft_envp_len(split) >= 4)
	{
		ft_putendl_fd("setenv: Too many arguments.", 2);
		ft_strstrdel(split);
		return ;
	}
	envp = ft_envp(NULL, "return");
	if (split[1] == NULL)
	{
		i = 0;
		while (envp[i])
			ft_putendl(envp[i++]);
		return ;
	}
	if ((count = ft_check_envp(envp, split[1])) != -1)
		ft_modify_envp(envp, split, count);
	else
		ft_add_envp(envp, split);
	ft_strstrdel(split);
}
