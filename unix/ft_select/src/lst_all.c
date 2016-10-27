/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:46:19 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/10 23:00:38 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_lst				*ft_lst_del(t_lst **alst)
{
	t_tmp_lst	*tmp_lst;

	tmp_lst = (t_tmp_lst *)malloc(sizeof(t_tmp_lst));
	tmp_lst->alst_tmp = *alst;
	tmp_lst->tmp = (*alst)->prev;
	*alst = (*alst)->next;
	if ((*alst)->next == tmp_lst->alst_tmp)
	{
		(*alst)->next = NULL;
		(*alst)->prev = NULL;
		return (*alst);
	}
	else
	{
		(*alst)->prev = tmp_lst->tmp;
		tmp_lst->tmp->next = *alst;
		free(tmp_lst->alst_tmp->data);
		free(tmp_lst->alst_tmp);
	}
	return (*alst);
}

t_lst				*ft_lst_new(char *s)
{
	static int	i;
	t_lst		*lst;

	if (s == NULL)
		return (NULL);
	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->data = ft_strdup(s);
	lst->loc_nb = i;
	lst->cursor = 0;
	lst->select = 0;
	lst->prev = NULL;
	lst->next = NULL;
	i++;
	return (lst);
}

void				ft_lst_add_next(t_lst **alst, char *s)
{
	t_tmp_lst		*tmp_lst;

	tmp_lst = (t_tmp_lst *)malloc(sizeof(t_tmp_lst));
	if (s == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = ft_lst_new(s);
		(*alst)->next = *alst;
		(*alst)->prev = *alst;
	}
	else
	{
		tmp_lst->alst_tmp = *alst;
		tmp_lst->tmp = ft_lst_new(s);
		(*alst)->prev = tmp_lst->tmp;
		tmp_lst->tmp->next = *alst;
		while (tmp_lst->alst_tmp->next != *alst)
			tmp_lst->alst_tmp = tmp_lst->alst_tmp->next;
		tmp_lst->alst_tmp->next = tmp_lst->tmp;
		tmp_lst->tmp->prev = tmp_lst->alst_tmp;
	}
	free(tmp_lst);
}

void				ft_lst_add(t_lst **alst, char *s)
{
	t_tmp_lst	*tmp_lst;

	tmp_lst = (t_tmp_lst *)malloc(sizeof(t_tmp_lst));
	if (s == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = ft_lst_new(s);
		(*alst)->next = *alst;
		(*alst)->prev = *alst;
	}
	else
	{
		tmp_lst->alst_tmp = *alst;
		tmp_lst->tmp = ft_lst_new(s);
		(*alst)->prev = tmp_lst->tmp;
		tmp_lst->tmp->next = *alst;
		while (tmp_lst->alst_tmp->next != *alst)
			tmp_lst->alst_tmp = tmp_lst->alst_tmp->next;
		tmp_lst->alst_tmp->next = tmp_lst->tmp;
		tmp_lst->tmp->prev = tmp_lst->alst_tmp;
		*alst = tmp_lst->alst_tmp->next;
	}
	free(tmp_lst);
}
