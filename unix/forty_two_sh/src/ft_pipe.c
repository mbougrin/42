/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 21:35:41 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:40:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_child(char *line, int *fd_tab)
{
	close(fd_tab[0]);
	dup2(fd_tab[1], 1);
	close(fd_tab[1]);
	ft_check_command_line(line);
	exit(0);
}

static void		ft_father(char *line, int *fd_tab, int i)
{
	close(fd_tab[1]);
	dup2(fd_tab[0], 0);
	close(fd_tab[0]);
	ft_check_command_line(&line[i]);
}

static int		ft_len_pipe(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(&line[i], "|", 1) == 0)
		{
			i += 2;
			break ;
		}
		i++;
	}
	return (i);
}

void			ft_pipe(char *line)
{
	int				fd_tab[2];
	int				fd_zero;
	int				fd_one;
	pid_t			pid;
	int				i;

	fd_zero = dup(0);
	fd_one = dup(1);
	i = ft_len_pipe(line);
	if (pipe(fd_tab) == -1)
		return (ft_putendl_fd("pipe error", 2));
	if ((pid = fork()) < 0)
		return (ft_putendl_fd("fork error", 2));
	if (pid == 0)
		ft_child(line, fd_tab);
	else
	{
		wait(&pid);
		ft_father(line, fd_tab, i);
	}
	dup2(fd_one, 1);
	dup2(fd_zero, 0);
}
