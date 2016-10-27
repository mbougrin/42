/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:55:28 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/09 18:59:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int			ft_down_end(t_lst **alst, int i)
{
	if ((*alst)->select == 1)
	{
		ft_print_select(&*alst);
		tputs(tgetstr("up", NULL), 1, t_putchar);
	}
	else
		ft_putstr((*alst)->data);
	while (i > 0)
	{
		tputs(tgetstr("up", NULL), 1, t_putchar);
		*alst = (*alst)->prev;
		i--;
	}
	tputs(tgetstr("up", NULL), 1, t_putchar);
	tputs(tgetstr("us", NULL), 1, t_putchar);
	tputs(tgetstr("do", NULL), 1, t_putchar);
	tputs(tgetstr("up", NULL), 1, t_putchar);
	if ((*alst)->select == 1)
		ft_print_select(&*alst);
	else
		ft_putendl((*alst)->data);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
	tputs(tgetstr("up", NULL), 1, t_putchar);
	return (i);
}

static int			ft_down_after(t_lst **alst, int i)
{
	if ((*alst)->select == 1)
	{
		ft_print_select(&*alst);
		tputs(tgetstr("up", NULL), 1, t_putchar);
	}
	else
		ft_putstr((*alst)->data);
	tputs(tgetstr("do", NULL), 1, t_putchar);
	tputs(tgetstr("us", NULL), 1, t_putchar);
	*alst = (*alst)->next;
	if ((*alst)->select == 1)
		ft_print_select(&*alst);
	else
		ft_putendl((*alst)->data);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
	tputs(tgetstr("up", NULL), 1, t_putchar);
	i++;
	return (i);
}

int					ft_down(t_lst **alst, int i, int j)
{
	if ((*alst)->next == NULL)
		return (i);
	if (i > j - 1)
		i = ft_down_end(&*alst, i);
	else
		i = ft_down_after(&*alst, i);
	return (i);
}
