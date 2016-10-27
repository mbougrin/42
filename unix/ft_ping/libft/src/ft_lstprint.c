/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:00:20 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/04 19:23:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_lstprint(t_list **alst)
{
	while (*alst)
	{
		ft_putendl((*alst)->content);
		*alst = (*alst)->next;
	}
}
