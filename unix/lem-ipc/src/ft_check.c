/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:43:14 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:45:27 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int				ft_check_player_one(char *map, int i, int len)
{
	int		dead;

	dead = 0;
	if (i > (SIZE_MAP + 1) && map[i - (SIZE_MAP + 1)] == '2')
		dead++;
	if ((i - (SIZE_MAP + 1)) > 0 && map[(i - (SIZE_MAP + 1)) - 1] == '2')
		dead++;
	if (i > (SIZE_MAP + 1) && map[(i - (SIZE_MAP + 1)) + 1] == '2')
		dead++;
	if (i > 0 && map[i - 1] == '2')
		dead++;
	if (map[i + 1] == '2')
		dead++;
	if ((i + (SIZE_MAP + 1)) < len && map[i + (SIZE_MAP + 1)] == '2')
		dead++;
	if ((i + (SIZE_MAP + 1)) < len && map[(i + (SIZE_MAP + 1)) - 1] == '2')
		dead++;
	if ((i + (SIZE_MAP + 1)) < len && map[i + (SIZE_MAP + 2)] == '2')
		dead++;
	if (dead == 2)
		return (1);
	return (0);
}

int				ft_check_player_two(char *map, int i, int len)
{
	int		dead;

	dead = 0;
	if (i > (SIZE_MAP + 1) && map[i - (SIZE_MAP + 1)] == '1')
		dead++;
	if ((i - (SIZE_MAP + 1)) > 0 && map[(i - (SIZE_MAP + 1)) - 1] == '1')
		dead++;
	if (i > (SIZE_MAP + 1) && map[(i - (SIZE_MAP + 1)) + 1] == '1')
		dead++;
	if (i > 0 && map[i - 1] == '1')
		dead++;
	if (map[i + 1] == '1')
		dead++;
	if ((i + (SIZE_MAP + 1)) < len && map[i + (SIZE_MAP + 1)] == '1')
		dead++;
	if ((i + (SIZE_MAP + 1)) < len && map[(i + (SIZE_MAP + 1)) - 1] == '1')
		dead++;
	if ((i + (SIZE_MAP + 1)) < len && map[i + (SIZE_MAP + 2)] == '1')
		dead++;
	if (dead == 2)
		return (1);
	return (0);
}

int				ft_defeat(char *map)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(map);
	while (map[i])
	{
		if (map[i] == '1')
		{
			if (ft_check_player_one(map, i, len) == 1)
				return (1);
		}
		else if (map[i] == '2')
		{
			if (ft_check_player_two(map, i, len) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int				ft_check_rand(char *map, char c, int i, int rnd)
{
	rnd = rand() % 4;
	if (rnd == 0 && (i > (SIZE_MAP + 1)) && map[i - (SIZE_MAP + 1)] == '0')
	{
		map[i - (SIZE_MAP + 1)] = c;
		return (1);
	}
	else if (rnd == 1 && map[i + (SIZE_MAP + 1)] == '0')
	{
		map[i + (SIZE_MAP + 1)] = c;
		return (1);
	}
	else if (rnd == 2 && i > 1 && map[i - 1] == '0')
	{
		map[i - 1] = c;
		return (1);
	}
	else if (rnd == 3 && map[i + 1] == '0')
	{
		map[i + 1] = c;
		return (1);
	}
	return (0);
}
