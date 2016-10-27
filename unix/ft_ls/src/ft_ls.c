/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:30:28 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/10 15:00:30 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				ft_sort_ascii_r(t_lst **lst)
{
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lstc	*tmp;

	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->prev;
		while (tmp2)
		{
			if (ft_strcmp(tmp1->lstc->name, tmp2->lstc->name) < 0)
			{
				tmp = tmp1->lstc;
				tmp1->lstc = tmp2->lstc;
				tmp2->lstc = tmp;
			}
			tmp2 = tmp2->prev;
		}
		tmp1 = tmp1->prev;
	}
}

void				ft_sort_ascii(t_lst **lst)
{
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lstc	*tmp;

	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp1->lstc->name, tmp2->lstc->name) > 0)
			{
				tmp = tmp1->lstc;
				tmp1->lstc = tmp2->lstc;
				tmp2->lstc = tmp;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void				ft_sort_time(t_lst **lst)
{
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lstc	*tmp;

	ft_sort_ascii(lst);
	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->lstc->itime < tmp2->lstc->itime)
			{
				tmp = tmp1->lstc;
				tmp1->lstc = tmp2->lstc;
				tmp2->lstc = tmp;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void				ft_sort_time_r(t_lst **lst)
{
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lstc	*tmp;

	ft_sort_ascii_r(lst);
	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->prev;
		while (tmp2)
		{
			if (tmp1->lstc->itime < tmp2->lstc->itime)
			{
				tmp = tmp1->lstc;
				tmp1->lstc = tmp2->lstc;
				tmp2->lstc = tmp;
			}
			tmp2 = tmp2->prev;
		}
		tmp1 = tmp1->prev;
	}
}

void				ft_ls(char *str, t_flags *flg)
{
	t_lst	*lst;

	if (str == NULL)
		str = ".";
	if (flg->gr == 1)
		return (ft_print_r(str, flg));
	if (ft_ls_error(str, flg) == -1)
		return ;
	if (ft_check_ln(str, flg) == -1)
		return ;
	lst = ft_create_lst(str, flg);
	if (flg->t == 1 && flg->r == 1)
		ft_sort_time_r(&lst);
	else if (flg->r == 1)
		ft_sort_ascii_r(&lst);
	else if (flg->t == 1 && flg->r == 0)
		ft_sort_time(&lst);
	else
		ft_sort_ascii(&lst);
	if (flg->l == 1)
		ft_print_l(lst, flg);
	else
		ft_print_lst(lst, flg);
	ft_free(&lst, &flg);
}
