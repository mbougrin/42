/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:24:01 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/23 19:44:32 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void			ft_lst_move(t_lst **alst)
{
	t_lst	*tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->prev)
	{
		if (tmp->prev->number_ants != 0)
		{
			tmp->number_ants = tmp->prev->number_ants;
			tmp->prev->number_ants = 0;
			ft_print_move_ants(tmp, 0);
		}
		tmp = tmp->prev;
	}
}

int				ft_check_lst_ants(t_lst *alst)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = alst;
	while (tmp)
	{
		if (tmp->number_ants != 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void			ft_lst_move_ants(t_lst **alst, int ants)
{
	t_lst	*tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->number_ants != 0)
		tmp->number_ants = 0;
	while (tmp->prev)
	{
		if (tmp->prev->number_ants != 0)
		{
			tmp->number_ants = tmp->prev->number_ants;
			tmp->prev->number_ants = 0;
			if (tmp->prev->prev != NULL)
				ft_print_move_ants(tmp, 0);
			else
				ft_print_move_ants(tmp, 0);
		}
		tmp = tmp->prev;
		if (tmp == *alst)
			break ;
	}
	if (ants == 0 && ft_check_lst_ants(*alst) > 0)
		ft_putchar('\n');
}

void			ft_move_ants(t_stc *stc, t_lst *alst)
{
	int		ants;

	ants = 0;
	while (1)
	{
		if (stc->ants > 0)
		{
			ants++;
			stc->ants--;
			ft_lst_move(&alst);
			alst->number_ants = ants;
			ft_print_move_ants(alst, 1);
		}
		else
			ft_lst_move_ants(&alst, stc->ants);
		if (stc->ants == 0 && ft_check_lst_ants(alst) == 0)
			break ;
	}
}

void			ft_lemin(char **map)
{
	t_stc		*stc;
	t_lst		*alst;
	int			i;

	alst = NULL;
	while (map[i])
	{
		if (map[i][0] != '#')
			break ;
		i++;
	}
	stc = (t_stc *)malloc(sizeof(t_stc));
	stc->map = map;
	stc->ants = ft_atoi(map[i]);
	stc->start = ft_create_start(map);
	stc->end = ft_create_end(map);
	ft_lst_map(&alst, map, stc->start, stc->end);
	ft_move_ants(stc, alst);
	ft_strdel(&stc->start);
	ft_strdel(&stc->end);
	free(stc);
	ft_strstrdel(map);
}
