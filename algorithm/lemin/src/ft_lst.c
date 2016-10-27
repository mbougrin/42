/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:29:59 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/23 19:43:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void			ft_lst_map(t_lst **alst, char **map, char *start, char *end)
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
			if (ft_strstr(map[i], end) != NULL)
			{
				lst_add(alst, ft_strdup(end));
				return ;
			}
			tmp = next;
			next = ft_create_next(map[i], next);
			lst_add(alst, ft_strdup(next));
			ft_strdel(&tmp);
			map[i][0] = '\0';
			i = 0;
		}
		i++;
	}
	ft_strstrdel(map);
}

t_lst			*lst_new(char *room)
{
	t_lst		*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->number_ants = 0;
	new->room = ft_strdup(room);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void			lst_add(t_lst **alst, char *room)
{
	t_lst	*tmp;

	if (*alst == NULL)
		*alst = lst_new(room);
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = lst_new(room);
		tmp->next->prev = tmp;
	}
}

int				ft_check_map(char **map)
{
	char	*start;
	char	*end;

	start = NULL;
	end = NULL;
	start = ft_create_start(map);
	end = ft_create_end(map);
	if (ft_map(map, start, end) == -1)
	{
		ft_strstrdel(map);
		return (-1);
	}
	ft_strstrdel(map);
	return (0);
}

void			ft_print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
	ft_putchar('\n');
}
