/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:22:41 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/16 16:14:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int					ft_create_space(t_lst *lst, int nb, t_flags *flg)
{
	static int		ntab[4];

	if (nb != -1)
		return (ntab[nb]);
	if (flg->r == 1)
	{
		ntab[0] = ft_check_nb_link_prev(lst);
		ntab[1] = ft_check_name_prev(lst);
		ntab[2] = ft_check_group_prev(lst);
		ntab[3] = ft_check_size_prev(lst);
		return (-1);
	}
	ntab[0] = ft_check_nb_link(lst);
	ntab[1] = ft_check_name(lst);
	ntab[2] = ft_check_group(lst);
	ntab[3] = ft_check_size(lst);
	return (-1);
}

int					ft_ret_space_link(t_lst *lst)
{
	int		result;
	int		tmp;

	result = 0;
	tmp = lst->lstc->nb_link;
	if (tmp == 0)
		return (1);
	while (tmp > 0)
	{
		tmp /= 10;
		result++;
	}
	return (result);
}

int					ft_ret_space_size(t_lst *lst)
{
	int		result;
	int		tmp;

	result = 0;
	tmp = lst->lstc->size;
	if (tmp == 0)
		return (1);
	while (tmp > 0)
	{
		tmp /= 10;
		result++;
	}
	return (result);
}

int					ft_ret_space(t_lst *lst, int nb)
{
	if (nb == 0)
		return (ft_ret_space_link(lst));
	else if (nb == 1)
		return (ft_strlen(lst->lstc->user));
	else if (nb == 2)
		return (ft_strlen(lst->lstc->group));
	else if (nb == 3)
		return (ft_ret_space_size(lst));
	return (-1);
}

void				ft_print_space(int nb, int tab, t_lst *lst, t_flags *flg)
{
	int		tmp;
	int		tmp1;

	tmp = ft_create_space(NULL, tab, flg);
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
	}
	tmp1 = ft_ret_space(lst, tab);
	tmp = tmp - tmp1;
	while (tmp > 0)
	{
		ft_putchar(' ');
		tmp--;
	}
}
