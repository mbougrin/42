/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:52:05 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/09 18:59:40 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int			ft_up_end(t_lst **alst, int i, int j)
{
	if ((*alst)->select == 1)
	{
		ft_print_select(&*alst);
		tputs(tgetstr("up", NULL), 1, t_putchar);
	}
	else
		ft_putstr((*alst)->data);
	while (i < j + 1)
	{
		tputs(tgetstr("do", NULL), 1, t_putchar);
		*alst = (*alst)->next;
		i++;
	}
	return (i);
}

int					ft_up(t_lst **alst, int i, int j)
{
	if ((*alst)->next == NULL)
		return (i);
	if (i < 1)
		i = ft_up_end(&*alst, i, j);
	if (i != j + 1)
	{
		if ((*alst)->select == 1)
			ft_print_select(&*alst);
		else
			ft_putendl((*alst)->data);
		tputs(tgetstr("up", NULL), 1, t_putchar);
	}
	tputs(tgetstr("up", NULL), 1, t_putchar);
	tputs(tgetstr("us", NULL), 1, t_putchar);
	*alst = (*alst)->prev;
	if ((*alst)->select == 1)
		ft_print_select(&*alst);
	else
		ft_putendl((*alst)->data);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
	tputs(tgetstr("up", NULL), 1, t_putchar);
	i--;
	return (i);
}
