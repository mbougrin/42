/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_directory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:28:46 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:50:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static char		**ft_create_tab(char *path, char *dst)
{
	char	**tmp;

	tmp = ft_strstrnew(4);
	tmp[0] = ft_strdup("setenv");
	tmp[1] = ft_strdup(path);
	tmp[2] = ft_strdup(dst);
	tmp[3] = NULL;
	return (tmp);
}

static void		ft_cd(char *pwd)
{
	char	*home;

	home = ft_getenv("HOME");
	if (home == NULL)
		return (ft_putendl_fd("HOME not found", 2));
	if (ft_cd_check(&home[5]) == 0)
	{
		ft_setenv(ft_create_tab("OLDPWD", &pwd[4]));
		ft_setenv(ft_create_tab("PWD", &home[5]));
		chdir(&home[5]);
	}
	if (home != NULL)
		ft_strdel(&home);
}

static void		ft_cd_old_pwd(char *old, char *pwd)
{
	if (ft_cd_check(&old[7]) == 0)
	{
		ft_setenv(ft_create_tab("PWD", &old[7]));
		ft_setenv(ft_create_tab("OLDPWD", &pwd[4]));
		chdir(&old[7]);
	}
}

static void		ft_cd_split(char *s, char *pwd)
{
	char	tmp[256];

	if (ft_cd_check(s) == 0)
	{
		chdir(s);
		getcwd(tmp, sizeof(tmp));
		ft_setenv(ft_create_tab("PWD", tmp));
		ft_setenv(ft_create_tab("OLDPWD", &pwd[4]));
	}
}

void			ft_change_directory(char **split)
{
	char	*pwd;
	char	*old;

	pwd = ft_getenv("PWD");
	old = ft_getenv("OLDPWD");
	if (pwd == NULL)
		ft_putendl_fd("PWD not found", 2);
	else if (old == NULL)
		ft_putendl_fd("OLDPWD not found", 2);
	else if (split[1] == NULL)
		ft_cd(pwd);
	else if (split[1] != NULL && split[2] != NULL)
		ft_putendl_fd("cd: too many arguments.", 2);
	else if (split[1][0] == '-' && split[1][1] == '\0' && \
			split[2] == NULL)
		ft_cd_old_pwd(old, pwd);
	else
		ft_cd_split(split[1], pwd);
	if (pwd != NULL)
		ft_strdel(&pwd);
	if (old != NULL)
		ft_strdel(&old);
	ft_strstrdel(split);
}
