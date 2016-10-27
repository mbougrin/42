/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 05:11:55 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/29 06:04:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_pb_next(t_lst **alst, t_lst *tmp, t_lst *blst)
{
	tmp = lst_add();
	if (blst->next == NULL)
	{
		tmp->next = blst;
		tmp->prev = blst;
		blst->next = tmp;
		blst->prev = tmp;
	}
	else
	{
		tmp->prev = blst->prev;
		tmp->next = blst;
		blst->prev->next = tmp;
		blst->prev = tmp;
	}
	tmp->nb = (*alst)->nb;
	tmp = *alst;
	*alst = (*alst)->next;
	(*alst)->prev->prev->next = *alst;
	(*alst)->prev = (*alst)->prev->prev;
	ft_blst(blst);
	if (tmp != NULL)
		tmp = NULL;
}

void			ft_swap_sa(t_lst **alst)
{
	ft_sa(alst);
	ft_putchar(' ');
	ft_pb(alst);
}

void			ft_swap_rra_pb(t_lst **alst, int rra, int nb)
{
	nb = nb;
	while (rra > 0)
	{
		ft_rra(alst);
		ft_putchar(' ');
		rra--;
	}
	ft_pb(alst);
}

void			ft_swap_ra_pb(t_lst **alst, int ra, int nb)
{
	nb = nb;
	while (ra > 0)
	{
		ft_ra(alst);
		ft_putchar(' ');
		ra--;
	}
	ft_pb(alst);
}

void			ft_swap_pa(t_lst **alst)
{
	while (1)
	{
		ft_pa(alst);
		if (ft_blst(NULL) == NULL - 1)
			break ;
		ft_putchar(' ');
	}
}
