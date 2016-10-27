/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 18:11:15 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/04 16:22:27 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_next(const char *str, char charset, int i)
{
	int		first;
	int		result;

	result = 0;
	first = i;
	while (str[i] != '\0')
	{
		if (str[i] == charset || str[i] == '\t' || str[i] == ' ')
			break ;
		i++;
	}
	result = i - first;
	return (result);
}

static int		ft_charset(const char *str, char charset)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	while (str[i] != '\0')
	{
		if (str[i] == charset || str[i] == '\t' || str[i] == ' ')
		{
			result++;
			while (str[i] == charset || str[i] == '\t' || str[i] == ' ')
				i++;
		}
		i++;
	}
	return (result);
}

char			**ft_strsplit_minishell(char const *s, char c)
{
	char	**split;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i] == c || s[i] == '\t' || s[i] == ' ')
		i++;
	if (s[i] == '\0')
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_charset(s, c) + 1));
	while (s[i] != '\0')
	{
		while (s[i] == c || s[i] == '\t' || s[i] == ' ')
			i++;
		if (s[i] == '\0')
			break ;
		split[n] = ft_strsub(s, i, ft_next(s, c, i));
		i += ft_next(s, c, i);
		n++;
	}
	split[n] = NULL;
	return (split);
}
