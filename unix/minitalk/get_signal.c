/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:17:14 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/07 20:36:28 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <libft.h>

char				*g_string = NULL;

static void	add_in_string(char c)
{
	char	*tmp;

	if (g_string == NULL)
	{
		if ((g_string = ft_strnew(1)) == NULL)
			return ;
	}
	if ((tmp = ft_strnew(2)) == NULL)
		return ;
	tmp[0] = c;
	ft_str_realloc_cat(&g_string, tmp);
	free(tmp);
}

static void print_string(int sig)
{
	if (g_string == NULL)
	{
		signal(sig, &print_string);
		return ;
	}
	ft_putendl(g_string);
	free(g_string);
	g_string = NULL;
	get_client_pid(1);
	signal(sig, &print_string);
}

static void	print_char(int *tab, int size)
{
	char			to_print;
	int				i;
	int				mult;

	to_print = 0;
	i = 0;
	mult = 1;
	while (i < size)
	{
		to_print = to_print + ((tab)[size - i - 1] * mult);
		i = i + 1;
		mult = mult * 2;
	}
	add_in_string(to_print);
}

static void	input_signal(int sig)
{
	static int		tab[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
	static int		i = 0;

	if (sig == SIGUSR1)
		tab[i] = 0;
	else if (sig == SIGUSR2)
		tab[i] = 1;
	i = i + 1;
	if (i == 8)
	{
		i = 0;
		print_char(tab, 8);
	}
	signal(sig, &input_signal);
	kill(get_client_pid(0), SIGUSR1);
}

void		get_signal(void)
{
	signal(SIGUSR1, &input_signal);
	signal(SIGUSR2, &input_signal);
	signal(SIGWINCH, &print_string);
	while (1)
	{
		pause();
	}
}
