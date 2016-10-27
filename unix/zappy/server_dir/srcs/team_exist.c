/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:56:22 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 12:56:57 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "serv.h"

int		team_exist(char **teams, char *team)
{
	int		i;

	i = 0;
	if (team == NULL)
		return (0);
	while (teams[i])
	{
		if (ft_strcmp(teams[i], team) == 0)
			return (1);
		i++;
	}
	return (0);
}
