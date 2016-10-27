/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 17:01:45 by mblet             #+#    #+#             */
/*   Updated: 2014/06/22 21:29:51 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "display.h"
#include "creat_bg.h"

void	*ft_thread_hook(void *e)
{
	t_display	*d;

	d = (t_display *)e;
	pthread_mutex_lock(&d->mutex_display);
	ft_creat_bg(d);
	pthread_mutex_unlock(&d->mutex_display);
	pthread_mutex_unlock(&d->mutex_hook);
	return (NULL);
}
