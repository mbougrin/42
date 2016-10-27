/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 18:34:04 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 07:34:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "display.h"
#include "read_cmd_func.h"
#include "creat_team.h"

static int		ft_check_cmd(t_display *d, char *s)
{
	int		i;
	char	**split;

	split = ft_strsplit(s, ' ');
	if (!ft_strcmp(split[0], "tna"))
		d->team = ft_creat_team(d, split[1]);
	i = 0;
	while (i < 3)
	{
		if (d->read_cmd[i](d, split) == 1)
			break ;
		i++;
	}
	ft_strlistdel(split);
	return (0);
}

static void		ft_get_msg_serv(t_display *d)
{
	char	*buff;
	int		ret;

	ret = ft_get_next_line(d->connect->sock, &buff);
	if (ret <= 0)
	{
		ft_strdel(&buff);
		return ;
	}
	ft_putendl(buff);
	ft_check_cmd(d, buff);
	ft_strdel(&buff);
}

static void		ft_ini_ptr_func(t_display *d)
{
	d->read_cmd[0] = &ft_read_cmd_ppos;
	d->read_cmd[1] = &ft_read_cmd_bct;
	d->read_cmd[2] = &ft_read_cmd_seg;
	d->read_cmd[3] = &ft_read_cmd_bct;
	d->read_cmd[4] = &ft_read_cmd_bct;
	d->read_cmd[5] = &ft_read_cmd_bct;
	d->read_cmd[6] = &ft_read_cmd_bct;
}

void			*ft_thread_read(void *e)
{
	t_display	*d;

	d = (t_display *)e;
	ft_ini_ptr_func(d);
	while (d->winner == NULL)
	{
		ft_get_msg_serv(d);
	}
	return (NULL);
}
