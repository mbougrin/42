/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 01:07:22 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/22 20:00:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				ft_print_lst(t_lst *alst)
{
	t_lst	*tmp;

	tmp = alst;
	while (tmp->next != alst)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putnbr(tmp->nb);
	ft_putchar('\n');
}

t_lst				*ft_lst(int ac)
{
	int		i;
	t_lst	*lst;
	t_lst	*tmp;

	i = 0;
	lst = lst_add();
	tmp = lst;
	while (i < (ac - 2))
	{
		tmp->next = lst_add();
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp->next = lst;
	lst->prev = tmp;
	return (lst);
}

t_lst				*ft_create_lst(char **av, int ac)
{
	t_lst	*alst;
	t_lst	*tmp;
	int		i;

	i = 0;
	alst = ft_lst(ac);
	tmp = alst;
	while (av[i])
	{
		tmp->nb = ft_atoi(av[i]);
		i++;
		tmp = tmp->next;
	}
	return (alst);
}

t_lst				*lst_add(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->nb = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
