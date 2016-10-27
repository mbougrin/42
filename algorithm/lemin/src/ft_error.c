/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 13:41:56 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/23 19:42:56 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				ft_check_start(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strstr(map[i], "##start") != NULL)
				return (0);
		i++;
	}
	return (-1);
}

int				ft_check_access_room(char *next, char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], next, ft_strlen(next)) == 0 \
				&& ft_strchr(map[i], '-') == NULL)
			return (0);
		i++;
	}
	return (-1);
}

int				ft_check_end(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strstr(map[i], "##end") != NULL)
				return (0);
		i++;
	}
	return (-1);
}

int				ft_check_tube(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], '-') != NULL)
				return (0);
		i++;
	}
	return (-1);
}
