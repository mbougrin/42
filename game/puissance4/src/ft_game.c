/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 22:33:55 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/09 19:26:57 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_power_four.h>

static int		ft_random_number(void)
{
	srand(time(NULL));
	return ((rand() % (100 - 0 + 1)) + 0);
}

static void		ft_game_power_four(char **map, int line, int player)
{
	int		turn;

	turn = player;
	while (ft_check_win(player, map) != 0)
	{
		if (ft_check_play(map) == 0)
			return (ft_putendl("draw"));
		ft_print_map(map, line);
		if (turn % 2 == 0)
		{
			player = 0;
			ft_game_player(map, 0);
		}
		else
		{
			player = 1;
			ft_putstr("your turn game: ");
			ft_game_player(map, 1);
		}
		turn++;
	}
	ft_print_map(map, line);
}

void			ft_game(char **map, int line)
{
	int		nb;

	nb = 0;
	nb = ft_random_number();
	if (nb % 2 == 0)
		ft_game_power_four(map, line, (nb % 2));
	else
		ft_game_power_four(map, line, (nb % 2));
}
