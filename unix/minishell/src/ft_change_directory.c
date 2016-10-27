/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_directory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 14:59:54 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/06 19:54:12 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char			**ft_change_directory_home(char **envp, char *old_pwd)
{
	char	*pwd;
	char	*home;

	home = ft_getenv("HOME", envp);
	pwd = ft_getenv("PWD", envp);
	old_pwd = ft_getenv("OLDPWD", envp);
	if (home == NULL)
		ft_putendl_fd("HOME not found", 2);
	else
	{
		chdir(home);
		ft_strdel(&old_pwd);
		old_pwd = envp[ft_check_setenv("OLDPWD", envp)];
		envp[ft_check_setenv("OLDPWD", envp)] = ft_strjoin("OLDPWD=", pwd);
		ft_strdel(&pwd);
		ft_strdel(&old_pwd);
		old_pwd = envp[ft_check_setenv("PWD", envp)];
		envp[ft_check_setenv("PWD", envp)] = ft_strjoin("PWD=", home);
		ft_strdel(&home);
		ft_strdel(&old_pwd);
	}
	return (envp);
}

static char			**ft_change_directory_reverse(char **envp)
{
	char	*old_pwd;
	char	*pwd;
	char	*tmp;

	pwd = ft_getenv("PWD", envp);
	old_pwd = ft_getenv("OLDPWD", envp);
	ft_putendl(old_pwd);
	chdir(old_pwd);
	tmp = envp[ft_check_setenv("OLDPWD", envp)];
	envp[ft_check_setenv("OLDPWD", envp)] = ft_strjoin("OLDPWD=", pwd);
	ft_strdel(&tmp);
	tmp = envp[ft_check_setenv("PWD", envp)];
	envp[ft_check_setenv("PWD", envp)] = ft_strjoin("PWD=", old_pwd);
	ft_strdel(&tmp);
	ft_strdel(&old_pwd);
	ft_strdel(&pwd);
	return (envp);
}

static char			**ft_check_chdir_access(char *pwd, char *s, char **envp)
{
	struct stat		s_stat;
	char			tmp[256];
	int				i;

	i = 0;
	stat(s, &s_stat);
	if (access(s, F_OK | X_OK | R_OK) == 0)
	{
		chdir(s);
		i = ft_check_setenv("PWD", envp);
		ft_strdel(&envp[i]);
		envp[i] = ft_strjoin("PWD=", getcwd(tmp, sizeof(tmp)));
		i = ft_check_setenv("OLDPWD", envp);
		ft_strdel(&envp[i]);
		envp[i] = ft_strjoin("OLDPWD=", pwd);
	}
	else if (s_stat.st_mode == 33188)
		ft_cd_error(s, 1);
	else if (access(s, F_OK) != 0)
		ft_cd_error(s, 2);
	else
		ft_cd_error(s, 0);
	return (envp);
}

static char			**ft_change_directory_parameter(char *s, char **envp)
{
	char	*old_pwd;
	char	*pwd;

	pwd = ft_getenv("PWD", envp);
	old_pwd = ft_getenv("OLDPWD", envp);
	envp = ft_check_chdir_access(pwd, s, envp);
	ft_strdel(&old_pwd);
	ft_strdel(&pwd);
	return (envp);
}

char				**ft_change_directory(char **split, char **envp)
{
	char	*tmp;
	char	*pwd;
	char	*old_pwd;

	pwd = ft_getenv("PWD", envp);
	old_pwd = ft_getenv("OLDPWD", envp);
	if (pwd == NULL)
		ft_putendl_fd("PWD not found", 2);
	else if (old_pwd == NULL)
		ft_putendl_fd("OLDPWD not found", 2);
	else if (split[1] == NULL)
		envp = ft_change_directory_home(envp, tmp);
	else if (split[1][0] == '~')
		envp = ft_tilde(envp, split);
	else if (split[1][0] == '-' && split[1][1] == '\0')
		envp = ft_change_directory_reverse(envp);
	else
		envp = ft_change_directory_parameter(split[1], envp);
	if (pwd != NULL)
		ft_strdel(&pwd);
	if (old_pwd != NULL)
		ft_strdel(&old_pwd);
	return (envp);
}
