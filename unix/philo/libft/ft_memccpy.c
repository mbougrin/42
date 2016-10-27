/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:01:43 by mbar              #+#    #+#             */
/*   Updated: 2013/11/22 16:25:09 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;
	char			*r;
	const char		*r2;

	i = 0;
	r = s1;
	r2 = s2;
	while (i < n)
	{
		r[i] = r2[i];
		if (r2[i] == c)
			return (r + i + 1);
		i++;
	}
	return (0);
}
