/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logical_operators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 10:39:48 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:36:14 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static int		ft_len_operators(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '&' && line[i + 1] == '&')
		{
			i += 3;
			while (line[i] == ' ')
				i++;
			return (i);
		}
		else if (line[i] == '|' && line[i + 1] == '|')
		{
			i += 3;
			while (line[i] == ' ')
				i++;
			return (i);
		}
		i++;
	}
	return (i);
}

static int		ft_launch_logical_operators(char *line)
{
	int		ret;

	ret = ft_check_command_line(line);
	return (ret);
}

void			ft_logical_operators(char *line)
{
	int		ret;

	if (ft_strstr(line, "||") != NULL)
	{
		ret = ft_launch_logical_operators(line);
		if (ret == -1)
			ft_launch_logical_operators(&line[ft_len_operators(line)]);
	}
	else if (ft_strstr(line, "&&") != NULL)
	{
		ret = ft_launch_logical_operators(line);
		if (ret != -1)
			ft_launch_logical_operators(&line[ft_len_operators(line)]);
	}
}
