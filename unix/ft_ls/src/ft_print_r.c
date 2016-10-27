/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 11:21:45 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/09 16:52:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_lst				*ft_sort_r(char *str, t_lst *lst, t_flags *flg)
{
	if (ft_ls_error(str, flg) == -1)
		return (NULL);
	if (ft_check_ln(str, flg) == -1)
		return (NULL);
	lst = ft_create_lst(str, flg);
	if (lst == NULL)
		return (NULL);
	if (flg->t == 1 && flg->r == 1)
		ft_sort_time_r(&lst);
	else if (flg->r == 1)
		ft_sort_ascii_r(&lst);
	else if (flg->t == 1 && flg->r == 0)
		ft_sort_time(&lst);
	else
		ft_sort_ascii(&lst);
	if (flg->l == 1)
		ft_print_l(lst, flg);
	else
		ft_print_lst(lst, flg);
	return (lst);
}

void				ft_print_r_next(char *str, char *ptr)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '/')
			result++;
		i++;
	}
	if (result == 1 && str[0] == '/')
	{
		ft_putchar('\n');
		ft_putstr(&ptr[1]);
		ft_putendl(":");
	}
	else
	{
		ft_putchar('\n');
		ft_putstr(ptr);
		ft_putendl(":");
	}
}

t_lst				*ft_return_r(char *ptr, t_lst *tmp, t_flags *flg)
{
	ft_strdel(&ptr);
	if (flg->r == 1)
		tmp = tmp->prev;
	else
		tmp = tmp->next;
	return (tmp);
}

char				*ft_join_ls(char *str, t_lst *tmp)
{
	if (str[ft_strlen(str) - 1] == '/')
		return (ft_strjoin(str, tmp->lstc->name));
	else
		return (ft_strstrjoin(3, str, "/", tmp->lstc->name));
	return (NULL);
}

void				ft_print_r(char *str, t_flags *flg)
{
	t_lst	*lst;
	t_lst	*tmp;
	char	*ptr;

	if ((lst = ft_sort_r(str, lst, flg)) == NULL)
		return ;
	tmp = lst;
	while (tmp)
	{
		ptr = ft_join_ls(str, tmp);
		if (tmp->lstc->mode & S_IFDIR)
		{
			if (ft_strcmp(tmp->lstc->name, ".") != 0 && \
					ft_strcmp(tmp->lstc->name, "..") != 0)
			{
				ft_print_r_next(str, ptr);
				ft_print_r(ptr, flg);
			}
		}
		tmp = ft_return_r(ptr, tmp, flg);
	}
	ft_free(&lst, &flg);
}
