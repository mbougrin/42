/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 12:28:08 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/09 15:21:52 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_copy_cursor_end(char **line, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	i = ft_strlen(*line);
	tmp = *line;
	*line = ft_strnew(i + 2);
	*line = ft_strdup(tmp);
	line[0][i] = c;
	ft_strdel(&tmp);
	line[0][i + 1] = '\0';
}

void			ft_copy_pos_cursor(char **line, char c)
{
	int		move;
	char	*tmp;
	char	*line_tmp;

	move = 0;
	tmp = line[0];
	line_tmp = ft_strdup(tmp);
	line[0][ft_pos_cursor("size")] = c;
	line[0][ft_pos_cursor("size") + 1] = '\0';
	line[0] = ft_strjoin(tmp, &line_tmp[ft_pos_cursor("size")]);
	ft_strdel(&tmp);
	ft_strdel(&line_tmp);
	ft_pos_cursor("more");
	move = ft_pos_cursor("size") + 1;
	tputs(tgetstr("rc", NULL), 1, t_putchar);
	ft_putstr(*line);
	tputs(tgetstr("rc", NULL), 1, t_putchar);
	move = 0;
	while (move < ft_pos_cursor("size"))
	{
		ft_move_right(1);
		move++;
	}
}
