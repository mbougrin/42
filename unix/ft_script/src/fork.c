/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:23:06 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 23:38:07 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void				input(int pid)
{
	t_opt				*opt;
	char				buff[4096];

	opt = singleton(NULL);
	opt->pid = pid;
	ft_signal(SIGWINCH, sigwinch);
	sigwinch(0);
	while (1)
	{
		ft_bzero(buff, 4096);
		if ((read(0, buff, 4096)) == -1)
			checkend(pid);
		ft_putstr_fd(buff, opt->master);
	}
}

static void				output(void)
{
	char				buff[4096];
	t_opt				*opt;

	opt = singleton(NULL);
	ft_signal(SIGUSR1, sigusr1);
	while (1)
	{
		ft_bzero(buff, 4096);
		if ((read(opt->master, buff, 4096)) == -1)
			checkend(0);
		ft_putstr_fd(buff, 1);
		ft_putstr_fd(buff, opt->fd);
	}
}

void					father(int pid_child)
{
	int					pid;
	t_opt				*opt;

	opt = singleton(NULL);
	if ((pid = fork()) == -1)
	{
		kill(pid_child, SIGKILL);
		if (opt->initterm == true)
			resetterm();
		freeopt();
		exit(-1);
	}
	if (pid == 0)
		output();
	else
		input(pid);
}

void					child(void)
{
	t_opt				*opt;

	opt = singleton(NULL);
	close(opt->master);
	close(opt->fd);
	ft_execve();
}
