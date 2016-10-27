/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 14:15:30 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/23 19:44:25 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

char			*ft_create(char *s)
{
	int		len;

	len = 0;
	while (s[len])
	{
		if (s[len] == ' ')
			break ;
		len++;
	}
	return (ft_strsub(s, 0, len));
}

char			*ft_create_start(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strstr(map[i], "##start") != NULL)
		{
			while (map[i])
			{
				if (map[i][0] != '#')
					break ;
				i++;
			}
			break ;
		}
		i++;
	}
	return (ft_create(map[i]));
}

char			*ft_create_end(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strstr(map[i], "##end") != NULL)
		{
			while (map[i])
			{
				if (map[i][0] != '#')
					break ;
				i++;
			}
			break ;
		}
		i++;
	}
	return (ft_create(map[i]));
}

char			*ft_create_next(char *map, char *next)
{
	int		i;
	char	*tmp;
	int		len;

	len = i = 0;
	if (ft_strncmp(map, next, ft_strlen(next)) == 0)
		i = ft_strlen(next) + 1;
	len = ft_strlen(map) - ft_strlen(next) - 1;
	tmp = ft_strsub(map, i, len);
	return (tmp);
}

int				ft_map(char **map, char *start, char *end)
{
	char	*next;
	char	*tmp;
	int		i;

	next = start;
	i = 0;
	while (map[i])
	{
		if (ft_strstr(map[i], next) != NULL && ft_strchr(map[i], '-') != NULL)
		{
			if (ft_strstr(map[i], end) != NULL \
					&& ft_strchr(map[i], '-') != NULL)
				return (0);
			tmp = next;
			next = ft_create_next(map[i], next);
			ft_strdel(&tmp);
			if (ft_check_access_room(next, map) == -1)
				return (-1);
			map[i][0] = '\0';
			i = 0;
		}
		i++;
	}
	return (-1);
}
