/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:04:54 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/23 15:35:41 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content_size = 0;
		list->content = NULL;
	}
	else
	{
		list->content_size = content_size;
		list->content = ft_strnew(content_size);
		ft_strcpy(list->content, (char const *)content);
	}
	list->next = NULL;
	return (list);
}
