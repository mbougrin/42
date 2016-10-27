/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sock.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 18:48:15 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/27 00:23:40 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

int				ft_see(int sock, t_stc *stc)
{
	char	*buff;
	char	**split;
	t_see	*see;

	write(sock, "voir\n", ft_strlen("voir\n"));
	see = malloc(sizeof(t_see));
	ft_get_next_line(sock, &buff);
	split = ft_strsplit(buff, ' ');
	if (split == NULL)
		exit(0);
	ft_see_next(see, stc->sock, split);
	ft_strstrdel(split);
	free(see);
	ft_strdel(&buff);
	return (0);
}

void			ft_broadcast(int sock, char *s)
{
	char	*str;
	char	buff[4096];
	int		ret;

	str = ft_strnew(ft_strlen(s) + ft_strlen("broadcast ") + 2);
	ft_strcat(str, "broadcast ");
	ft_strcat(str, s);
	ft_strcat(str, "\n");
	write(sock, str, ft_strlen(str));
	ft_strdel(&str);
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_strclr(buff);
}

void			ft_fork(int sock)
{
	char	buff[4096];
	int		ret;

	write(sock, "fork\n", ft_strlen("fork\n"));
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_strclr(buff);
}

void			ft_laying(int sock, char *s)
{
	char	*str;
	char	buff[4096];
	int		ret;

	str = ft_strnew(ft_strlen(s) + ft_strlen("pose ") + 2);
	ft_strcat(str, "pose ");
	ft_strcat(str, s);
	ft_strcat(str, "\n");
	write(sock, str, ft_strlen(str));
	ft_strdel(&str);
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_strclr(buff);
}

void			ft_take(int sock, char *s)
{
	char	*str;
	char	buff[4096];
	int		ret;

	str = ft_strnew(ft_strlen(s) + ft_strlen("prend \n") + 1);
	ft_strcat(str, "prend ");
	ft_strcat(str, s);
	ft_strcat(str, "\n");
	write(sock, str, ft_strlen(str));
	ft_strdel(&str);
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_strclr(buff);
}
