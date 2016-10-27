/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_space_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:12:41 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/16 16:16:42 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int					ft_check_nb_link(t_lst *lst)
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
		lst = lst->next;
	}
	return (result);
}

int					ft_check_name(t_lst *lst)
{
	int		result;
	int		tmp;

	result = 0;
	while (lst)
	{
		tmp = ft_strlen(lst->lstc->user);
		if (tmp > result)
			result = tmp;
		lst = lst->next;
	}
	return (result);
}

int					ft_check_group(t_lst *lst)
{
	int		result;
	int		tmp;

	result = 0;
	while (lst)
	{
		tmp = ft_strlen(lst->lstc->group);
		if (tmp > result)
			result = tmp;
		lst = lst->next;
	}
	return (result);
}

int					ft_check_size(t_lst *lst)
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
		lst = lst->next;
	}
	return (result);
}
