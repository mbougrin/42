/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bquote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:57:48 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:32:02 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void			ft_delete(void)
{
	char	**split;

	split = ft_strstrnew(2);
	split[0] = ft_strdup("rm");
	split[1] = ft_strdup("temp_42sh");
	split[2] = NULL;
	ft_execve("/bin/rm", split);
}

void			ft_modify_bquote(char **line, char c)
{
	char	*line_tmp;
	char	*tmp;

	ft_putstr("bquote> ");
	if (get_next_line(0, &line_tmp) == 0)
		ft_exit(0, *line);
	tmp = line_tmp;
	line_tmp = ft_strjoin("\n", line_tmp);
	ft_strdel(&tmp);
	tmp = *line;
	*line = ft_strjoin(*line, line_tmp);
	ft_strdel(&tmp);
	ft_strdel(&line_tmp);
	if (ft_check_bquote(*line) == 0)
		ft_quote(line, c);
}

int				ft_check_bquote(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '`')
			count++;
		i++;
	}
	return (count % 2);
}
