/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:28:28 by mbar              #+#    #+#             */
/*   Updated: 2014/04/18 09:04:39 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabsize(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] == c)
		i++;
	if (s[i] != '\0')
	{
		n++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
}

void	ft_var_init(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

char	**ft_strsplit(char const *s, char c)
{
	int		i[2];
	int		n[2];
	char	**t;

	t = (char **)malloc(sizeof(*t) * (ft_tabsize(s, c) + 1));
	if (!t)
		return (0);
	ft_var_init(&i[0], &i[1], &n[0], &n[1]);
	while (i[1] < ft_tabsize(s, c))
	{
		if ((s[i[0]] == c || s[i[0]] == '\0') && i[0] != 0 && s[i[0] - 1] != c)
		{
			t[i[1]] = ft_strsub(s, n[0], n[1]);
			n[0] = 0;
			n[1] = 0;
			i[1]++;
		}
		if (n[0] == 0 && s[i[0]] != c && s[i[0] - 1] == c)
			n[0] = i[0];
		if (s[i[0]] != c)
			n[1]++;
		i[0]++;
	}
	t[i[1]] = 0;
	return (t);
}
