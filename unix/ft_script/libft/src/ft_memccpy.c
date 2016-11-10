/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:01:55 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/04 21:50:15 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	charact;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	charact = (unsigned char)c;
	while (n > 0)
	{
		*p1 = *p2;
		if (*p2 == charact)
			return ((void *)p1 + 1);
		p1++;
		p2++;
		n--;
	}
	return (NULL);
}
