/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_bquote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 16:05:43 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:18:15 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static char		*ft_copy_bquote(char **line)
{
	int		i;
	int		len;
	int		j;

	len = 0;
	j = 0;
	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == '`')
		{
			j = i + 1;
			i++;
			while (line[0][i])
			{
				if (line[0][i] == '`')
					break ;
				i++;
				len++;
			}
		}
		i++;
	}
	return (ft_strsub(*line, j, len));
}

static void		ft_launch_cmd(char *tmp)
{
	int		fd_zero;
	int		fd_one;
	int		fd;

	fd = open("temp_42sh", O_RDWR | O_CREAT, 0644);
	fd_zero = dup(0);
	fd_one = dup(1);
	dup2(fd, 1);
	if (ft_check_command_line(tmp) == -1)
		ft_delete();
	close(fd);
	dup2(fd_zero, 0);
	dup2(fd_one, 1);
}

static int		ft_modify_str(char *line_tmp, char **tmp, int j, int o)
{
	while (line_tmp[j])
	{
		if (line_tmp[j] == '\n')
			tmp[0][o] = ' ';
		else if (ft_strncmp(&line_tmp[j], "temp_42sh", \
					ft_strlen("temp_42sh")) == 0)
			j += ft_strlen("temp_42sh") - 1;
		else
			tmp[0][o] = line_tmp[j];
		j++;
		o++;
	}
	return (o);
}

static char		*ft_create(char *line, char *line_tmp, char *s)
{
	int		i;
	int		j;
	int		o;
	char	*tmp;

	i = 0;
	j = 0;
	o = 0;
	tmp = ft_strnew((ft_strlen(line) - ft_strlen(s)) + ft_strlen(line_tmp));
	while (line[i])
	{
		if (line[i] == '`')
		{
			o = ft_modify_str(line_tmp, &tmp, j, o);
			i += ft_strlen(s) + 2;
		}
		tmp[o] = line[i];
		o++;
		i++;
	}
	tmp[o] = '\0';
	return (tmp);
}

void			ft_replace_bquote(char **line)
{
	char	*tmp;
	char	*tmp1;
	char	next[4096];
	int		fd;
	int		ret;

	tmp = ft_copy_bquote(&*line);
	ft_launch_cmd(tmp);
	fd = open("temp_42sh", O_RDWR);
	ret = read(fd, next, 4096);
	next[ret] = '\0';
	tmp1 = *line;
	*line = ft_create(*line, next, tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp1);
	if (fd == -1)
		return ;
	else
		ft_delete();
	ft_strclr(next);
}
