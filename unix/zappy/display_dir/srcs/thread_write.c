/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 15:00:39 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 17:24:11 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "display.h"

void	*ft_thread_write(void *e)
{
	t_display	*d;

	d = (t_display *)e;
	while (d->winner == NULL)
	{
		ft_putendl_fd("ppos\nmct", d->connect->sock);
		usleep(100000);
	}
	return (NULL);
}
