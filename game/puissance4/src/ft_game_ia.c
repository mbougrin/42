/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_ia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 16:55:18 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/09 19:26:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_power_four.h>

static int		ft_map_len(char **map)
{
	int		count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

static int		ft_check_game(char **map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '.' && map[y + 1][x] != '.' \
					&& map[y + 1][x] != '|')
			{
				map[y][x] = 'x';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int		ft_check_first(char **map, int map_len)
{
	if (map[map_len - 1][1] == '.')
	{
		map[map_len - 1][1] = 'x';
		return (1);
	}
	return (0);
}

static int		ft_check(int x, int y, char **map)
{
	if (y != 0 && map[y][x] == '.')
	{
		map[y][x] = 'x';
		return (1);
	}
	while (y != -1)
	{
		if (y != 0 && map[y][x] == 'x' && map[y - 1][x] == '.')
		{
			map[y - 1][x] = 'x';
			return (1);
		}
		else if (y != 0 && map[y][x] == 'o' && map[y - 1][x] == '.')
			break ;
		y--;
	}
	return (0);
}

void			ft_game_ia(char **map)
{
	int		map_len;
	int		y;
	int		x;

	map_len = ft_map_len(map);
	x = 0;
	if (ft_check_first(map, map_len) == 1)
		return ;
	y = map_len - 1;
	while (map[y][x] != '\0')
	{
		if (ft_check(x, y, map) == 1)
			return ;
		y = map_len - 1;
		x++;
	}
	ft_check_game(map);
}
