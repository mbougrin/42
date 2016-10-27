/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:23:11 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/09 16:52:14 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_lst				*ft_return_lst(t_lst *new, t_lst *lst, t_flags *flg)
{
	if (flg->r == 1)
		return (lst);
	return (new);
}

int					ft_check_point(char *name)
{
	if (name[0] == '.' && name[1] != '/')
		return (0);
	return (-1);
}

void				ft_print_lst(t_lst *lst, t_flags *flg)
{
	if (flg->r == 1)
	{
		while (lst)
		{
			ft_putendl(lst->lstc->name);
			lst = lst->prev;
		}
		return ;
	}
	while (lst)
	{
		ft_putendl(lst->lstc->name);
		lst = lst->next;
	}
}

t_lst				*ft_lst_add(void)
{
	t_lst	*new;

	if ((new = (t_lst *)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	else
	{
		if ((new->lstc = (t_lstc *)malloc(sizeof(t_lstc))) == NULL)
			return (NULL);
		new->lstc->prot = NULL;
		new->lstc->nb_link = 0;
		new->lstc->user = NULL;
		new->lstc->group = NULL;
		new->lstc->size = 0;
		new->lstc->name = NULL;
		new->lstc->time = NULL;
		new->lstc->block = 0;
		new->prev = NULL;
		new->next = NULL;
		new->lstc->uid = 0;
		new->lstc->gid = 0;
		new->lstc->itime = 0;
	}
	return (new);
}
