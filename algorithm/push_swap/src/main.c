/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 22:41:01 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/29 06:04:20 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_sort_algo(t_lst **alst)
{
	int		nb;
	int		rra;
	int		ra;

	nb = ft_check_min(*alst);
	if ((*alst)->next->nb == nb && (*alst)->next->next != *alst)
		return (ft_swap_sa(alst));
	if ((*alst)->next->next == *alst)
		return (ft_swap_pa(alst));
	rra = ft_check_rra(alst, nb);
	ra = ft_check_ra(alst, nb);
	if (rra < ra)
		ft_swap_rra_pb(alst, rra, nb);
	else
		ft_swap_ra_pb(alst, ra, nb);
}

t_lst			*ft_blst(t_lst *tmp)
{
	static t_lst	*blst;

	if (tmp != NULL)
		blst = tmp;
	return (blst);
}

int				ft_check_swap_end(t_lst *alst)
{
	t_lst	*tmp;

	tmp = alst;
	while (tmp->next->next != alst)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	ft_putendl("rra rra sa ra ra");
	return (-1);
}

void			ft_push_swap(char **av, int ac)
{
	t_lst	*alst;

	if (ft_check_number(av) == -1)
		return (ft_putendl_fd("args is too big number", 2));
	if (ft_check_value(av) == -1)
		return (ft_putendl_fd("args is not a number", 2));
	else
		alst = ft_create_lst(av, ac);
	if (ft_check_sort(alst) == 0)
		return ;
	if (alst->prev == ft_check_order(alst))
		return (ft_putendl("sa"));
	if (ft_check_swap_end(alst) == -1)
		return ;
	while (1)
	{
		if (ft_check_sort(alst) == 0 && ft_blst(NULL) == NULL - 1)
			break ;
		ft_sort_algo(&alst);
		if (ft_check_sort(alst) != 0 && ft_blst(NULL) == NULL - 1)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

int				main(int ac, char **av)
{
	if (ac >= 3)
	{
		if (ft_check_dbl(av) == -1)
		{
			ft_putendl_fd("args error", 2);
			return (0);
		}
		ft_push_swap(&av[1], ac);
	}
	else
		ft_putendl_fd("too few args", 2);
	return (0);
}
