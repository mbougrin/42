/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:15:02 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 18:34:53 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				sigusr1(int sig)
{
	t_opt				*opt;

	opt = singleton(NULL);
	(void)sig;
	close(opt->fd);
	resetterm();
	freeopt();
	exit(-1);
}

void				sigwinch(int sig)
{
	t_opt				*opt;
	struct winsize		ws;

	opt = singleton(NULL);
	(void)sig;
	signal(SIGWINCH, sigwinch);
	if ((ioctl(0, TIOCGWINSZ, &ws)) != -1)
		ioctl(opt->master, TIOCSWINSZ, &ws);
}

void				ft_signal(int s, void (*func)(int))
{
	struct sigaction	sa;
	struct sigaction	osa;
	sigset_t			sigintr;

	sigintr = 0;
	sa.sa_handler = func;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (!sigismember(&sigintr, s))
		sa.sa_flags |= SA_RESTART;
	if (sigaction(s, &sa, &osa) < 0)
		return ;
}

void				sigchild(int sig)
{
	t_opt				*opt;

	opt = singleton(NULL);
	(void)sig;
	if (!opt->q)
		ft_putchar_fd('\n', 1);
	if (opt->pid)
		checkend(opt->pid);
	else
		checkend(0);
}
