/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 18:45:29 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/27 05:40:27 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

void			ft_expels(int sock)
{
	char			buff[4096];
	int				ret;

	write(sock, "expulse\n", ft_strlen("expulse\n"));
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_strclr(buff);
}

void			ft_spell(int sock, t_stc *stc)
{
	char			buff[4096];
	int				ret;
	static int		view_update;
	static int		count;

	if (count == 0)
		view_update = stc->view;
	write(sock, "incantation\n", ft_strlen("incantation\n"));
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	if (ft_strcmp(buff, "elevation en cours\n") == 0)
	{
		stc->level++;
		view_update += 2;
		stc->view += view_update;
		ft_strclr(buff);
	}
}

void			ft_top(int sock)
{
	char			buff[4096];
	int				ret;

	write(sock, "avance\n", ft_strlen("avance\n"));
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_strclr(buff);
}

void			ft_left(int sock)
{
	char			buff[4096];
	int				ret;

	write(sock, "gauche\n", ft_strlen("gauche\n"));
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_strclr(buff);
}

void			ft_right(int sock)
{
	char			buff[4096];
	int				ret;

	write(sock, "droite\n", ft_strlen("droite\n"));
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_strclr(buff);
}
