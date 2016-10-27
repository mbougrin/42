/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:00:20 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/23 13:02:21 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void				print_list(t_list **alst)
{
	while (*alst)
	{
		ft_putendl((*alst)->content);
		*alst = (*alst)->next;
	}
}
