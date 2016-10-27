/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 17:33:06 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/27 13:48:15 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int			ft_check(t_list **alst_1, t_list **alst_2, int i)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	if (i > 0)
		check_alst(&*alst_1, &*alst_2, i);
	struc->alst_1 = *alst_1;
	struc->tmp = (*alst_1)->next;
	while (struc->alst_1->next != *alst_1)
	{
		if (struc->tmp->nb < struc->alst_1->nb)
		{
			free(struc);
			return (0);
		}
		struc->tmp = struc->tmp->next;
		struc->alst_1 = struc->alst_1->next;
	}
	free(struc);
	return (1);
}

static void			ft_sort(t_list **alst_1, t_list **alst_2, int ac)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	struc->j = 0;
	struc->alst_1 = *alst_1;
	struc->tmp = (*alst_1)->next;
	while (ft_check(&struc->alst_1, &*alst_2, 0) == 0)
	{
		if (struc->alst_1->nb > struc->tmp->nb)
		{
			lst_s(&struc->alst_1, "sa ");
			struc->tmp = struc->tmp->next;
		}
		else
		{
			lst_r(&struc->alst_1, "ra ");
			struc->tmp = struc->alst_1->next;
		}
		struc->j++;
		if (struc->j == ac)
		{
			struc->j = 0;
			struc->alst_1 = *alst_1;
		}
	}
}

static void			ft_push_swap(t_list **alst, int ac)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	struc->alst_1 = *alst;
	struc->alst_2 = NULL;
	ft_sort(&struc->alst_1, &struc->alst_2, ac);
	ft_putchar('\n');
	free(struc);
}

static void			push_swap(int ac, char **av)
{
	t_struct	*struc;

	struc = (t_struct *)malloc(sizeof(t_struct));
	struc->ac_tmp = ac;
	struc->i = 1;
	struc->alst_1 = NULL;
	while (struc->ac_tmp > 1)
	{
		ft_lstadd_next(&struc->alst_1, av[struc->i]);
		struc->i++;
		struc->ac_tmp--;
	}
	ft_push_swap(&struc->alst_1, ac);
	free(struc);
}

int					main(int ac, char **av)
{
	if (ac == 1)
		write(2, "Error\n", 6);
	else
		push_swap(ac, av);
	return (0);
}
