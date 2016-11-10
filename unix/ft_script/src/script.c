/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:39:28 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 23:34:27 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				createptyandtty(void)
{
	static char			ptsname[128];
	struct stat			sbuf;
	char				*ret;
	t_opt				*opt;

	opt = singleton(NULL);
	ret = NULL;
	if ((opt->master = open("/dev/ptmx", O_RDWR)) == -1)
		openerror();
	if (ioctl(opt->master, TIOCPTYGRANT) == -1)
		ioctlerror();
	if (ioctl(opt->master, TIOCPTYUNLK) == -1)
		ioctlerror();
	if (ioctl(opt->master, TIOCPTYGNAME, ptsname) == -1)
		ioctlerror();
	if (stat(ptsname, &sbuf) == -1)
		staterror();
	ret = ptsname;
	if ((opt->slave = open(ret, O_RDWR)) == -1)
		openerror();
}

void				script(void)
{
	int		pid;
	t_opt	*opt;

	opt = singleton(NULL);
	createptyandtty();
	initterm();
	ft_signal(SIGCHLD, sigchild);
	if ((pid = fork()) == -1)
		forkerror();
	if (pid == 0)
		child();
	else
	{
		close(opt->slave);
		father(pid);
	}
}
