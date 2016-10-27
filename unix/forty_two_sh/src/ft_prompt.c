/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:03:12 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 04:08:25 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_print_prompt(char *user, char *pwd, char *home, char *group)
{
	int		count;

	count = ft_strlen(&home[5]);
	ft_putstr(&user[5]);
	ft_putchar('@');
	ft_putstr(&group[6]);
	ft_putchar(':');
	if (ft_strstr(&pwd[4], &home[5]) != NULL)
	{
		if (ft_strncmp(&pwd[4], "/Volumes/Data", ft_strlen("/Volumes/Data")) \
	== 0)
			count += ft_strlen("/Volumes/Data");
		ft_putchar('~');
		if (ft_strlen(&pwd[4]) > ft_strlen(&home[5]))
		{
			if (pwd[count + 4] == '\0')
				ft_putchar('/');
			ft_putstr(&pwd[count + 4]);
		}
		else
			ft_putchar('/');
	}
	else
		ft_putstr(&pwd[4]);
	ft_putstr(" 42sh$> ");
}

void			ft_prompt(void)
{
	char	*home;
	char	*pwd;
	char	*user;
	char	*group;

	home = ft_getenv("HOME");
	pwd = ft_getenv("PWD");
	user = ft_getenv("USER");
	group = ft_getenv("GROUP");
	if (home == NULL || pwd == NULL || user == NULL || group == NULL \
			|| (ft_strlen("USER") + 1) == ft_strlen(user)
			|| (ft_strlen("PWD") + 1) == ft_strlen(pwd)
			|| (ft_strlen("HOME") + 1) == ft_strlen(home)
			|| (ft_strlen("GROUP") + 1) == ft_strlen(group))
		ft_putstr("42sh$> ");
	else
		ft_print_prompt(user, pwd, home, group);
	if (home != NULL)
		ft_strdel(&home);
	if (pwd != NULL)
		ft_strdel(&pwd);
	if (user != NULL)
		ft_strdel(&user);
	if (group != NULL)
		ft_strdel(&group);
}
