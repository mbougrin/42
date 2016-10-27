/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 14:21:33 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/08 14:24:04 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int					ft_check_nb(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (str[0] == '-' && str[1] == '\0')
		return (-1);
	if (str[0] == '-' && str[1] == '-' && str[2] == '\0')
		return (-1);
	if (str[0] == '-' && str[1] == '-' && str[2] != '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[0] != '-')
			break ;
		if (str[i] == '-')
			result += 1;
		i++;
	}
	return (result);
}

int					ft_check_value(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}

char				**ft_reverse_tab(char **tab)
{
	int		len;
	int		i;
	char	**tmp;

	i = 0;
	len = ft_strstrlen(tab);
	tmp = ft_strstrnew(len);
	tmp[len] = NULL;
	len--;
	while (1)
	{
		tmp[i] = ft_strdup(tab[len]);
		i++;
		if (len == 0)
			break ;
		len--;
	}
	return (tmp);
}

void				ft_sort_tab_time_next(int j, int i, char **tab, \
					struct stat stt)
{
	char			*ptr;
	struct stat		sto;

	while (tab[j])
	{
		stat(tab[j], &sto);
		if (stt.st_mtime < sto.st_mtime && !S_ISDIR(sto.st_mode))
		{
			stat(tab[j], &stt);
			ptr = tab[i];
			tab[i] = tab[j];
			tab[j] = ptr;
		}
		j++;
	}
}

char				**ft_sort_tab_time(char **tab)
{
	struct stat		stt;
	int				i;
	int				j;

	i = 0;
	while (tab[i])
	{
		stat(tab[i], &stt);
		if (tab[i + 1] == NULL)
			break ;
		j = i + 1;
		ft_sort_tab_time_next(j, i, tab, stt);
		i++;
	}
	return (tab);
}
