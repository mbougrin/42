/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 20:25:48 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/01 06:45:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_check_color(t_stc **stc, int i)
{
	if (stc[i]->val == 0)
		init_pair(stc[i]->color, 15, 250);
	if (stc[i]->val == 2)
		init_pair(stc[i]->color, 16, 229);
	if (stc[i]->val == 4)
		init_pair(stc[i]->color, 15, 214);
	if (stc[i]->val == 8)
		init_pair(stc[i]->color, 15, 208);
	if (stc[i]->val == 16)
		init_pair(stc[i]->color, 15, 202);
	if (stc[i]->val == 32)
		init_pair(stc[i]->color, 15, 93);
	if (stc[i]->val == 64)
		init_pair(stc[i]->color, 15, 92);
	if (stc[i]->val == 128)
		init_pair(stc[i]->color, 15, 91);
	if (stc[i]->val == 256)
		init_pair(stc[i]->color, 15, 90);
	if (stc[i]->val == 512)
		init_pair(stc[i]->color, 15, 89);
	if (stc[i]->val == 1024)
		init_pair(stc[i]->color, 15, 88);
}

void			ft_init_color(t_stc **stc, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_check_color(stc, i);
		i++;
	}
}

void			ft_init_background(t_stc **stc, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		wbkgd(stc[i]->win, COLOR_PAIR(stc[i]->color));
		i++;
	}
}

void			ft_write_nb(t_stc **stc, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		mvwprintw(stc[i]->win, stc[i]->x / 2, stc[i]->y / 2, \
				"%d", stc[i]->val);
		i++;
	}
}

void			ft_write_space(t_stc **stc, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		mvwprintw(stc[i]->win, stc[i]->x / 2, stc[i]->y / 2, \
				"%s", "    ");
		i++;
	}
}
