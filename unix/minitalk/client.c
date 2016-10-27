/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 17:15:00 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/07 20:35:35 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <signal.h>
#include "client.h"

static void	init_tab(int pid, int *tab)
{
	int		i;

	i = 0;
	while (i < 32)
	{
		tab[31 - i] = pid % 2;
		pid = pid / 2;
		i = i + 1;
	}
}

void		send_pid(int pid_server)
{
	int		tab[32];
	int		i;

	init_tab(getpid(), tab);
	i = 0;
	while (i < 32)
	{
		if (tab[i] == 1)
			kill(pid_server, SIGBUS);
		else if (tab[i] == 0)
			kill(pid_server, SIGTERM);
		usleep(2000);
		i = i + 1;
	}
}

int			set_var(int mode)
{
	static int		var = 0;

	if (mode == -1)
		return (var);
	else
		var = mode;
	return (var);
}

void		handler(int sig)
{
	set_var(1);
	signal(sig, &handler);
}
