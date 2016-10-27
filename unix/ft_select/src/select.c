/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 13:10:36 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/09 19:33:02 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void				ft_print_select(t_lst **alst)
{
	tputs(tgetstr("mr", NULL), 1, t_putchar);
	ft_putendl((*alst)->data);
	tputs(tgetstr("me", NULL), 1, t_putchar);
}

void				ft_print_cursor_and_select(t_lst **alst)
{
	tputs(tgetstr("us", NULL), 1, t_putchar);
	tputs(tgetstr("mr", NULL), 1, t_putchar);
	ft_putendl((*alst)->data);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
	tputs(tgetstr("me", NULL), 1, t_putchar);
}

void				ft_print_cursor(t_lst **alst)
{
	tputs(tgetstr("us", NULL), 1, t_putchar);
	ft_putendl((*alst)->data);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
}

int					ft_delete(t_lst **alst)
{
	t_tmp_lst	*tmp_lst;

	tmp_lst = (t_tmp_lst *)malloc(sizeof(t_tmp_lst));
	if ((*alst)->next == NULL)
		return (-1);
	*alst = ft_lst_del(&*alst);
	(*alst)->cursor = 1;
	while (1)
	{
		if ((*alst)->next == NULL)
			break ;
		tmp_lst->alst_tmp = (*alst)->prev;
		if ((*alst)->loc_nb < tmp_lst->alst_tmp->loc_nb)
			break ;
		*alst = (*alst)->next;
	}
	(*alst)->cursor = 0;
	return (-2);
}

int					ft_cursor_up(int i, t_lst **alst)
{
	while (i >= 0)
	{
		if ((*alst)->cursor == 1)
		{
			(*alst)->cursor = 0;
			break ;
		}
		*alst = (*alst)->prev;
		tputs(tgetstr("up", NULL), 1, t_putchar);
		i--;
	}
	i++;
	if ((*alst)->select == 1)
		ft_print_cursor_and_select(&*alst);
	else
		ft_print_cursor(&*alst);
	tputs(tgetstr("up", NULL), 1, t_putchar);
	return (i);
}
