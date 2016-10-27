/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 05:03:41 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/29 05:06:25 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_lst			*ft_check_order(t_lst *alst)
{
	t_lst	*tmp;

	tmp = alst;
	tmp = tmp->next;
	while (tmp->next != alst)
	{
		if (tmp->nb > tmp->next->nb)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int				ft_check_ra(t_lst **alst, int nb)
{
	int		result;
	t_lst	*tmp;

	result = 0;
	tmp = *alst;
	while (tmp->next != *alst)
	{
		if (tmp->nb == nb)
			return (result);
		result++;
		tmp = tmp->next;
	}
	if (tmp->nb == nb)
		return (result);
	return (0);
}

int				ft_check_rra(t_lst **alst, int nb)
{
	int		result;
	t_lst	*tmp;

	result = 0;
	tmp = *alst;
	while (tmp->prev != *alst)
	{
		if (tmp->nb == nb)
			return (result);
		result++;
		tmp = tmp->prev;
	}
	if (tmp->nb == nb)
		return (result);
	return (0);
}

int				ft_check_value(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j])
			{
				if (av[i][j] != '-')
					break ;
				j++;
			}
			if (ft_isdigit(av[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_check_sort(t_lst *alst)
{
	t_lst	*tmp;

	tmp = alst;
	while (tmp->next != alst)
	{
		if (tmp->nb > tmp->next->nb)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
