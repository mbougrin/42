/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:23:48 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/23 19:46:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static char		**ft_new_map(char **map, int len, char *line)
{
	map = ft_strstrnew(len + 1);
	map[0] = line;
	map[1] = NULL;
	return (map);
}

static char		**ft_copy(char *line, char **tmp, int i)
{
	static int		len;
	static char		**map;

	if (map != NULL && line == NULL && len != 0)
		return (map);
	len++;
	if (len > 1)
	{
		tmp = map;
		map = ft_strstrnew(len + 1);
		while (tmp[i])
		{
			map[i] = ft_strdup(tmp[i]);
			i++;
		}
		map[i] = line;
		map[i + 1] = NULL;
		ft_strstrdel(tmp);
	}
	else
		map = ft_new_map(map, len, line);
	return (map);
}

static char		**ft_len_read(void)
{
	char	**tmp;
	char	*line;
	int		len;

	tmp = NULL;
	len = 0;
	while (get_next_line(0, &line) != 0)
	{
		ft_copy(line, tmp, 0);
		len++;
	}
	if (len == 0)
		return (NULL);
	return (ft_copy(NULL, tmp, 0));
}

int				main(void)
{
	char	**map;

	map = ft_len_read();
	if (map == NULL)
	{
		ft_putendl("ERROR");
		return (0);
	}
	if (ft_check_error(map) == -1)
	{
		ft_putendl("ERROR");
		ft_strstrdel(map);
		return (0);
	}
	if (ft_check_map(ft_strstrdup(map)) == -1)
	{
		ft_putendl("ERROR");
		ft_strstrdel(map);
		return (0);
	}
  	ft_print_map(map);
	ft_lemin(ft_strstrdup(map));
	ft_strstrdel(map);
	return (0);
}
