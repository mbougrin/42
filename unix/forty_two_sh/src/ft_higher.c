/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_higher.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:17:45 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:43:11 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static int		ft_len_higher_higher(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(&line[i], ">>", 2) == 0)
		{
			i += 3;
			break ;
		}
		i++;
	}
	return (i);
}

static int		ft_len_higher(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(&line[i], ">", 1) == 0)
		{
			i += 2;
			break ;
		}
		i++;
	}
	return (i);
}

void			ft_higher(char *line)
{
	int		fd;
	int		fd_one;
	int		i;

	i = 0;
	if (ft_check_command_found(line) == 0)
		return ;
	i = ft_len_higher(line);
	if (line[i] == '\0' || (fd = open(&line[i], O_RDWR \
					| O_CREAT | O_TRUNC, 0644)) == -1)
		return (ft_putendl_fd("open error", 2));
	else
	{
		fd_one = dup(1);
		dup2(fd, 1);
		ft_check_command_line(line);
		close(fd);
		dup2(fd_one, 1);
	}
}

void			ft_higher_higher(char *line)
{
	int		fd;
	int		fd_one;
	int		i;

	i = 0;
	if (ft_check_command_found(line) == 0)
		return ;
	i = ft_len_higher_higher(line);
	if (line[i] == '\0' || (fd = open(&line[i], O_RDWR \
					| O_CREAT | O_APPEND, 0644)) == -1)
		return (ft_putendl_fd("open error", 2));
	else
	{
		fd_one = dup(1);
		dup2(fd, 1);
		ft_check_command_line(line);
		close(fd);
		dup2(fd_one, 1);
	}
}
