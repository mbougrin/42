/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 13:00:40 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/09 19:11:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int			ft_space_end_zero(int i, t_lst **alst)
{
	tputs(tgetstr("mr", NULL), 1, t_putchar);
	ft_putstr((*alst)->data);
	(*alst)->select = 1;
	tputs(tgetstr("me", NULL), 1, t_putchar);
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

static int			ft_space_after_zero(int i, t_lst **alst)
{
	tputs(tgetstr("mr", NULL), 1, t_putchar);
	ft_putstr((*alst)->data);
	(*alst)->select = 1;
	tputs(tgetstr("me", NULL), 1, t_putchar);
	tputs(tgetstr("do", NULL), 1, t_putchar);
	*alst = (*alst)->next;
	tputs(tgetstr("us", NULL), 1, t_putchar);
	if ((*alst)->select == 1)
		ft_print_select(&*alst);
	else
		ft_putendl((*alst)->data);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
	tputs(tgetstr("up", NULL), 1, t_putchar);
	i++;
	return (i);
}

static int			ft_space_end_select(int i, t_lst **alst)
{
	ft_putstr((*alst)->data);
	(*alst)->select = 0;
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

static int			ft_space_after_select(int i, t_lst **alst)
{
	ft_putstr((*alst)->data);
	(*alst)->select = 0;
	tputs(tgetstr("do", NULL), 1, t_putchar);
	*alst = (*alst)->next;
	tputs(tgetstr("us", NULL), 1, t_putchar);
	if ((*alst)->select == 1)
		ft_print_select(&*alst);
	else
		ft_putendl((*alst)->data);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
	tputs(tgetstr("up", NULL), 1, t_putchar);
	i++;
	return (i);
}

int					ft_space(int i, int j, t_lst **alst)
{
	if ((*alst)->next == NULL && (*alst)->select == 1)
	{
		(*alst)->select = 0;
		ft_print_cursor(&*alst);
		tputs(tgetstr("up", NULL), 1, t_putchar);
		return (i);
	}
	else if ((*alst)->next == NULL && (*alst)->select == 0)
	{
		(*alst)->select = 1;
		ft_print_cursor_and_select(&*alst);
		tputs(tgetstr("up", NULL), 1, t_putchar);
		return (i);
	}
	if (i > j - 1 && (*alst)->select == 1)
		i = ft_space_end_select(i, &*alst);
	else if ((*alst)->select == 1)
		i = ft_space_after_select(i, &*alst);
	else if (i > j - 1)
		i = ft_space_end_zero(i, &*alst);
	else
		i = ft_space_after_zero(i, &*alst);
	return (i);
}
