/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 22:33:16 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 07:48:01 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

pid_t			ft_stock_pid(pid_t pid)
{
	pid_t	pid_tmp;

	if (pid != 0)
		pid_tmp = pid;
	return (pid_tmp);
}

void			ft_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		signal(SIGINT, SIG_IGN);
		kill(ft_stock_pid(0), SIGKILL);
		ft_putchar('\n');
	}
}

void			ft_signal_pid(pid_t pid)
{
	ft_stock_pid(pid);
	signal(SIGINT, ft_sig_handler);
}

void			ft_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		ft_prompt();
	}
}

void			ft_signal(void)
{
	signal(SIGINT, ft_handler);
	signal(SIGTSTP, SIG_IGN);
}
