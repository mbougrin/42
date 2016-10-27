/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_pid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 19:14:19 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/14 15:48:26 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_pid_tmp(pid_t pid)
{
	pid_t	pid_tmp;

	if (pid == 0)
		return (pid_tmp);
	else
		pid_tmp = pid;
	return (pid);
}

void			ft_sig_handler_pid(int sig)
{
	if (sig == SIGINT)
	{
		signal(SIGINT, SIG_IGN);
		kill(ft_pid_tmp(0), SIGKILL);
		ft_putchar('\n');
	}
}

void			ft_signal_pid(pid_t pid)
{
	ft_pid_tmp(pid);
	signal(SIGINT, ft_sig_handler_pid);
}
