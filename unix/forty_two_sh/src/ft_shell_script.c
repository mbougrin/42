/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_script.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 08:12:08 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 17:02:03 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void		ft_shell_script(char **line)
{
	int		fd;
	char	*free_tmp;
	char	buff[4096];
	int		i;
	int		ret;

	i = 0;
	if ((fd = open(&line[0][2], O_RDONLY)) == -1)
		return ;
	free_tmp = line[0];
	ret = read(fd, buff, 4096);
	buff[ret] = '\0';
	line[0] = ft_strdup(buff);
	ft_strclr(buff);
	while (line[0][i] != '\0')
	{
		if (line[0][i] == '\n')
			line[0][i] = 59;
		i++;
	}
	ft_strdel(&free_tmp);
}
