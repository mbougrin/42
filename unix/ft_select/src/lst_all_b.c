/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_all_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 13:20:26 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/11 03:38:22 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int					ft_lst_print(t_lst **alst)
{
	t_tmp_lst	*tmp_lst;
	int			i;

	i = 0;
	tmp_lst = (t_tmp_lst *)malloc(sizeof(t_tmp_lst));
	tmp_lst->alst_tmp = *alst;
	while (tmp_lst->alst_tmp->next != *alst)
	{
		if (tmp_lst->alst_tmp->select == 1)
			ft_print_select(&tmp_lst->alst_tmp);
		else if (tmp_lst->alst_tmp->cursor == 1)
			ft_print_cursor(&tmp_lst->alst_tmp);
		else
			ft_putendl(tmp_lst->alst_tmp->data);
		tmp_lst->alst_tmp = tmp_lst->alst_tmp->next;
		i++;
	}
	if (tmp_lst->alst_tmp->select == 1)
		ft_print_select(&tmp_lst->alst_tmp);
	else if (tmp_lst->alst_tmp->cursor == 1)
		ft_print_cursor(&tmp_lst->alst_tmp);
	else
		ft_putendl(tmp_lst->alst_tmp->data);
	free(tmp_lst);
	return (i);
}

static void			ft_print_return_end_lst(t_lst **alst, int i)
{
	if ((*alst)->select == 1)
	{
		ft_putstr((*alst)->data);
		i++;
	}
	if (i > 0)
		ft_putchar('\n');
	exit(0);
}

void				ft_print_select_return(t_lst **alst)
{
	t_tmp_lst		*tmp_lst;
	int				i;

	tmp_lst = (t_tmp_lst *)malloc(sizeof(t_tmp_lst));
	i = 0;
	if ((*alst)->next == NULL)
		ft_print_return_end_lst(&*alst, i);
	*alst = ft_sort_first(&*alst);
	tmp_lst->alst_tmp = (*alst)->prev;
	(*alst)->prev = NULL;
	tmp_lst->alst_tmp->next = NULL;
	while ((*alst)->next != NULL)
	{
		if ((*alst)->select == 1)
		{
			ft_putstr((*alst)->data);
			ft_putchar(' ');
			i++;
		}
		*alst = (*alst)->next;
	}
	free(tmp_lst);
	ft_print_return_end_lst(&*alst, i);
}

t_lst				*ft_sort_first(t_lst **alst)
{
	t_tmp_lst	*tmp_lst;

	tmp_lst = (t_tmp_lst *)malloc(sizeof(t_tmp_lst));
	while (1)
	{
		tmp_lst->alst_tmp = (*alst)->prev;
		if ((*alst)->loc_nb < tmp_lst->alst_tmp->loc_nb)
			break ;
		*alst = (*alst)->next;
	}
	free(tmp_lst);
	return (*alst);
}
