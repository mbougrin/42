/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:21:57 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/05 00:26:28 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*p1;
	unsigned char		*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
