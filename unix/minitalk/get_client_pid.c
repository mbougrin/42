/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_client_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 17:22:48 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/07 20:36:06 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <libft.h>

int					g_tab[32];

static int	get_index(int mode)
{
	static int	index = 0;

	if (mode == -1)
		index = 0;
	else if (mode == 1)
		index = index + 1;
	return (index);
}

static int	convert_tab(int *tab)
{
	int			result;
	int			i;
	int			mult;

	result = 0;
	i = 0;
	mult = 1;
	while (i < 32)
	{
		result = result + (tab[31 - i] * mult);
		i = i + 1;
		mult = mult * 2;
	}
	get_index(-1);
	return (result);
}

static void	fill_tab(int sig)
{
	if (sig == SIGTERM)
		g_tab[get_index(0)] = 0;
	else if (sig == SIGBUS)
		g_tab[get_index(0)] = 1;
	get_index(1);
	signal(sig, &fill_tab);
}

static int	init_client_pid(void)
{
	signal(SIGTERM, &fill_tab);
	signal(SIGBUS, &fill_tab);
	get_index(-1);
	while (get_index(0) != 32)
		pause();
	return (convert_tab(g_tab));
}

int			get_client_pid(int mode)
{
	static int		client_pid = 0;

	if (mode == 1)
	{
		client_pid = init_client_pid();
		return (client_pid);
	}
	else
		return (client_pid);
}
