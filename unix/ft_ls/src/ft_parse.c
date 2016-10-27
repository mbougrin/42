/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 12:26:04 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/08 14:25:13 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char				**ft_loop_found(int ac, char **av)
{
	char			**tab;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (ac == 1)
		return (NULL);
	tab = ft_strstrnew(ac + 1);
	while (av[i] != NULL)
	{
		ft_add_loop_found(tab, i, &j, av);
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char				**ft_loop_parse_check(char **tab, t_flags *flg, \
					int *i, int *len)
{
	if (ft_check_value(tab) == 0)
		tab = ft_swap_folder(tab);
	if (flg->t == 1)
		tab = ft_sort_tab_time(tab);
	if (flg->r == 1)
		tab = ft_reverse_tab(tab);
	if (ft_strcmp(tab[0], "--") == 0)
	{
		*i = *i + 1;
		*len = *len - 1;
	}
	return (tab);
}

void				ft_loop_parse(char **tab, t_flags *flg, int res, int len)
{
	int			i;
	struct stat stt;
	struct stat sto;

	i = 0;
	tab = ft_loop_parse_check(tab, flg, &i, &len);
	while (tab[i] != NULL)
	{
		stat(tab[i], &stt);
		if (tab[i + 1] != NULL)
			stat(tab[i + 1], &sto);
		if ((len > 1 || res > 0) && stt.st_mode & S_IFDIR)
		{
			ft_putstr(tab[i]);
			ft_putendl(":");
		}
		ft_ls(tab[i], flg);
		if (tab[i + 1] != NULL && (stt.st_mode & S_IFDIR \
					|| sto.st_mode & S_IFDIR))
			ft_putchar('\n');
		i++;
	}
}

t_flags				*ft_parse_flags(int ac, char **av, int *size)
{
	t_flags		*flg;

	if (ac > 1 && (ft_check_nb(av[1]) == 1 || ft_check_nb(av[1]) >= 3))
	{
		while (av[*size])
		{
			if (ft_check_nb(av[*size]) == 1 || ft_check_nb(av[*size]) >= 3)
				flg = ft_flags(av[*size]);
			else
				break ;
			*size = *size + 1;
		}
	}
	else
		flg = ft_flags(NULL);
	return (flg);
}

void				ft_parse(int ac, char **av)
{
	int			size;
	char		**tab;
	t_flags		*flg;
	int			len;
	int			res;

	tab = NULL;
	size = 1;
	flg = ft_parse_flags(ac, av, &size);
	if (ac > 1)
		ft_loop_empty(av);
	if (ac > 1)
		res = ft_loop_not_found(av + size);
	if (ac > 1)
		tab = ft_loop_found(ac, av + size);
	if (res > 0 && *tab == NULL)
		return ;
	if (tab == NULL || *tab == NULL || (ft_strcmp(tab[0], "--") == 0 \
				&& tab[1] == NULL))
		return (ft_ls(NULL, flg));
	len = ft_strstrlen(tab);
	if (len == 0)
		return ;
	ft_free_parse(tab, flg, res, len);
}
