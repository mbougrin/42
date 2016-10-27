/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_slash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 10:11:50 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:31:46 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static char		ft_check_back_slash(char c)
{
	if (c == '0')
		return ('\0');
	if (c == 'a')
		return ('\a');
	if (c == 'b')
		return ('\b');
	if (c == 'f')
		return ('\f');
	if (c == 'n')
		return ('\n');
	if (c == 't')
		return ('\t');
	if (c == 'v')
		return ('\v');
	if (c == 'r')
		return ('\r');
	return (-1);
}

void			ft_back_slash(char **line)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (line[0][i])
	{
		if (line[0][i] == '\\' && line[0][i + 1] == '\\' \
				&& ft_check_back_slash(line[0][i + 2]) != -1)
		{
			line[0][j] = ft_check_back_slash(line[0][i + 2]);
			i += 2;
			j++;
		}
		else
		{
			if (line[0][i] == '\\' && line[0][i + 1] == '\\')
				i++;
			line[0][j] = line[0][i];
			j++;
		}
		i++;
	}
	line[0][j] = '\0';
}
