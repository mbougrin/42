/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 15:01:15 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/27 13:36:04 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				lst_pa(t_list **alst_1, t_list **alst_2)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	struc->tmp = *alst_2;
	*alst_2 = (*alst_2)->next;
	(*alst_2)->prev = struc->tmp->prev;
	struc->alst_tmp = *alst_2;
	while (struc->alst_tmp->next != struc->tmp)
		struc->alst_tmp = struc->alst_tmp->next;
	struc->alst_tmp->next = struc->tmp->next;
	struc->alst_tmp = *alst_1;
	(*alst_1)->prev = struc->tmp;
	struc->tmp->next = *alst_1;
	while (struc->alst_tmp->next != *alst_1)
		struc->alst_tmp = struc->alst_tmp->next;
	struc->alst_tmp->next = struc->tmp;
	struc->alst_tmp->prev = struc->alst_tmp;
	*alst_1 = struc->alst_tmp->next;
	free(struc);
	write(1, "pa ", 3);
}

void				lst_pb_b(t_list **alst_1, t_list **alst_2)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	struc->tmp = *alst_1;
	*alst_1 = (*alst_1)->next;
	(*alst_1)->prev = struc->tmp->prev;
	struc->alst_tmp = *alst_1;
	while (struc->alst_tmp->next != struc->tmp)
		struc->alst_tmp = struc->alst_tmp->next;
	struc->alst_tmp->next = struc->tmp->next;
	struc->alst_tmp = *alst_2;
	(*alst_2)->prev = struc->tmp;
	struc->tmp->next = *alst_2;
	while (struc->alst_tmp->next != *alst_2)
		struc->alst_tmp = struc->alst_tmp->next;
	struc->alst_tmp->next = struc->tmp;
	struc->alst_tmp->prev = struc->alst_tmp;
	*alst_2 = struc->alst_tmp->next;
	free(struc);
}

void				lst_pb(t_list **alst_1, t_list **alst_2)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	if (*alst_2 == NULL)
	{
		*alst_2 = *alst_1;
		*alst_1 = (*alst_1)->next;
		(*alst_1)->prev = (*alst_2)->prev;
		struc->alst_tmp = *alst_1;
		while (struc->alst_tmp->next != *alst_2)
			struc->alst_tmp = struc->alst_tmp->next;
		struc->alst_tmp->next = (*alst_2)->next;
		(*alst_2)->next = *alst_2;
		(*alst_2)->prev = *alst_2;
		free(struc);
	}
	else
	{
		lst_pb_b(alst_1, alst_2);
	}
	write(1, "pb ", 3);
}

void				lst_r(t_list **alst, char *s)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	struc->alst_tmp = (*alst)->next;
	*alst = struc->alst_tmp;
	ft_putstr(s);
	free(struc);
}

void				lst_s(t_list **alst, char *s)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	struc->alst_tmp = (*alst)->next;
	struc->tmp_nb = struc->alst_tmp->nb;
	struc->alst_tmp->nb = (*alst)->nb;
	(*alst)->nb = struc->tmp_nb;
	ft_putstr(s);
	free(struc);
}
