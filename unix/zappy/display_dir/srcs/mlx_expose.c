/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_expose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 04:04:48 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 08:01:00 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <pthread.h>
#include <mlx.h>
#include <stdlib.h>

#include "display.h"
#include "thread_loop.h"
#include "thread_hook.h"
#include "print_popup.h"
#include "print_popup_menu.h"
#include "menu.h"

static int	ft_expose_hook(void *e)
{
	(void)e;
	return (1);
}

static int	ft_expose_loop(void *e)
{
	t_display	*d;

	d = (t_display *)e;
	pthread_mutex_lock(&d->mutex_display);
	if (d->winner == NULL)
	{
		ft_print_popup(d);
		ft_print_popup_menu(d);
	}
	mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->img, 0, 0);
	pthread_mutex_unlock(&d->mutex_display);
	return (1);
}

void		ft_mlx_expose(t_display *d)
{
	pthread_t	thread_display;

	if ((pthread_mutex_init(&d->mutex_display, NULL) < 0))
		exit(EXIT_FAILURE);
	if ((pthread_mutex_init(&d->mutex_hook, NULL) < 0))
		exit(EXIT_FAILURE);
	if ((pthread_create(&thread_display, NULL, &ft_thread_loop, d) < 0))
		exit(EXIT_FAILURE);
	mlx_expose_hook(d->mlx->win, &ft_expose_hook, d);
	mlx_loop_hook(d->mlx->mlx, &ft_expose_loop, d);
	mlx_loop(d->mlx->mlx);
}
