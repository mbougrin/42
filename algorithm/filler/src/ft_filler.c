/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 00:46:16 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/26 05:46:26 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void			ft_play(t_filler *stc)
{
	ft_putnbr(stc->y_coor);
	ft_putchar(' ');
	ft_putnbr(stc->x_coor);
	ft_putchar('\n');
}

void			ft_creat_piece(t_filler *stc)
{
	stc->i = stc->y_piece;
	stc->j = 0;
	stc->piece = ft_strstrnew(stc->y_piece + 1);
	while (stc->i > stc->j)
	{
		get_next_line(0, &stc->line);
		stc->piece[stc->j] = ft_strdup(stc->line);
		stc->j++;
		ft_strdel(&stc->line);
	}
	stc->piece[stc->j] = NULL;
	stc->j = 0;
	stc->i = 0;
}

void			ft_creat_coor(t_filler *stc)
{
	get_next_line(0, &stc->line);
	stc->split = ft_strsplit(stc->line, ' ');
	stc->y_piece = ft_atoi(stc->split[1]);
	stc->x_piece = ft_atoi(stc->split[2]);
	ft_strstrdel(stc->split);
	ft_strdel(&stc->line);
}

void			ft_creat_map(t_filler *stc)
{
	stc->i = stc->y_map;
	stc->j = 0;
	stc->map = ft_strstrnew(stc->y_map + 1);
	while (stc->i > stc->j)
	{
		get_next_line(0, &stc->line);
		stc->map[stc->j] = ft_strsub(stc->line, 4, (ft_strlen(stc->line) - 4));
		stc->j++;
		ft_strdel(&stc->line);
	}
	stc->map[stc->j] = NULL;
	stc->j = 0;
	stc->i = 0;
}

void			ft_player(t_filler *stc)
{
	if (stc->player == 1)
	{
		stc->c = 'o';
		stc->b = 'O';
	}
	else if (stc->player == 2)
	{
		stc->c = 'x';
		stc->b = 'X';
	}
}
