/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:17:54 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:47:22 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

t_list		*ft_create_elem(char *str)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->str = ft_strdup(str);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		ft_list_push_back(t_list **root, char *str)
{
	t_list	*ptr;

	ptr = (*root);
	if (*root == NULL)
	{
		*root = ft_create_elem(str);
		(*root)->prev = NULL;
		(*root)->next = NULL;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = ft_create_elem(str);
		ptr->next->prev = ptr;
	}
}

void		ft_list_push_front(t_list **root, char *str)
{
	t_list	*ptr;

	if (*root == NULL)
	{
		*root = ft_create_elem(str);
		(*root)->prev = NULL;
		(*root)->next = NULL;
	}
	else
	{
		ptr = ft_create_elem(str);
		ptr->next = *root;
		ptr->prev = NULL;
		(*root)->prev = ptr;
		*root = (*root)->prev;
	}
}
