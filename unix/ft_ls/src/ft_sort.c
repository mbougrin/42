/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:18:50 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/08 14:20:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char				**ft_sort_tab_ascii(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void				ft_sort_folder_ascii_next(int j, char **tab, \
					struct stat sto, int i)
{
	struct stat	stt;
	char		*tmp;

	while (tab[j])
	{
		stat(tab[j], &stt);
		if (ft_strcmp(tab[i], tab[j]) > 0 && sto.st_mode \
				& S_IFDIR && stt.st_mode & S_IFDIR)
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}
		j++;
	}
}

char				**ft_sort_folder_ascii(char **tab)
{
	int			i;
	int			j;
	struct stat	sto;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		stat(tab[i], &sto);
		ft_sort_folder_ascii_next(j, tab, sto, i);
		i++;
	}
	return (tab);
}

void				ft_swap_folder_next(int j, char **tab, \
					struct stat sto, int i)
{
	struct stat	stt;
	char		*tmp;

	while (tab[j])
	{
		stat(tab[j], &stt);
		if (sto.st_mode & S_IFDIR && !(stt.st_mode & S_IFDIR))
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			break ;
		}
		j++;
	}
}

char				**ft_swap_folder(char **tab)
{
	int			i;
	int			j;
	struct stat	sto;

	i = 0;
	tab = ft_sort_tab_ascii(tab);
	while (tab[i])
	{
		j = i + 1;
		stat(tab[i], &sto);
		ft_swap_folder_next(j, tab, sto, i);
		i++;
	}
	tab = ft_sort_folder_ascii(tab);
	return (tab);
}
