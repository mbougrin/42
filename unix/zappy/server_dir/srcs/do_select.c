/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:24:38 by mbar              #+#    #+#             */
/*   Updated: 2014/06/25 22:34:15 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serv.h"

void	do_select(t_env *e)
{
	struct timeval	tv;

	tv.tv_usec = 1;
	e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, &tv);
}
