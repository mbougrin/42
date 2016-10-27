/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 17:48:26 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 04:16:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "display.h"

t_display	*ft_ini_display(void)
{
	t_display	*d;

	if ((d = malloc(sizeof(t_display))) == NULL)
		return (NULL);
	if ((d->connect = malloc(sizeof(t_connect))) == NULL)
		return (NULL);
	if ((d->mlx = malloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((d->img = malloc(sizeof(t_img))) == NULL)
		return (NULL);
	if ((d->map = malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((d->popup = malloc(sizeof(t_popup))) == NULL)
		return (NULL);
	if ((d->entity = malloc(sizeof(t_entity *))) == NULL)
		return (NULL);
	if ((d->menu = malloc(sizeof(t_menu *))) == NULL)
		return (NULL);
	d->team = NULL;
	d->winner = NULL;
	return (d);
}
