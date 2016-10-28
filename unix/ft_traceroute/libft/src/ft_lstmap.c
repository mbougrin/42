/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 19:14:42 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/05 00:21:54 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	new = NULL;
	while (lst != NULL)
	{
		if (new == NULL)
		{
			new = ft_lstnew(f(lst)->content, f(lst)->content_size);
			tmp = new;
		}
		else
		{
			tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (new);
}
