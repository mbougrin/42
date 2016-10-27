/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:02:22 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/26 09:07:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				ft_check_pos_piece(t_filler *stc)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	pos = 0;
	while (stc->piece[i])
	{
		j = 0;
		while (stc->piece[i][j])
		{
			if (ft_check_valid(stc->piece[i][j], \
						stc->map[stc->i + i][stc->j + j]) == 2)
			{
				pos++;
				if (stc->c != stc->map[stc->i + i][stc->j + j] \
						&& stc->b != stc->map[stc->i + i][stc->j + j])
					pos++;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

void			ft_check_coor_first(t_filler *stc)
{
	stc->i = 0;
	stc->j = 0;
	stc->pos = 0;
	while (stc->pos != 1)
	{
		stc->pos = ft_check_pos_piece(stc);
		if (stc->pos == 1)
		{
			stc->x_coor = stc->j;
			stc->y_coor = stc->i;
			stc->pos = 0;
		}
		stc->j++;
		if ((stc->x_piece + stc->j) > stc->x_map)
		{
			stc->i++;
			stc->j = 0;
		}
		else if ((stc->y_piece + stc->i) >= stc->y_map)
			break ;
	}
}

void			ft_check_coor_end(t_filler *stc)
{
	stc->i = 0;
	stc->j = 0;
	stc->pos = 0;
	while (stc->pos != 1)
	{
		stc->pos = ft_check_pos_piece(stc);
		if (stc->pos == 1)
		{
			stc->x_coor = stc->j;
			stc->y_coor = stc->i;
			break ;
		}
		stc->j++;
		if ((stc->x_piece + stc->j) > stc->x_map)
		{
			stc->i++;
			stc->j = 0;
		}
		else if ((stc->y_piece + stc->i) >= stc->y_map)
			break ;
	}
}
