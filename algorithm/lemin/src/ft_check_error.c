/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 18:00:28 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/23 18:55:36 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		ft_check_start_room(char **map, int i)
{
	i++;
	while (map[i])
	{
		if (map[i][0] != '#')
			break ;
		if (ft_strstr(map[i], "##end") != NULL)
			return (-1);
		i++;
	}
	return (i);
}

static int		ft_check_end_room(char **map, int i)
{
	i++;
	while (map[i])
	{
		if (map[i][0] != '#')
			break ;
		if (ft_strstr(map[i], "##start") != NULL)
			return (-1);
		i++;
	}
	return (i);
}

static int		ft_check_room(char **map)
{
	int		i;
	int		len;

	len = i = 0;
	while (map[i])
	{
		if (ft_strstr(map[i], "##start") != NULL)
		{
			i = ft_check_start_room(map, i);
			if (i == -1)
				return (-1);
		}
		if (ft_strstr(map[i], "##end") != NULL)
		{
			i = ft_check_end_room(map, i);
			if (i == -1)
				return (-1);
		}
		if (map[i][0] != '#' && ft_strchr(map[i], '-') == NULL)
			len++;
		i++;
	}
	if (len > 2)
		return (0);
	return (-1);
}

int				ft_check_error(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '#')
			break ;
		i++;
	}
	if (map == NULL)
		return (-1);
	if (ft_atoi(map[i]) <= 0 || ft_atoi(map[i]) > 2147483647)
		return (-1);
	if (ft_check_start(map) == -1)
		return (-1);
	if (ft_check_end(map) == -1)
		return (-1);
	if (ft_check_tube(map) == -1)
		return (-1);
	if (ft_check_room(map) == -1)
		return (-1);
	return (0);
}
