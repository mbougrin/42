/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 17:20:57 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 18:05:02 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_read_fd(char *s, int fd_tmp)
{
	int		fd;
	char	line[4096];

	fd = 0;
	if (fd_tmp != 0)
		fd = fd_tmp;
	if (fd == 0 && (fd = open(s, O_RDONLY)) == -1)
	{
		ft_putendl_fd("open error", 2);
		ft_strdel(&s);
		return ;
	}
	while (read(fd, line, 4096))
	{
		ft_putstr(line);
		ft_strclr(line);
	}
	ft_strdel(&s);
}

static int		ft_len_lower(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(&line[i], "<", 1) == 0)
		{
			i += 2;
			break ;
		}
		i++;
	}
	return (i);
}

static int		ft_len_lower_lower(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(&line[i], "<<", 2) == 0)
		{
			i += 3;
			while (line[i] == '<')
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

void			ft_lower_lower(char *line)
{
	int		fd;
	int		fd_zero;
	int		i;
	char	*s;

	i = ft_len_lower_lower(line);
	if (line[0] != '<' && ft_check_command_found(line) == 0)
		return ;
	if (line[i] == '\0')
		return ;
	s = ft_strsub(line, i, (ft_strlen(line) - i));
	fd = ft_open_tmp(s);
	if (line[0] == '<')
	{
		ft_read_fd(s, fd);
		return (ft_remove_tmp());
	}
	fd_zero = dup(0);
	dup2(fd, 0);
	ft_check_command_line(line);
	close(fd);
	dup2(fd_zero, 0);
	ft_strdel(&s);
	ft_remove_tmp();
}

void			ft_lower(char *line)
{
	int		fd;
	int		fd_zero;
	int		i;
	char	*s;

	i = 0;
	i = ft_len_lower(line);
	if (line[0] != '<' && ft_check_command_found(line) == 0)
		return ;
	if (line[i] == '\0')
		return ;
	s = ft_strsub(line, i, (ft_strlen(line) - i));
	if (line[0] == '<')
		return (ft_read_fd(s, 0));
	if ((fd = open(s, O_RDONLY)) == -1)
		ft_putendl_fd("open error", 2);
	else
	{
		fd_zero = dup(0);
		dup2(fd, 0);
		ft_check_command_line(line);
		close(fd);
		dup2(fd_zero, 0);
	}
	ft_strdel(&s);
}
