/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmesas <kmesas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:09:36 by kmesas            #+#    #+#             */
/*   Updated: 2015/05/03 21:15:13 by kmesas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_circle		*ft_crl(t_circle *circle)
{
	static t_circle	*tmp;

	if (circle != NULL)
		tmp = circle;
	return (tmp);
}

t_stc			*ft_stc(t_stc *stc)
{
	static t_stc	*tmp;

	if (stc != NULL)
		tmp = stc;
	return (tmp);
}

void			ft_check_col(t_map **map, t_circle *crl)
{
	int	i;
	int	j;

	i = 2;
	while (i > -1)
	{
		j = 0;
		while (j < 11)
		{
			if (map[i][j].hr + 0.88 <= crl->pos
				&& map[i][j].left <= (crl->pos_v * -1)
				&& map[i][j].right >= (crl->pos_v * -1) && map[i][j].block > 0)
			{
				if (map[i][j].block < 4 && map[i][j].block > 0)
					map[i][j].block -= 1;
				crl->move_h = 1;
				return ;
			}
			j++;
		}
		i--;
	}
}
