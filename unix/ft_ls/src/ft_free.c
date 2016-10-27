/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 09:11:15 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/06 02:56:59 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				ft_print_total_r(t_lst *lst)
{
	int		total;

	total = 0;
	while (lst)
	{
		total += lst->lstc->block;
		lst = lst->prev;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

static void			ft_free_lst(t_lst **lst, t_flags **flg)
{
	if ((*flg)->l == 1)
	{
		if ((*lst)->prev->lstc->user != NULL)
			ft_strdel(&(*lst)->prev->lstc->user);
		if ((*lst)->prev->lstc->group != NULL)
			ft_strdel(&(*lst)->prev->lstc->group);
		ft_strdel(&(*lst)->prev->lstc->time);
		ft_strdel(&(*lst)->prev->lstc->name);
		ft_strdel(&(*lst)->prev->lstc->prot);
		free((*lst)->prev->lstc);
		free((*lst)->prev);
	}
	else
	{
		ft_strdel(&(*lst)->prev->lstc->time);
		ft_strdel(&(*lst)->prev->lstc->name);
		free((*lst)->prev->lstc);
		free((*lst)->prev);
	}
}

static void			ft_free_end(t_lst **lst, t_flags **flg)
{
	if ((*flg)->l == 1)
	{
		if ((*lst)->lstc->user != NULL)
			ft_strdel(&(*lst)->lstc->user);
		if ((*lst)->lstc->group != NULL)
			ft_strdel(&(*lst)->lstc->group);
		ft_strdel(&(*lst)->lstc->time);
		ft_strdel(&(*lst)->lstc->name);
		ft_strdel(&(*lst)->lstc->prot);
		free((*lst)->lstc);
		free(*lst);
	}
	else
	{
		ft_strdel(&(*lst)->lstc->time);
		ft_strdel(&(*lst)->lstc->name);
		free((*lst)->lstc);
		free(*lst);
	}
}

static void			ft_free_lst_prev(t_lst **lst, t_flags **flg)
{
	if ((*flg)->l == 1)
	{
		if ((*lst)->next->lstc->user != NULL)
			ft_strdel(&(*lst)->next->lstc->user);
		if ((*lst)->next->lstc->group != NULL)
			ft_strdel(&(*lst)->next->lstc->group);
		ft_strdel(&(*lst)->next->lstc->time);
		ft_strdel(&(*lst)->next->lstc->name);
		ft_strdel(&(*lst)->next->lstc->prot);
		free((*lst)->next->lstc);
		free((*lst)->next);
	}
	else
	{
		ft_strdel(&(*lst)->next->lstc->time);
		ft_strdel(&(*lst)->next->lstc->name);
		free((*lst)->next->lstc);
		free((*lst)->next);
	}
}

void				ft_free(t_lst **lst, t_flags **flg)
{
	while (*lst)
	{
		if ((*flg)->r == 0 && (*lst)->next == NULL)
			break ;
		else if ((*lst)->prev == NULL)
			break ;
		if ((*flg)->r == 0)
		{
			*lst = (*lst)->next;
			ft_free_lst(lst, flg);
		}
		else
		{
			*lst = (*lst)->prev;
			ft_free_lst_prev(lst, flg);
		}
	}
	ft_free_end(lst, flg);
}
