/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_level.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:02:16 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/24 09:56:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

int			ft_level_five(t_stc *stc)
{
	if (stc->linemate < 1)
		return (1);
	else if (stc->deraumere < 2)
		return (2);
	else if (stc->sibur < 1)
		return (3);
	else if (stc->mendiane < 3)
		return (4);
	return (-1);
}

int			ft_level_sixe(t_stc *stc)
{
	if (stc->linemate < 1)
		return (1);
	else if (stc->deraumere < 2)
		return (2);
	else if (stc->sibur < 3)
		return (3);
	else if (stc->phiras < 1)
		return (5);
	return (-1);
}

int			ft_level_seven(t_stc *stc)
{
	if (stc->linemate < 2)
		return (1);
	else if (stc->deraumere < 2)
		return (2);
	else if (stc->sibur < 2)
		return (3);
	else if (stc->mendiane < 2)
		return (4);
	else if (stc->phiras < 2)
		return (5);
	else if (stc->thystame < 1)
		return (6);
	return (-1);
}

void		*ft_ptr_function(int lvl)
{
	if (lvl == 1)
		return (&ft_level_one);
	if (lvl == 2)
		return (&ft_level_two);
	if (lvl == 3)
		return (&ft_level_three);
	if (lvl == 4)
		return (&ft_level_four);
	if (lvl == 5)
		return (&ft_level_five);
	if (lvl == 6)
		return (&ft_level_sixe);
	if (lvl == 7)
		return (&ft_level_seven);
	return (NULL);
}

int			ft_check_level_up(t_stc *stc)
{
	int		(*ptr)(t_stc *);

	ptr = ft_ptr_function(stc->level);
	if (ptr == NULL)
		return (-2);
	return (ptr(stc));
}
