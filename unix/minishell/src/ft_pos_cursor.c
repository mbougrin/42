/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 09:32:22 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/09 12:28:38 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_check_end(int nb)
{
	int		i;
	int		cursor;

	i = 0;
	cursor = ft_pos_cursor("size");
	if (cursor >= nb)
		return ;
	while (cursor < nb)
	{
		cursor++;
		i++;
		ft_pos_cursor("more");
	}
	ft_move_right(i);
}

void			ft_check_move_right(int nb)
{
	if (ft_pos_cursor("size") < nb)
	{
		tputs(tgetstr("nd", NULL), 1, t_putchar);
		ft_pos_cursor("more");
	}
}

void			ft_check_move_left(int nb)
{
	if (ft_pos_cursor("size") > 0 && ft_pos_cursor("size") <= nb)
	{
		tputs(tgetstr("le", NULL), 1, t_putchar);
		ft_pos_cursor("less");
	}
}

int				ft_pos_cursor(char *s)
{
	static int		cursor;

	if (ft_strcmp(s, "zero") == 0)
		cursor = 0;
	else if (ft_strcmp(s, "more") == 0)
		cursor++;
	else if (ft_strcmp(s, "less") == 0 && cursor > 0)
		cursor--;
	return (cursor);
}
