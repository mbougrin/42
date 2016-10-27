/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 10:43:20 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/23 11:04:54 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void				ft_loop_empty(char **av)
{
	int		i;

	i = 0;
	while (av[i] != NULL)
	{
		if (av[i][0] == '\0')
			ft_empty();
		i++;
	}
}

int					ft_print_tab(char **tab)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (tab[i] != NULL)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(tab[i], 2);
		ft_putendl_fd(": No such file or directory", 2);
		result = result + 1;
		i++;
	}
	return (result);
}

int					ft_print_not_found(char **tab)
{
	int		i;
	char	*tmp;
	int		j;

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
	return (ft_print_tab(tab));
}

int					ft_loop_not_found(char **av)
{
	char			*tab[256];
	struct stat		stt;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (av[i] != NULL)
	{
		if (lstat(av[i], &stt) == -1 && stat(av[i], &stt) == -1 \
				&& ft_strcmp(av[i], "--") != 0)
		{
			tab[j] = av[i];
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (ft_print_not_found(tab));
}

void				ft_add_loop_found(char **tab, int i, int *j, char **av)
{
	struct stat		stt;

	if (ft_strcmp(av[i], "--") == 0 && stat(av[i + 1], NULL) != -1 \
				&& lstat(av[i + 1], NULL) == -1)
	{
		tab[*j] = ft_strdup(av[i]);
		*j = *j + 1;
	}
	else if (ft_strcmp(av[i], "--") == 0 && stat(av[i + 1], NULL) != -1 \
			&& lstat(av[i + 1], NULL) == -1)
	{
		i++;
		tab[*j] = ft_strdup(av[i]);
		*j = *j + 1;
	}
	else if (stat(av[i], &stt) != -1 || lstat(av[i], &stt) != -1)
	{
		tab[*j] = ft_strdup(av[i]);
		*j = *j + 1;
	}
}
