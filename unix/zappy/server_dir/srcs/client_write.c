/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:24:25 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 16:32:27 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdio.h>
#include "serv.h"

static void		aff_on_serv(t_env *e, int cs)
{
	ft_putstr("[");
	ft_putnbr(count_cmd(e->fds[cs].buf_mem));
	ft_putstr(" waiting] ");
	if (e->fds[cs].player.team != NULL)
	{
		ft_putstr("[");
		ft_putstr(e->fds[cs].player.team);
		ft_putstr("] ");
	}
	ft_putstr("Client #");
	ft_putnbr(cs);
	ft_putstr(" > ");
	ft_putstr(e->fds[cs].buf_read);
}

void			client_write(t_env *e, int cs)
{
	if ((e->fds[cs].type == FD_CLIENT) && (ft_strlen(e->fds[cs].buf_read) > 0))
	{
		if (AFF_SERV)
			aff_on_serv(e, cs);
		ft_cmd(e, cs);
	}
	ft_bzero(e->fds[cs].buf_read, BUF_SIZE);
}
