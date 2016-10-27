/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:25:04 by mblet             #+#    #+#             */
/*   Updated: 2014/02/22 15:10:54 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ptr;
	size_t	j;

	i = 0;
	ptr = 0;
	j = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s2[j] == s1[i])
		{
			if (j == 0)
				ptr = i;
			j++;
		}
		else
			j = 0;
		i++;
		if (s2[j] == '\0')
			return ((char *)(s1 + ptr));
	}
	return (NULL);
}
