/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_space_prev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:12:38 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/12 16:22:19 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int					ft_check_nb_link_prev(t_lst *lst)
{
	int		result;
	int		i;
	int		tmp;

	result = 0;
	while (lst)
	{
		i = 0;
		tmp = lst->lstc->nb_link;
		while (tmp > 0)
		{
			tmp /= 10;
			i++;
		}
		if (result < i)
			result = i;
		lst = lst->prev;
	}
	return (result);
}

int					ft_check_name_prev(t_lst *lst)
{
	int		result;
	int		tmp;

	result = 0;
	while (lst)
	{
		tmp = ft_strlen(lst->lstc->user);
		if (tmp > result)
			result = tmp;
		lst = lst->prev;
	}
	return (result);
}

int					ft_check_group_prev(t_lst *lst)
{
	int		result;
	int		tmp;

	result = 0;
	while (lst)
	{
		tmp = ft_strlen(lst->lstc->group);
		if (tmp > result)
			result = tmp;
		lst = lst->prev;
	}
	return (result);
}

int					ft_check_size_prev(t_lst *lst)
{
	int		result;
	int		i;
	int		tmp;

	result = 0;
	while (lst)
	{
		i = 0;
		tmp = lst->lstc->size;
		while (tmp > 0)
		{
			tmp /= 10;
			i++;
		}
		if (result < i)
			result = i;
		lst = lst->prev;
	}
	return (result);
}
