/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:08:53 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/08 17:48:39 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char				*ft_getpath(char *str)
{
	static char		*path;

	if (str != NULL)
	{
		if (path != NULL)
			ft_strdel(&path);
		path = ft_strdup(str);
	}
	return (path);
}

void				ft_print_link(char *name, char *path)
{
	char	*str;
	char	*tmp;
	int		len;

	str = NULL;
	str = (char *)malloc(10000);
	if (path != NULL)
		tmp = ft_strstrjoin(3, path, "/", name);
	else
		tmp = ft_strdup(name);
	len = readlink(tmp, str, 10000);
	str[len] = '\0';
	ft_putstr(name);
	ft_putstr(" -> ");
	ft_putendl(str);
	ft_strdel(&str);
}

void				ft_empty(void)
{
	ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
	exit(0);
}
