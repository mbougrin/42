/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 08:55:18 by mbar              #+#    #+#             */
/*   Updated: 2014/05/11 18:43:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		main(void)
{
	int			i;
	pthread_t	thread_ph[NB_PH];
	pthread_t	thread_t;
	t_ph		**data;

	data = (t_ph **)malloc(sizeof(t_ph) * 7);
	i = 0;
	while (i < NB_PH)
	{
		data[i] = (t_ph *)malloc(sizeof(t_ph));
		data[i]->id = i;
		data[i]->life = MAX_LIFE;
		data[i]->status = REST;
		pthread_create(&thread_ph[i], NULL, ft_action, data[i]);
		i++;
	}
	pthread_create(&thread_t, NULL, ft_time, data);
	pthread_join(thread_t, NULL);
	return (0);
}
