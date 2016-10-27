/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:54:58 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/11 09:54:21 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	const char	*src;
	char		*dst;

	src = (const char *)s2;
	dst = (char *)s1;
	src += n - 1;
	dst += n - 1;
	if (s1 <= s2)
		ft_memcpy(s1, s2, n);
	else
	{
		while (n > 0)
		{
			*dst = *src;
			src--;
			dst--;
			n--;
		}
	}
	return (s1);
}
