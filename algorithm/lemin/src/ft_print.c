/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:29:11 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/23 17:31:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void			ft_print_lst(t_lst **alst)
{
	t_lst	*tmp;

	tmp = *alst;
	while (tmp)
	{
		ft_putendl(tmp->room);
		tmp = tmp->next;
	}
}

void			ft_print_move_ants(t_lst *alst, int count)
{
	ft_putchar('L');
	ft_putnbr(alst->number_ants);
	ft_putchar('-');
	ft_putstr(alst->room);
	if (count == 0)
		ft_putchar(' ');
	else
		ft_putchar('\n');
}
