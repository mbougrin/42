/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:55:54 by mbar              #+#    #+#             */
/*   Updated: 2014/04/18 09:05:04 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*r;

	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= 0)
		j--;
	if (j - i < 0)
		return (0);
	r = (char *)malloc(sizeof(*r) * (j - i + 2));
	if (!r)
		return (0);
	while (i <= j)
	{
		r[k] = s[i];
		k++;
		i++;
	}
	r[k] = '\0';
	return (r);
}
