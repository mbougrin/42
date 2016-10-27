/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:41:54 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 07:34:15 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "display.h"
#include "creat_entity.h"

int				ft_read_cmd_seg(t_display *d, char **spt)
{
	if (ft_strcmp(spt[0], "seg") == 0 && ft_strlistlen(spt) == 2)
	{
		d->winner = ft_strdup(spt[1]);
		return (1);
	}
	return (0);
}

int				ft_read_cmd_sgt(t_display *d, char **spt)
{
	if (ft_strcmp(spt[0], "sgt") == 0 && ft_strlistlen(spt) == 2)
	{
		d->sgt = ft_atoi(spt[1]);
		return (1);
	}
	return (0);
}

int				ft_read_cmd_bct(t_display *d, char **spt)
{
	int		i;

	i = 0;
	if (ft_strcmp(spt[0], "bct") == 0 && ft_strlistlen(spt) == 10)
	{
		i = ft_atoi(spt[1]) + ft_atoi(spt[2]) * d->map->w;
		d->map->map_case[i].loot[0] = ft_atoi(spt[3]);
		d->map->map_case[i].loot[1] = ft_atoi(spt[4]);
		d->map->map_case[i].loot[2] = ft_atoi(spt[5]);
		d->map->map_case[i].loot[3] = ft_atoi(spt[6]);
		d->map->map_case[i].loot[4] = ft_atoi(spt[7]);
		d->map->map_case[i].loot[5] = ft_atoi(spt[8]);
		d->map->map_case[i].loot[6] = ft_atoi(spt[9]);
		return (1);
	}
	return (0);
}

int				ft_read_cmd_ppos(t_display *d, char **spt)
{
	if (ft_strcmp(spt[0], "ppos") == 0 && ft_strlistlen(spt) == 14)
	{
		d->entity = ft_creat_entity(d, spt[1], spt);
		return (1);
	}
	return (0);
}
