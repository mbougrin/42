/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 19:49:54 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/06 20:36:08 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char			**ft_cd_tilde(char *s, char **envp)
{
	char	tmp[256];
	char	*pwd;
	int		i;

	i = 0;
	chdir(s);
	pwd = ft_getenv("PWD", envp);
	i = ft_check_setenv("PWD", envp);
	ft_strdel(&envp[i]);
	envp[i] = ft_strjoin("PWD=", getcwd(tmp, sizeof(tmp)));
	i = ft_check_setenv("OLDPWD", envp);
	ft_strdel(&envp[i]);
	envp[i] = ft_strjoin("OLDPWD=", pwd);
	ft_strdel(&pwd);
	return (envp);
}

char				**ft_tilde(char **envp, char **split)
{
	struct stat		s_stat;
	char			*home;
	char			*pwd;

	home = ft_getenv("HOME", envp);
	pwd = ft_getenv("PWD", envp);
	if (home == NULL)
		ft_putendl("HOME not found");
	else
	{
		chdir(home);
		stat(&split[1][2], &s_stat);
		if (access(&split[1][2], F_OK | X_OK | R_OK) == 0)
			return (ft_cd_tilde(&split[1][2], envp));
		else if (s_stat.st_mode == 33188)
			ft_cd_error(&split[1][2], 1);
		else if (access(&split[1][2], F_OK) != 0)
			ft_cd_error(&split[1][2], 2);
		else
			ft_cd_error(&split[1][2], 0);
		chdir(pwd);
		ft_strdel(&home);
		ft_strdel(&pwd);
	}
	return (envp);
}
