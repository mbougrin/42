/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_team.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 03:15:14 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 07:08:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "display.h"

static char		**ft_add_team(char **team, char *name)
{
	int		i;
	char	**tmp;

	if ((tmp = (char **)malloc((ft_strlistlen(team) + 2) * sizeof(char *))))
	{
		i = 0;
		while (team && team[i])
		{
			tmp[i] = team[i];
			i++;
		}
		tmp[i] = ft_strdup(name);
		tmp[i + 1] = NULL;
		if (team)
			free(team);
	}
	return (tmp);
}

char			**ft_creat_team(t_display *d, char *name)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlistlen(d->team))
	{
		if (!ft_strcmp(d->team[i], name))
			return (d->team);
		i++;
	}
	d->team = ft_add_team(d->team, name);
	return (d->team);
}
