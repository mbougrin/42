/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 12:17:57 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:32:13 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void			ft_exit(int nb, char *s)
{
	ft_strdel(&s);
	ft_putendl("exit");
	exit(nb);
}

static int		ft_len_space(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

int				ft_builtin(char *s)
{
	if (ft_strncmp(s, "exit", ft_strlen("exit")) == 0 \
			&& ft_len_space(s) == (int)ft_strlen("exit"))
		ft_exit(ft_atoi(&s[ft_strlen("exit ")]), s);
	else if (ft_strncmp(s, "setenv", ft_strlen("setenv")) == 0 \
			&& ft_len_space(s) == (int)ft_strlen("setenv"))
		ft_setenv(ft_shellsplit(s, ' '));
	else if (ft_strncmp(s, "unsetenv", ft_strlen("unsetenv")) == 0 \
			&& ft_len_space(s) == (int)ft_strlen("unsetenv"))
		ft_unsetenv(ft_shellsplit(s, ' '));
	else if (ft_strncmp(s, "env", ft_strlen("env")) == 0 \
			&& ft_len_space(s) == (int)ft_strlen("env"))
		ft_env(s, ft_shellsplit(s, ' '));
	else if (ft_strncmp(s, "cd", ft_strlen("cd")) == 0 \
			&& ft_len_space(s) == (int)ft_strlen("cd"))
		ft_change_directory(ft_shellsplit(s, ' '));
	else if (ft_strncmp(s, "echo", ft_strlen("echo")) == 0 \
			&& ft_len_space(s) == (int)ft_strlen("echo"))
		ft_echo(ft_shellsplit(s, ' '));
	else
		return (0);
	return (1);
}
