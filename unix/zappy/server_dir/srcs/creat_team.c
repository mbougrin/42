/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_team.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 03:15:14 by mblet             #+#    #+#             */
/*   Updated: 2014/06/20 21:18:22 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "serv.h"

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
		tmp[i] = name;
		tmp[i + 1] = NULL;
		if (team)
			free(team);
	}
	return (tmp);
}

void			ft_creat_team(t_env *e, char *name)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlistlen(e->data.teams))
	{
		if (!ft_strcmp(e->data.teams[i], name))
			return ;
		i++;
	}
	e->data.teams = ft_add_team(e->data.teams, name);
}
