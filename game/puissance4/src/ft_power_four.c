/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:36:58 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/09 15:17:33 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_power_four.h>

static char		**ft_create_map(int line, int column)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = ft_strstrnew(column);
	while (i < column)
	{
		j = 0;
		map[i] = ft_strnew((line * 2) + 1);
		while (j < (line * 2) + 1)
		{
			if (j % 2 == 0)
				map[i][j] = '|';
			else
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void		ft_print(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
		if (s[i] == '\0')
			break ;
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

void			ft_print_map(char **map, int column)
{
	int		i;

	i = 1;
	while (i < column)
	{
		ft_putchar(' ');
		ft_putnbr(i);
		if (i < 10)
			ft_putstr("  ");
		if (i >= 10)
			ft_putstr(" ");
		i++;
	}
	ft_putstr(" ");
	ft_putnbr(i);
	ft_putchar('\n');
	i = 0;
	while (map[i])
	{
		ft_print(map[i]);
		i++;
	}
}

int				main(int ac, char **av)
{
	char	**map;
	int		column;
	int		line;

	if (ac < 3)
		ft_putendl("too few arguments");
	else if (ac > 3)
		ft_putendl("too many arguments");
	else
	{
		line = ft_atoi(av[2]);
		column = ft_atoi(av[1]);
		if (line < 6)
			line = 6;
		if (column < 7)
			column = 7;
		map = ft_create_map(line, column);
		ft_putendl("Player == O && IA == X");
		ft_game(map, line);
		ft_strstrdel(map);
	}
	return (0);
}
