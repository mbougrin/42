/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 05:06:35 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/29 11:56:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int				ft_check_number(char **av)
{
	int			i;
	long int	nb;

	i = 0;
	while (av[i])
	{
		nb = 0;
		nb = ft_atol(av[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

int				ft_check_dbl(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_check_min(t_lst *alst)
{
	int		nb;
	t_lst	*tmp;

	tmp = alst;
	nb = tmp->nb;
	while (tmp->next != alst)
	{
		if (nb > tmp->nb)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	if (nb > tmp->nb)
		nb = tmp->nb;
	return (nb);
}

void			ft_check_pa(t_lst **alst)
{
	t_lst	*blst;
//	t_lst	*tmp;

	*alst = *alst;
/*	blst = ft_blst(NULL);
	tmp = blst->prev;
	tmp->prev = (*alst)->prev;
	tmp->next = *alst;
	(*alst)->prev->next = tmp;
	(*alst)->prev = tmp;
	*alst = (*alst)->prev;
	tmp = blst;
	tmp->prev = (*alst)->prev;
	tmp->next = *alst;
	(*alst)->prev->next = tmp;
	(*alst)->prev = tmp;
	*alst = (*alst)->prev;
*/	blst = NULL - 1;
	ft_blst(blst);
	ft_putendl("pa pa");
	exit(0);
}

void			ft_check_one_pa(t_lst **alst)
{
	t_lst	*blst;
	t_lst	*tmp;

	if ((*alst)->nb > (*alst)->next->nb && *alst == (*alst)->next->next)
	{
		ft_putendl("sa pa");
		exit(0);
	}
	blst = ft_blst(NULL);
	tmp = blst;
	tmp->prev = (*alst)->prev;
	tmp->next = *alst;
	(*alst)->prev->next = tmp;
	(*alst)->prev = tmp;
	*alst = (*alst)->prev;
	blst = NULL - 1;
	ft_blst(blst);
	ft_putstr("pa");
}
