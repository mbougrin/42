/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 08:20:07 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/09 19:26:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_power_four.h>

int				ft_map_error(void)
{
	ft_putendl("output of the map");
	return (1);
}

int				ft_check_column(char **map, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		if (map[i + 3] == NULL)
			break ;
		if (map[i][j] == c && map[i + 1][j] == c && map[i + 2][j] == c \
				&& map[i + 3][j] == c)
				return (0);
		j++;
		if (map[i][j + 1] == '\0')
		{
			j = 0;
			i++;
		}
	}
	return (1);
}

int				ft_check_line(char **map, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (map[i] != NULL)
	{
		if (map[i][j] == c && map[i][j + 2] == c && map[i][j + 4] == c\
				&& map[i][j + 6] == c)
				return (0);
		j += 2;
		if (map[i][j + 6] == '\0')
		{
			j = 1;
			i++;
		}
	}
	return (1);
}

int				ft_check_diagonal_right(char **map, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][j] == c && map[i + 1][j + 2] == c && map[i + 2][j + 4] == c \
				&& map[i + 3][j + 6] == c)
			return (0);
		j++;
		if (map[i][j + 5] == '\0')
		{
			j = 0;
			i++;
		}
		if (map[i + 3] == NULL)
			break ;
	}
	return (1);
}

int				ft_check_diagonal_left(char **map, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 7;
	while (map[i])
	{
		if (map[i][j] == c && map[i + 1][j - 2] == c && map[i + 2][j - 4] == c \
				&& map[i + 3][j - 6] == c)
			return (0);
		j++;
		if (map[i][j + 1] == '\0')
		{
			j = 7;
			i++;
		}
		if (map[i + 3] == NULL)
			break ;
	}
	return (1);
}
