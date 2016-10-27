/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 16:51:56 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/03 18:06:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char			*get_split_line(char *s)
{
	static char		*str = "";
	char			*tmp;
	int				i;
	int				j;

	i = 0;
	if (*str != '\0')
	{
		tmp = s;
		s = ft_strjoin(str, tmp);
		free(tmp);
		free(str);
	}
	else if (*s == '\0')
		return ("eof");
	while (s[i] != '\n')
		i++;
	j = ft_strlen(s);
	s[i] = '\0';
	i++;
	str = ft_strsub(s, i, (j - i));
	tmp = s;
	s = ft_strsub(tmp, 0, i);
	free(tmp);
	return (s);
}

static char			*get_read(int fd)
{
	char	*buff;
	char	*str;
	char	*tmp;
	int		ret;

	buff = ft_strnew(BUFF_SIZE + 1);
	str = ft_strnew(1);
	if (str == NULL || buff == NULL)
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(str, '\n') != NULL)
			break ;
	}
	free(buff);
	if (ret == 0 && ft_strchr(str, '\n') == NULL && ft_strlen(str) != 0)
		return (str);
	str = get_split_line(str);
	if (ret == -1)
		return (NULL);
	return (str);
}

int					get_next_line(int fd, char **line)
{
	char		*str;

	if (line != NULL || *line != '\0')
		free(*line);
	if (fd == -1)
		return (-1);
	if (BUFF_SIZE < 0)
		return (-1);
	str = get_read(fd);
	if (ft_strcmp(str, "eof") == 0)
		return (0);
	else if (str == NULL)
		return (-1);
	*line = ft_strdup(str);
	free(str);
	return (1);
}
