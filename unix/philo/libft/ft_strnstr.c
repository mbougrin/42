/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:57:36 by mbar              #+#    #+#             */
/*   Updated: 2013/11/27 18:00:59 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[j] == '\0')
		return ((char*)s1);
	while (i < n && s1[i])
	{
		j = 0;
		k = 0;
		while (s1[i + k] == s2[j] && s2[j] != '\0' && i + (size_t)k < n)
		{
			k++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)s1 + i);
		i++;
	}
	return (0);
}
