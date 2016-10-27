/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 17:19:42 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/31 18:54:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void			ft_check_file2(char *s, char **envp)
{
	t_struc		*pp;

	pp = (t_struc *)malloc(sizeof(t_struc));
	pp->str = ft_strjoin(ft_strsub(envp[15], 4, \
				ft_strlen(envp[15])), ft_strjoin("/", s));
	if (access(pp->str, W_OK) == -1)
	{
		write(2, "permission denied file2\n", 24);
		_exit(-1);
	}
}

void			ft_cmd_error(char *s)
{
	write(2, "command not found: ", 19);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	_exit(-1);
}

void			ft_check_file(char *s, char **envp)
{
	t_struc		*pp;

	pp = (t_struc *)malloc(sizeof(t_struc));
	pp->str = ft_strjoin(ft_strsub(envp[15], 4, \
				ft_strlen(envp[15])), ft_strjoin("/", s));
	if (access(pp->str, F_OK) == -1)
	{
		write(2, "file1 not found\n", 16);
		_exit(-1);
	}
	if (access(pp->str, R_OK) == -1)
	{
		write(2, "permission denied file1\n", 24);
		_exit(-1);
	}
}

void			ft_pipe_error(void)
{
		write(2, "pipe failed\n", 12);
		_exit(-1);
}

void			ft_fork_error(void)
{
		write(2, "fork failed\n", 12);
		_exit(-1);
}
