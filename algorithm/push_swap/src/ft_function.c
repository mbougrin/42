/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 05:09:05 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/29 11:50:14 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_pb(t_lst **alst)
{
	t_lst	*blst;
	t_lst	*tmp;

	blst = ft_blst(NULL);
	tmp = NULL;
	if (blst == NULL)
	{
		blst = lst_add();
		blst->nb = (*alst)->nb;
		tmp = *alst;
		*alst = (*alst)->next;
		(*alst)->prev->prev->next = *alst;
		(*alst)->prev = (*alst)->prev->prev;
		ft_blst(blst);
		free(tmp);
	}
	else
		ft_pb_next(alst, tmp, blst);
	ft_putstr("pb ");
}

void			ft_pa(t_lst **alst)
{
	t_lst	*blst;
	t_lst	*tmp;

	blst = ft_blst(NULL);
	if (blst == NULL - 1)
		return ;
	if (blst->next == NULL)
		return (ft_check_one_pa(alst));
	if (blst->next->next == blst)
		return (ft_check_pa(alst));
	tmp = blst->prev;
	blst->prev->prev->next = blst;
	blst->prev = blst->prev->prev;
	tmp->prev = (*alst)->prev;
	tmp->next = *alst;
	(*alst)->prev->next = tmp;
	(*alst)->prev = tmp;
	*alst = (*alst)->prev;
	ft_putstr("pa");
	ft_blst(blst);
}

void			ft_sa(t_lst **alst)
{
	int		nb;

	nb = 0;
	nb = (*alst)->nb;
	(*alst)->nb = (*alst)->next->nb;
	(*alst)->next->nb = nb;
	ft_putstr("sa");
}

void			ft_ra(t_lst **alst)
{
	ft_putstr("ra");
	*alst = (*alst)->next;
}

void			ft_rra(t_lst **alst)
{
	ft_putstr("rra");
	*alst = (*alst)->prev;
}
