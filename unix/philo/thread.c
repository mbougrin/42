/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 18:38:33 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/11 18:51:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int					g_t = TIMEOUT;
int					g_bread[NB_PH] = {0};
pthread_mutex_t		g_mutex_bread[NB_PH] = {PTHREAD_MUTEX_INITIALIZER};

void				*ft_time(void *data)
{
	int		i;

	while (g_t > 0)
	{
		i = 0;
		while (i < NB_PH)
		{
			ft_mlx(data);
			if (((t_ph **)data)[i]->status != 1)
				((t_ph **)data)[i]->life--;
			if (((t_ph **)data)[i]->life <= 0)
			{
				ft_mlx(data);
				ft_mlx(NULL);
				return (0);
			}
			i++;
		}
		g_t--;
		usleep(1000000);
	}
	ft_putendl("Now, it is time... To DAAAAAAAANCE!!!");
	ft_mlx(data);
	ft_mlx(NULL);
	return (0);
}

static int			ft_eat(void *data)
{
	t_ph				*ph;

	ph = (t_ph *)data;
	if (ph->life < (MAX_LIFE / 2))
	{
		if (g_bread[ph->id] == 0 && g_bread[(ph->id + 1) % 7] == 0)
		{
			g_bread[ph->id] = 1;
			g_bread[(ph->id + 1) % 7] = 1;
			ph->status = EAT;
			usleep((int)EAT_T * 1000000);
			ph->life = MAX_LIFE;
			g_bread[ph->id] = 0;
			g_bread[(ph->id + 1) % 7] = 0;
		}
		return (1);
	}
	return (0);
}

static int			ft_think(void *data)
{
	t_ph				*ph;

	ph = (t_ph *)data;
	if (g_bread[ph->id] == 0)
	{
		g_bread[ph->id] = 1;
		ph->status = THINK;
		usleep((int)THINK_T * 1000000);
		g_bread[ph->id] = 0;
		return (1);
	}
	if (g_bread[(ph->id + 1) % 7] == 0)
	{
		g_bread[(ph->id + 1) % 7] = 1;
		ph->status = THINK;
		usleep((int)THINK_T * 1000000);
		g_bread[(ph->id + 1) % 7] = 0;
		return (1);
	}
	return (0);
}

static void			*ft_rest(void *data)
{
	t_ph		*ph;

	ph = (t_ph *)data;
	ph->status = REST;
	usleep((int)REST_T * 1000000);
	return (0);
}

void				*ft_action(void *data)
{
	while (g_t > 0)
	{
		ft_rest(data);
		if (!ft_eat(data))
			ft_think(data);
	}
	return (0);
}
