/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_termcaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 05:02:53 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/09 15:08:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int				t_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static void		ft_delete_next(char **line)
{
	int		i;
	char	*tmp;
	char	*tmp_line;

	tputs(tgetstr("dc", NULL), 1, t_putchar);
	i = 0;
	i = ft_pos_cursor("size");
	tmp = line[0];
	tmp_line = ft_strdup(&tmp[i]);
	tmp[i - 1] = '\0';
	line[0] = ft_strjoin(tmp, tmp_line);
	tmp[i - 1] = ' ';
	ft_strdel(&tmp_line);
	ft_strdel(&tmp);
	tputs(tgetstr("rc", NULL), 1, t_putchar);
	ft_pos_cursor("less");
	ft_putstr(*line);
	tputs(tgetstr("rc", NULL), 1, t_putchar);
	i--;
	while (i > 0)
	{
		ft_move_right(1);
		i--;
	}
}

int				ft_delete(char **line)
{
	if (line[0] == NULL || line[0][0] == '\0')
		return (1);
	else if (ft_pos_cursor("size") == 0)
		return (1);
	else if ((size_t)ft_pos_cursor("size") < ft_strlen(*line))
		ft_delete_next(line);
	else
	{
		ft_move_left(ft_strlen(*line));
		tputs(tgetstr("dc", NULL), 1, t_putchar);
		line[0][ft_strlen(*line) - 1] = '\0';
		ft_putstr(*line);
		return (2);
	}
	return (2);
}

void			ft_move_left(int nb)
{
	while (nb)
	{
		tputs(tgetstr("le", NULL), 1, t_putchar);
		nb--;
	}
}

void			ft_move_right(int nb)
{
	while (nb)
	{
		tputs(tgetstr("nd", NULL), 1, t_putchar);
		nb--;
	}
}
