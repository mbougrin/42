/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tempnam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 23:17:23 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/07 00:24:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_remove_tmp(char **envp)
{
	char	**split;

	split = ft_strstrnew(3);
	split[0] = ft_strdup("rm");
	split[1] = ft_strdup("file_tmp");
	split[2] = NULL;
	ft_check_cmd(split, envp);
	ft_strstrdel(split);
}

int				ft_open_tmp(char *end)
{
	int		fd;
	char	*line;

	fd = open("file_tmp", O_WRONLY | O_RDONLY | O_CREAT | O_APPEND, 0644);
	while (1)
	{
		ft_putstr("42sh> ");
		get_next_line(0, &line);
		if (ft_strcmp(line, end) == 0)
			break ;
		ft_putendl_fd(line, fd);
		ft_strdel(&line);
	}
	close(fd);
	return (open("file_tmp", O_RDONLY));
}
