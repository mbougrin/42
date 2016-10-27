/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:25:32 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/09 16:52:08 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				ft_print_l_time_year(char *time)
{
	ft_putchar(time[4]);
	ft_putchar(time[5]);
	ft_putchar(time[6]);
	ft_putchar(' ');
	ft_putchar(time[8]);
	ft_putchar(time[9]);
	ft_putstr("  ");
	ft_putchar(time[20]);
	ft_putchar(time[21]);
	ft_putchar(time[22]);
	ft_putchar(time[23]);
}

void				ft_print_l_time(char *str_time, int itime)
{
	int		atime;

	atime = time(NULL);
	if (itime < (atime - SIXMONTHS))
		return (ft_print_l_time_year(str_time));
	ft_putchar(str_time[4]);
	ft_putchar(str_time[5]);
	ft_putchar(str_time[6]);
	ft_putchar(' ');
	ft_putchar(str_time[8]);
	ft_putchar(str_time[9]);
	ft_putchar(' ');
	ft_putchar(str_time[11]);
	ft_putchar(str_time[12]);
	ft_putchar(str_time[13]);
	ft_putchar(str_time[14]);
	ft_putchar(str_time[15]);
}

static void			ft_print_l_r(t_lst *lst, t_flags *flg)
{
	ft_print_total_r(lst);
	while (lst)
	{
		ft_putstr(lst->lstc->prot);
		ft_print_space(2, 0, lst, flg);
		ft_putnbr(lst->lstc->nb_link);
		ft_putchar(' ');
		ft_putstr(lst->lstc->user);
		ft_print_space(2, 1, lst, flg);
		ft_putstr(lst->lstc->group);
		ft_print_space(2, 2, lst, flg);
		ft_print_space(0, 3, lst, flg);
		ft_putnbr(lst->lstc->size);
		ft_putchar(' ');
		ft_print_l_time(lst->lstc->time, lst->lstc->itime);
		ft_putchar(' ');
		if (lst->lstc->prot[0] == 'l')
			ft_print_link(lst->lstc->name, lst->lstc->path);
		else
			ft_putendl(lst->lstc->name);
		lst = lst->prev;
	}
}

void				ft_print_total(t_lst *lst)
{
	int		total;

	total = 0;
	while (lst)
	{
		total += lst->lstc->block;
		lst = lst->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

void				ft_print_l(t_lst *lst, t_flags *flg)
{
	ft_create_space(lst, -1, flg);
	if (flg->r == 1)
		return (ft_print_l_r(lst, flg));
	ft_print_total(lst);
	while (lst)
	{
		ft_putstr(lst->lstc->prot);
		ft_print_space(2, 0, lst, flg);
		ft_putnbr(lst->lstc->nb_link);
		ft_putchar(' ');
		ft_putstr(lst->lstc->user);
		ft_print_space(2, 1, lst, flg);
		ft_putstr(lst->lstc->group);
		ft_print_space(2, 2, lst, flg);
		ft_print_space(0, 3, lst, flg);
		ft_putnbr(lst->lstc->size);
		ft_putchar(' ');
		ft_print_l_time(lst->lstc->time, lst->lstc->itime);
		ft_putchar(' ');
		if (lst->lstc->prot[0] == 'l')
			ft_print_link(lst->lstc->name, lst->lstc->path);
		else
			ft_putendl(lst->lstc->name);
		lst = lst->next;
	}
}
