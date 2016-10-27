/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:25:47 by mblet             #+#    #+#             */
/*   Updated: 2014/06/16 17:38:12 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_getlen_arg(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		**ft_modtab(char **arg, char *s)
{
	int		i;
	char	**tmp;

	if ((tmp = (char **)malloc((ft_strlistlen(arg) + 2) * sizeof(char *))))
	{
		i = 0;
		while (arg && arg[i])
		{
			tmp[i] = arg[i];
			i++;
		}
		tmp[i] = s;
		tmp[i + 1] = NULL;
		if (arg)
			free(arg);
	}
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	*tmp;
	char	**arg;

	if (!s || !*s)
		return (NULL);
	arg = NULL;
	j = 0;
	while (s && s[j])
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		i = ft_getlen_arg(s + j, c);
		if (i)
		{
			tmp = ft_strsub(s, j, i);
			arg = ft_modtab(arg, tmp);
		}
		j += i;
	}
	return (arg);
}
