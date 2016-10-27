/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:49:33 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:49:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_resize(t_ncs **ncs, int nb)
{
	int		i[7];

	i[1] = SIZE_MAP;
	i[2] = SIZE_MAP;
	i[5] = LINES / SIZE_MAP;
	i[6] = COLS / SIZE_MAP;
	i[0] = 0;
	i[3] = 0;
	i[4] = 0;
	while (i[0] < nb)
	{
		wclear(ncs[i[0]]->win);
		mvwin(ncs[i[0]]->win, i[3], i[4]);
		wresize(ncs[i[0]]->win, i[5], i[6]);
		i[4] += i[6];
		i[0]++;
		if (i[0] == i[2])
		{
			i[4] = 0;
			i[3] += i[5];
			i[2] += i[1];
		}
	}
}
