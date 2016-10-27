/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 02:02:28 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 05:27:17 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "display.h"
#include "print_entity.h"

unsigned int		ft_listlen(t_entity **e)
{
	unsigned int	i;

	i = 0;
	if (e)
	{
		while (e[i])
			i++;
	}
	return (i);
}

static void			ft_modif_entity(t_display *d, t_entity *e, char **spt)
{
	if (e->x != atoi(spt[2]) || e->y != atoi(spt[3]))
		e->anim = 1;
	e->n = atoi(spt[1]);
	e->x = atoi(spt[2]);
	e->y = atoi(spt[3]);
	e->o = atoi(spt[4]);
	e->lvl = atoi(spt[5]);
	ft_strdel(&e->t);
	e->t = ft_strdup(spt[6]);
	e->color_team = ft_find_color_team(d, spt[6]);
	e->loot[0] = atoi(spt[7]);
	e->loot[1] = atoi(spt[8]);
	e->loot[2] = atoi(spt[9]);
	e->loot[3] = atoi(spt[10]);
	e->loot[4] = atoi(spt[11]);
	e->loot[5] = atoi(spt[12]);
	e->loot[6] = atoi(spt[13]);
}

static t_entity		*ft_copy_entity(t_display *d, char **spt)
{
	t_entity	*e;

	if ((e = (t_entity *)malloc(sizeof(t_entity))))
	{
		e->n = atoi(spt[1]);
		e->x = atoi(spt[2]);
		e->y = atoi(spt[3]);
		e->o = atoi(spt[4]);
		e->lvl = atoi(spt[5]);
		e->t = ft_strdup(spt[6]);
		e->color_team = ft_find_color_team(d, spt[6]);
		e->loot[0] = atoi(spt[7]);
		e->loot[1] = atoi(spt[8]);
		e->loot[2] = atoi(spt[9]);
		e->loot[3] = atoi(spt[10]);
		e->loot[4] = atoi(spt[11]);
		e->loot[5] = atoi(spt[12]);
		e->loot[6] = atoi(spt[13]);
		e->anim = 0;
		e->anim_2 = 0;
	}
	return (e);
}

static t_entity		**ft_add_entity(t_display *d, t_entity **ent, char **spt)
{
	int			i;
	t_entity	**tmp;

	if ((tmp = (t_entity **)malloc((ft_listlen(ent) + 2) *
					sizeof(t_entity *))))
	{
		i = 0;
		while (ent && ent[i])
		{
			tmp[i] = ent[i];
			i++;
		}
		tmp[i] = ft_copy_entity(d, spt);
		tmp[i + 1] = NULL;
		if (ent)
			free(ent);
	}
	return (tmp);
}

t_entity			**ft_creat_entity(t_display *d, char *n, char **spt)
{
	unsigned int	i;

	i = 0;
	while (i < ft_listlen(d->entity))
	{
		if (d->entity[i]->n == atoi(n))
		{
			ft_modif_entity(d, d->entity[i], spt);
			return (d->entity);
		}
		i++;
	}
	d->entity = ft_add_entity(d, d->entity, spt);
	return (d->entity);
}
