/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 10:50:29 by scadoux           #+#    #+#             */
/*   Updated: 2013/12/15 04:35:17 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int				ft_key_word(t_data *alst, char *k_word, char *value)
{
	t_data		*alst_tmp;

	alst_tmp = alst;
	if (alst_tmp != NULL)
	{
	while (alst_tmp->next != NULL)
	{
		if (ft_strcmp(alst_tmp->k_word, k_word) == 0)
		{
			alst_tmp->k_word = ft_strdup(k_word);
			alst_tmp->value = ft_strdup(value);
			return (1);
		}
		alst_tmp = alst_tmp->next;
	}
		if (ft_strcmp(alst_tmp->k_word, k_word) == 0)
		{
			alst_tmp->k_word = ft_strdup(k_word);
			alst_tmp->value = ft_strdup(value);
			return (1);
		}
	}
	return (0);
}

static void			ft_check(t_data *alst, char *str)
{
	t_data		*alst_tmp;

	alst_tmp = alst;
	while (alst_tmp->next != NULL)
	{
		if (ft_strcmp(alst_tmp->k_word, str) == 0)
		{
			ft_putendl(alst_tmp->value);
			return ;
		}
		alst_tmp = alst_tmp->next;
	}
	if (ft_strcmp(alst_tmp->k_word, str) == 0)
	{
		ft_putendl(alst_tmp->value);
		return ;
	}
	ft_putstr(str);
	ft_putendl(": Not found.");
}

static void			ft_search(t_data *alst)
{
	t_struct	*ht;

	ht = (t_struct *)malloc(sizeof(t_struct));
	ht->str = NULL;
	while (get_next_line(0, &ht->str))
	{
		ft_check(alst, ht->str);
	}
}

void				hotrace(void)
{
	t_struct	*ht;

	ht = (t_struct *)malloc(sizeof(t_struct));
	ht->str = NULL;
	ht->i = 1;
	while (get_next_line(0, &ht->str))
	{
		if (ft_strncmp(ht->str, "\n", 1) == 0)
			break ;
		if (ht->i == (((ht->i - 1) / 2) * 2) + 1)
			ht->k_word = ft_strdup(ht->str);
		else
		{
			ht->value = ft_strdup(ht->str);
			if (ft_key_word(ht->alst, ht->k_word, ht->value) == 0)
				lst_add(&ht->alst, ht->k_word, ht->value);
		}
		ht->i++;
	}
	ft_search(ht->alst);
}
