/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 16:18:12 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/07 20:36:26 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <signal.h>
#include "client.h"

static void	init_tab(char c, int *tab)
{
	int		i;

	i = 0;
	while (i <= 7)
	{
		tab[7 - i] = c % 2;
		c = c / 2;
		i = i + 1;
	}
}

static void	send_char(int pid, char c)
{
	int		tab[8];
	int		i;

	init_tab(c, tab);
	i = 0;
	while (i < 8)
	{
		if (tab[i] == 1)
			kill(pid, SIGUSR2);
		else if (tab[i] == 0)
			kill(pid, SIGUSR1);
		while (set_var(-1) == 0)
			pause();
		set_var(0);
		i = i + 1;
	}
}

static void	send_string(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i = i + 1;
	}
	kill(pid, SIGWINCH);
}

int			main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putendl_fd("Error, incorrect arguments number", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_pid(pid);
	signal(SIGUSR1, &handler);
	send_string(pid, argv[2]);
	return (0);
}
