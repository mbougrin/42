/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 14:44:24 by mblet             #+#    #+#             */
/*   Updated: 2014/03/25 18:41:05 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

static int		ft_find_nl(char *str)
{
	char	*bak;

	bak = str;
	if (str)
	{
		while (*str)
		{
			if (*str == EOF)
				return (str - bak - 1);
			if (*str++ == '\n')
				return (str - bak - 1);
		}
	}
	return (-1);
}

static char		*ft_get_next_nl(char **str)
{
	int		pos;
	int		len;
	char	*ret;
	char	*bak;

	if ((pos = ft_find_nl(*str)) == -1)
		return (NULL);
	if (!(ret = (char *)malloc((pos + 1) * sizeof(*ret))))
		return (NULL);
	bak = ret;
	while ((ret - bak) < pos)
		*ret++ = *((*str)++);
	*ret = 0;
	len = ft_strlen(*str);
	if (!(ret = (char *)malloc((len + 1) * sizeof(*ret))))
		return (NULL);
	while (**str)
		*ret++ = *(++(*str));
	free(*str - len - pos);
	*str = ret - len;
	return (bak);
}

static char		*ft_concat_string(char *old, char *buf, int n)
{
	char	*ret;
	char	*bak;

	if (!(ret = (char *)malloc((ft_strlen(old) + n + 1) * sizeof(*ret))))
		return (NULL);
	bak = ret;
	if (old)
	{
		while (*old)
			*ret++ = *old++;
	}
	*(ret + n) = 0;
	free(old - (ret - bak));
	while (n--)
		*(ret + n) = buf[n];
	return (bak);
}

int				ft_get_next_line(int fd, char **line)
{
	char			*ret;
	int				nb_read;
	static char		*old;
	char			buf[BUFF_SIZE];

	while (!(ret = ft_get_next_nl(&old)))
	{
		nb_read = read(fd, buf, BUFF_SIZE);
		if (!nb_read)
		{
			ret = old;
			*line = ret;
			return (0);
		}
		else if (nb_read == -1)
		{
			ft_strdel(line);
			return (-1);
		}
		old = ft_concat_string(old, buf, nb_read);
	}
	*line = ret;
	return (1);
}
