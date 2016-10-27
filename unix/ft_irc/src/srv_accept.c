/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:16:42 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/23 17:39:11 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "bircd.h"

void			srv_accept(t_env *e, int s)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;

	csin_len = sizeof(csin);
	cs = X(-1, accept(s, (struct sockaddr*)&csin, &csin_len), "accept");
	e->fds[cs].nick_name = ft_strjoin("client #", ft_itoa(cs));
	ft_putstr("\033[31mNew client #");
	ft_putnbr(cs);
	ft_putstr(" from ");
	ft_putstr(inet_ntoa(csin.sin_addr));
	ft_putstr(":");
	ft_putnbr(ntohs(csin.sin_port));
	ft_putchar('\n');
	clean_fd(&e->fds[cs]);
	e->fds[cs].type = FD_CLIENT;
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_write = client_write;
}
