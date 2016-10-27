/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 19:28:55 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 19:39:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <poll.h>

#include "display.h"
#include "creat_map.h"
#include "creat_team.h"

static int	ft_check_cmd(t_display *d, char *s)
{
	char	**split;

	split = ft_strsplit(s, ' ');
	if (!ft_strcmp(split[0], "msz"))
		ft_creat_map(d, ft_atoi(split[1]), ft_atoi(split[2]));
	else if (!ft_strcmp(split[0], "tna"))
		d->team = ft_creat_team(d, split[1]);
	else if (!ft_strcmp(split[0], "sgt"))
		d->sgt = ft_atoi(split[1]);
	ft_strlistdel(split);
	return (1);
}

static int	ft_get_msg_lock(t_display *d)
{
	struct pollfd	fds;

	fds.fd = d->connect->sock;
	fds.events = POLLIN;
	if (!poll(&fds, 1, 5000))
		return (-1);
	if (fds.revents & (POLLOUT | POLLERR | POLLHUP))
		return (-1);
	return (0);
}

static int	ft_get_msg_serv_lock(t_display *d)
{
	char			**split;
	char			*buff;
	int				ret;
	unsigned int	i;

	i = 0;
	buff = ft_strnew(65536);
	if (ft_get_msg_lock(d) == -1)
		return (-1);
	ret = read(d->connect->sock, buff, 65536);
	if (ret <= 0)
		return (-1);
	buff[ret] = '\0';
	ft_putendl(buff);
	split = ft_strsplit(buff, '\n');
	while (i < ft_strlistlen(split))
	{
		ft_check_cmd(d, split[i]);
		i++;
	}
	ft_strlistdel(split);
	ft_strdel(&buff);
	return (1);
}

static int	ft_cmd_to_serv_lock(t_display *d, char *s)
{
	ft_putendl_fd(s, d->connect->sock);
	ft_putchar('g');
	if (ft_get_msg_serv_lock(d) == -1)
		return (-1);
	return (1);
}

int			ft_start_cmd(t_display *d)
{
	char	buff[1000];

	read(d->connect->sock, buff, 65536);
	if (ft_cmd_to_serv_lock(d, "GRAPHIC") == -1)
		return (-1);
	if (ft_cmd_to_serv_lock(d, "msz") == -1)
		return (-1);
	if (ft_cmd_to_serv_lock(d, "tna") == -1)
		return (-1);
	while (d->sgt == 0)
		if ((ft_cmd_to_serv_lock(d, "sgt") == -1))
			return (-1);
	return (0);
}
