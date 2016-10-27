/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 18:42:15 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:48:36 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_cd_permission(char *s)
{
	ft_putstr_fd("42sh: cd: permission denied: ", 2);
	ft_putendl_fd(s, 2);
}

static void		ft_cd_not_found(char *s)
{
	ft_putstr_fd("42sh: cd: no such file or directory: ", 2);
	ft_putendl_fd(s, 2);
}

static void		ft_cd_not_directory(char *s)
{
	ft_putstr_fd("42sh: cd: not a directory: ", 2);
	ft_putendl_fd(s, 2);
}

int				ft_cd_check(char *s)
{
	struct stat		s_stat;

	stat(s, &s_stat);
	if (access(s, F_OK) != 0)
		ft_cd_not_found(s);
	else if (S_ISDIR(s_stat.st_mode) == 1)
	{
		if (access(s, F_OK | X_OK | R_OK) == 0)
			return (0);
		else
			ft_cd_permission(s);
	}
	else
		ft_cd_not_directory(s);
	return (1);
}
