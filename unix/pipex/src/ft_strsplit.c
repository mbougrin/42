/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvier <abouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:13:00 by abouvier          #+#    #+#             */
/*   Updated: 2013/12/30 22:50:19 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static size_t	ft_strcountw(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			if (!(s = ft_strchr(s, c)))
				break ;
		}
		else
			s++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		words;
	char const	*p;
	size_t		i;

	words = ft_strcountw(s, c);
	if (!(split = (char **)ft_memalloc(sizeof(*split) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		p = ft_strchr(s, c);
		if (!(split[i] = ft_strsub(s, 0, p ? (size_t)(p - s) : ft_strlen(s))))
		{
			ft_strstrdel(&split);
			return (NULL);
		}
		s = p;
		i++;
	}
	return (split);
}
