/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:58:35 by mbar              #+#    #+#             */
/*   Updated: 2013/11/20 18:32:33 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
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
		i++;
	}
	return (s1);
}
