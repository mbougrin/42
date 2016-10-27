/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:53:50 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:52:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

int			ft_execve(char *cmd, char **arg)
{
	pid_t	pid;
	int		ret;

	if (cmd == NULL)
	{
		ft_strstrdel(arg);
		return (-1);
	}
	if ((pid = fork()) < 0)
	{
		ft_putendl_fd("fork error", 2);
		return (-1);
	}
	ft_signal_pid(pid);
	if (pid == 0)
		ret = execve(cmd, arg, ft_envp(NULL, "return"));
	else
		wait(NULL);
	ft_strstrdel(arg);
	return (ret);
}
