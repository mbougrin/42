/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:53:50 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/27 05:40:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

void			ft_execve(char *cmd, char **arg)
{
	pid_t		pid;
	extern char **environ;

	if ((pid = fork()) < 0)
	{
		ft_putendl_fd("fork error", 2);
		exit(0);
	}
	if (pid == 0)
	{
		execve(cmd, arg, environ);
	}
	else
	{
		return ;
	}
}
