/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:46:01 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 10:48:26 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	long	*ptr1;
	long	*ptr2;
	char	*cptr1;
	char	*cptr2;

	ptr1 = (long *)s1;
	ptr2 = (long *)s2;
	while (n >= sizeof(long))
	{
		*ptr1++ = *ptr2++;
		n -= sizeof(long);
	}
	cptr1 = (char *)ptr1;
	cptr2 = (char *)ptr2;
	while (n > 0)
	{
		*cptr1++ = *cptr2++;
		--n;
	}
	return (s1);
}
