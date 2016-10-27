/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_artificial_intelligence.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 23:22:42 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/09 19:26:54 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_power_four.h>

int				ft_check_win(int player, char **map)
{
	char	c;

	if (player == 1)
		c = 'o';
	if (player == 0)
		c = 'x';
	if (ft_check_column(map, c) == 0 || ft_check_line(map, c) == 0
			|| ft_check_diagonal_right(map, c) == 0 \
			|| ft_check_diagonal_left(map, c) == 0)
	{
		ft_putstr("Win ");
		if (player == 1)
			ft_putendl("player");
		else
			ft_putendl("IA");
		return (0);
	}
	return (1);
}

int				ft_play_player_one(char **map, int column)
{
	int		i;

	i = 0;
	if (map[i][column * 2 - 1] == '.' && ((int)ft_strlen(map[0]) / 2) >= column)
	{
		while (map[i])
		{
			if (map[i + 1][column * 2 - 1] == '.')
					i++;
			else
				break ;
			if (map[i + 1] == NULL)
				break ;
		}
	}
	else
		return (ft_map_error());
	map[i][column * 2 - 1] = 'o';
	return (0);
}

void			ft_game_player(char **map, int player)
{
	char	*line;

	if (player == 0)
		ft_game_ia(map);
	else
	{
		get_next_line(0, &line);
		if (ft_play_player_one(map, ft_atoi(line)) != 0)
		{
			ft_strdel(&line);
			ft_game_player(map, player);
		}
		ft_strdel(&line);
	}
}

int				ft_check_play(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
