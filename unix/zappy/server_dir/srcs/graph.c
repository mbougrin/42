/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:51:57 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 07:56:58 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

int				graph_seg(t_env *e, int cs)
{
	if (ft_strncmp(e->fds[cs].buf_read, "seg ", 4) == 0)
	{
		sprintf(e->fds[cs].buf_write, "%s",
				e->fds[cs].buf_read);
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		return (1);
	}
	return (0);
}

int				graph_msz(t_env *e, int cs)
{
	if (ft_strcmp(e->fds[cs].buf_read, "msz\n") == 0)
	{
		sprintf(e->fds[cs].buf_write, "msz %d %d\n",
				e->data.size_x,
				e->data.size_y);
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		return (1);
	}
	return (0);
}

int				graph_sst(t_env *e, int cs)
{
	char	*temp;

	if (ft_strncmp(e->fds[cs].buf_read, "sst ", 4) == 0)
	{
		temp = ft_strtrim(e->fds[cs].buf_read + 4);
		e->data.d_time = ft_atoi(temp);
		sprintf(e->fds[cs].buf_write, "sgt %d\n",
				e->data.d_time);
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		free(temp);
		return (1);
	}
	return (0);
}

int				graph_sgt(t_env *e, int cs)
{
	if (ft_strcmp(e->fds[cs].buf_read, "sgt\n") == 0)
	{
		sprintf(e->fds[cs].buf_write, "sgt %d\n",
				e->data.d_time);
		ft_putstr_fd(e->fds[cs].buf_write, cs);
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
		return (1);
	}
	return (0);
}
