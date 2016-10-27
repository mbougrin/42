/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shellsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:49:51 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:05:01 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static int		ft_next(const char *str, char charset, int i)
{
	int		first;
	int		result;

	result = 0;
	first = i;
	while (str[i] != '\0')
	{
		if (str[i] == charset || str[i] == '|' || str[i] == ';' \
				|| str[i] == '&' || str[i] == '<' || str[i] == '>')
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
		if (str[i] == charset)
		{
			result++;
			while (str[i] == charset)
				i++;
		}
		i++;
	}
	return (result);
}

static int		ft_charset_move(const char *s, char c, int i)
{
	int		j;

	j = 0;
	while (s[i + j] == c)
		j++;
	if (s[i + j] == '\0' || s[i + j] == '|' || s[i + j] == ';' \
			|| s[i + j] == '&' || s[i + j] == '<' || s[i + j] == '>')
		return (-1);
	return (j);
}

static char		ft_split_quote(char *s)
{
	char	b;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			break ;
		i++;
	}
	if (s[i] == '\0')
		return (0);
	b = s[i];
	return (b);
}

char			**ft_shellsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		n;

	i = 0;
	n = 0;
	split = (char **)malloc(sizeof(char *) * (ft_charset(s, c) + 1));
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (ft_charset_move(s, c, i) == -1)
			break ;
		if (s[i] == ft_split_quote((char *)s))
			split[n++] = ft_strsub(s, i + 1, ft_next(s, \
						ft_split_quote((char *)s), i + 1));
		else
			split[n++] = ft_strsub(s, i, ft_next(s, c, i));
		if (s[i] == ft_split_quote((char *)s))
			i += ft_next(s, ft_split_quote((char *)s), i + 1) + 1;
		else
			i += ft_next(s, c, i);
	}
	ft_modify_split(split, n);
	return (split);
}
