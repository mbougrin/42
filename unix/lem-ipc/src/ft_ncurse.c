/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 06:48:08 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:53:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_refresh(t_ncs **ncs, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		wrefresh(ncs[i]->win);
		i++;
	}
}

void			ft_clear(t_ncs **ncs, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		wclear(ncs[i]->win);
		i++;
	}
}

void			ft_print_map(t_ncs **ncs, char *map)
{
	ft_clear(ncs, SHMSZ);
	ft_check_color(ncs, SHMSZ, map);
	ft_init_background(ncs, SHMSZ);
	ft_refresh(ncs, SHMSZ);
}

void			ft_free_ncs(t_ncs **ncs, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		delwin(ncs[i]->win);
		free(ncs[i]);
		i++;
	}
	free(ncs);
}

void			ft_check_color(t_ncs **ncs, int nb, char *map)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 1;
	while (i < nb)
	{
		if (map[j] == '\n')
			j++;
		tmp = map[j] - 48;
		if (tmp == 0)
			ncs[i]->color = 3;
		else if (tmp == 1)
			ncs[i]->color = 4;
		else if (tmp == 2)
			ncs[i]->color = 5;
		j++;
		i++;
	}
	map = map;
}
