/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 09:54:21 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/24 09:57:00 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

int			ft_level_one(t_stc *stc)
{
	if (stc->linemate < 1)
		return (1);
	return (-1);
}

int			ft_level_two(t_stc *stc)
{
	if (stc->linemate < 1)
		return (1);
	else if (stc->deraumere < 1)
		return (2);
	else if (stc->sibur < 1)
		return (3);
	return (-1);
}

int			ft_level_three(t_stc *stc)
{
	if (stc->linemate < 2)
		return (1);
	else if (stc->sibur < 1)
		return (3);
	else if (stc->phiras < 2)
		return (5);
	return (-1);
}

int			ft_level_four(t_stc *stc)
{
	if (stc->linemate < 2)
		return (1);
	else if (stc->sibur < 1)
		return (3);
	else if (stc->phiras < 2)
		return (5);
	return (-1);
}
