/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_launch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 18:32:06 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 06:36:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>

#include "display.h"
#include "thread_read.h"
#include "thread_write.h"

void	ft_thread_launch(t_display *d)
{
	pthread_t	thread_read;
	pthread_t	thread_write;

	if ((pthread_create(&thread_read, NULL, &ft_thread_read, d) < 0))
		exit(EXIT_FAILURE);
	if ((pthread_create(&thread_write, NULL, &ft_thread_write, d) < 0))
		exit(EXIT_FAILURE);
}
