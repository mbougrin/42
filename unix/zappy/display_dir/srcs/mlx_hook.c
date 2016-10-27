/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 03:41:21 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 01:50:49 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

#include "display.h"
#include "thread_hook.h"
#include "check_action_nouse.h"
#include "check_if_in_menu.h"

static int	ft_key_hook(int key, void *e)
{
	t_display	*d;
	pthread_t	thread_hook;

	d = (t_display *)e;
	if (key == KEY_PAD_MINUS && d->map->size_case > 10)
		d->map->size_case -= 1;
	if (key == KEY_PAD_ADD
		&& d->map->h * (d->map->size_case + 1) < MAX_HEIGHT
		&& d->map->w * (d->map->size_case + 1) < MAX_WIDTH)
		d->map->size_case += 1;
	if (key == KEY_DELETE || key == KEY_ESC)
	{
		close(d->connect->sock);
		exit(EXIT_SUCCESS);
	}
	d->map->map_w = d->map->w * d->map->size_case;
	d->map->map_h = d->map->h * d->map->size_case;
	if (pthread_mutex_trylock(&d->mutex_hook) == 0)
	{
		if ((pthread_create(&thread_hook, NULL, &ft_thread_hook, d) < 0))
			exit(EXIT_FAILURE);
	}
	return (1);
}

static int	ft_mouse_motion(int x, int y, void *e)
{
	t_display	*d;

	d = (t_display *)e;
	d->popup->x = x;
	d->popup->y = y;
	return (1);
}

static int	ft_mouse_scroll(int button, int x, int y, void *e)
{
	t_display	*d;
	pthread_t	thread_hook;

	d = (t_display *)e;
	if (button == MOUSE_BUTTON_LEFT)
		ft_check_action_mouse(d, x, y);
	if (ft_check_if_in_menu(d, x, y, button))
		return (0);
	if (button == MOUSE_SCROLL_DOWN && d->map->size_case > 10)
		d->map->size_case -= 1;
	if (button == MOUSE_SCROLL_UP
		&& d->map->h * (d->map->size_case + 1) < MAX_HEIGHT
		&& d->map->w * (d->map->size_case + 1) < MAX_WIDTH)
		d->map->size_case += 1;
	d->map->map_w = d->map->w * d->map->size_case;
	d->map->map_h = d->map->h * d->map->size_case;
	if (pthread_mutex_trylock(&d->mutex_hook) == 0)
	{
		if ((pthread_create(&thread_hook, NULL, &ft_thread_hook, d) < 0))
			exit(EXIT_FAILURE);
	}
	return (0);
}

void		ft_mlx_hook(t_display *d)
{
	mlx_hook(d->mlx->win, 2, 3, &ft_key_hook, d);
	mlx_hook(d->mlx->win, 6, (1L << 6), &ft_mouse_motion, d);
	mlx_hook(d->mlx->win, 4, 5, &ft_mouse_scroll, d);
}
