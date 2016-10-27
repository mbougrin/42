/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tempnam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 19:27:08 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 18:12:01 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void			ft_remove_tmp(void)
{
	char	**split;

	split = ft_strstrnew(2);
	split[0] = ft_strdup("rm");
	split[1] = ft_strdup("file_tmp");
	split[2] = NULL;
	ft_execve("/bin/rm", split);
}

int				ft_open_tmp(char *end)
{
	int		fd;
	char	*line;

	fd = open("file_tmp", O_WRONLY | O_RDONLY | O_CREAT | O_APPEND, 0644);
	while (1)
	{
		ft_putstr("heredoc> ");
		if (get_next_line(0, &line) == 0)
			ft_exit(0, line);
		if (ft_strcmp(line, end) == 0)
		{
			ft_strdel(&line);
			break ;
		}
		ft_putendl_fd(line, fd);
		ft_strdel(&line);
	}
	close(fd);
	return (open("file_tmp", O_RDONLY));
}
