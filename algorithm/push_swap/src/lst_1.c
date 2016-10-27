/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 13:33:05 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/27 13:34:51 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				lst_sa_sb(t_list **alst_1, t_list **alst_2)
{
	lst_s(&*alst_1, "ss");
	lst_s(&*alst_2, " ");
}

void				lst_ra_rb(t_list **alst_1, t_list **alst_2)
{
	lst_r(&*alst_1, "r");
	lst_r(&*alst_2, "r ");
}

void				lst_rra_rrb(t_list **alst_1, t_list **alst_2)
{
	lst_rr(&*alst_1, "rr");
	lst_rr(&*alst_2, "r ");
}

void				lst_rr(t_list **alst, char *s)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	struc->alst_tmp = (*alst)->next;
	while (struc->alst_tmp->next != *alst)
		struc->alst_tmp = struc->alst_tmp->next;
	*alst = struc->alst_tmp;
	ft_putstr(s);
	free(struc);
}
