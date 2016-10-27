/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 20:01:10 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/08 20:12:27 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_read_lower(int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
}

void			ft_read_lower_lower(char **split)
{
	int		fd;
	char	*line;

	fd = ft_open_tmp(split[1]);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
}
