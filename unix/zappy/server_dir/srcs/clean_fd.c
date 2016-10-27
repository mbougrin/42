/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:21:57 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 17:50:02 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serv.h"

void	clean_fd(t_fd *fd)
{
	fd->type = FD_FREE;
	fd->fct_read = NULL;
	fd->fct_cmd = NULL;
	fd->fct_write = NULL;
	ft_bzero(fd->buf_read, BUF_SIZE);
	ft_bzero(fd->buf_mem, BUF_SIZE);
	ft_bzero(fd->buf_write, BUF_SIZE);
	fd->player.team = NULL;
}
