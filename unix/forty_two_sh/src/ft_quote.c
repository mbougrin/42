/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 07:40:03 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:59:11 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_modify_quote(char **line, char c)
{
	char	*line_tmp;
	char	*tmp;

	ft_putstr("quote> ");
	if (get_next_line(0, &line_tmp) == 0)
		ft_exit(0, *line);
	tmp = line_tmp;
	line_tmp = ft_strjoin("\n", line_tmp);
	ft_strdel(&tmp);
	tmp = *line;
	*line = ft_strjoin(*line, line_tmp);
	ft_strdel(&tmp);
	ft_strdel(&line_tmp);
	if (ft_check_quote(*line) == -1)
		ft_quote(line, c);
}

static void		ft_modify_dquote(char **line, char c)
{
	char	*line_tmp;
	char	*tmp;

	ft_putstr("dquote> ");
	if (get_next_line(0, &line_tmp) == 0)
		ft_exit(0, *line);
	tmp = line_tmp;
	line_tmp = ft_strjoin("\n", line_tmp);
	ft_strdel(&tmp);
	tmp = *line;
	*line = ft_strjoin(*line, line_tmp);
	ft_strdel(&tmp);
	ft_strdel(&line_tmp);
	if (ft_check_quote(*line) == -1)
		ft_quote(line, c);
}

void			ft_quote(char **line, char c)
{
	int		i;

	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == 34 || line[0][i] == 39)
		{
			c = line[0][i];
			break ;
		}
		i++;
	}
	if (c == 34)
		ft_modify_dquote(&*line, c);
	if (c == 39)
		ft_modify_quote(line, c);
}

char			ft_check_quote(char *s)
{
	int		i;
	int		count;
	char	c;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 39 || s[i] == 34)
		{
			count++;
			c = s[i++];
			break ;
		}
		i++;
	}
	while (s[i])
	{
		if (c == s[i])
			count++;
		i++;
	}
	if (count % 2 == 0)
		return (c);
	return (-1);
}
