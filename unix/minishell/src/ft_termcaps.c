/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 00:38:59 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/12 08:53:50 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_read_cpy(char **line, char c)
{
	if (*line == NULL)
	{
		*line = ft_strnew(2);
		*line[0] = c;
		line[0][1] = '\0';
	}
	else if ((size_t)ft_pos_cursor("size") < ft_strlen(*line))
	{
		ft_copy_pos_cursor(line, c);
		return ;
	}
	else
		ft_copy_cursor_end(line, c);
	tputs(tgetstr("rc", NULL), 1, t_putchar);
	ft_putstr(*line);
	ft_pos_cursor("more");
}

static int		ft_check_read_next(char *read_char)
{
	if (read_char[0] == 12 && read_char[1] == 0 && read_char[2] == 0)
	{
		tputs(tgetstr("ti", NULL), 1, t_putchar);
		tputs(tgetstr("sc", NULL), 1, t_putchar);
	}
	else if (read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 65)
		read_char = read_char;
	else if (read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 66)
		read_char = read_char;
	else if (read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 72)
	{
		tputs(tgetstr("rc", NULL), 1, t_putchar);
		ft_pos_cursor("zero");
	}
	else
		return (0);
	return (1);
}

static int		ft_check_read(char *read_char, char **line, struct termios term)
{
	if (read_char[0] == 4 && read_char[1] == 0 && read_char[2] == 0)
		ft_control_d(term);
	else if (read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 68)
	{
		if (*line == NULL)
			return (1);
		ft_check_move_left(ft_strlen(*line));
	}
	else if (read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 67)
	{
		if (*line == NULL)
			return (1);
		ft_check_move_right(ft_strlen(*line));
	}
	else if (read_char[0] == 27 && read_char[1] == 91 && read_char[2] == 70 \
			&& *line != NULL)
		ft_check_end(ft_strlen(*line));
	else if (read_char[0] == 127 && read_char[1] == 0 && read_char[2] == 0)
		return (ft_delete(line));
	else
		return (ft_check_read_next(read_char));
	return (1);
}

static void		ft_read_termcaps(char **line)
{
	char				read_char[4];
	struct termios		term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(0, 0, &term);
	tputs(tgetstr("sc", NULL), 1, t_putchar);
	ft_pos_cursor("zero");
	while (1)
	{
		read(0, read_char, 3);
		if (ft_check_read(read_char, line, term) == 0)
		{
			if (read_char[0] == 10 && read_char[1] == 0 && read_char[2] == 0)
				break ;
			else
				ft_read_cpy(line, read_char[0]);
		}
		read_char[0] = read_char[1] = read_char[2] = 0;
	}
	ft_putchar('\n');
	ft_end_termcaps(term);
	if (*line == NULL)
		*line = ft_strdup("\0");
}

char			*ft_termcaps(void)
{
	char	*line;
	char	buffer[BUFF_SIZE];

	if (line != NULL)
		ft_strdel(&line);
	tgetent(buffer, getenv("TERM"));
	ft_read_termcaps(&line);
	return (line);
}
