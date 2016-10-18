/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 16:29:16 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/04 22:49:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list		*alst_tmp;

	if (new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		alst_tmp = *alst;
		new->next = alst_tmp;
		*alst = new;
	}
}
