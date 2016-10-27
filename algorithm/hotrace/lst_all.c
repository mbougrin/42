/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 00:39:42 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/15 03:18:15 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void				print_list(t_data **t_data)
{
	while (*t_data)
	{
		ft_putendl((*t_data)->k_word);
		ft_putendl((*t_data)->value);
		*t_data = (*t_data)->next;
	}
}

t_data				*lst_new(char *k_word, char *value)
{
	t_data *s_data;

	s_data = (t_data *)malloc(sizeof(t_data));
	s_data->k_word = k_word;
	s_data->value = value;
	s_data->next = NULL;
	return (s_data);
}

void				lst_add(t_data **alst, char *k_word, char *value)
{
	t_data		*alst_tmp;

	if (value == NULL || k_word == NULL)
		return ;
	if (*alst == NULL)
		*alst = lst_new(k_word, value);
	else
	{
		alst_tmp = *alst;
		while (alst_tmp->next != NULL)
			alst_tmp = alst_tmp->next;
		alst_tmp->next = lst_new(k_word, value);
	}
}
