/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forty_two_sh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:31:08 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:34:52 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

int				ft_check_space(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void			ft_replace_tabulation(char **line)
{
	int		i;

	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == '\t')
			line[0][i] = ' ';
		i++;
	}
}

void			ft_shelltrim(char **line)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strtrim(tmp);
	ft_strdel(&tmp);
}

int				ft_strlen_space(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			break ;
		i++;
	}
	return (i);
}
