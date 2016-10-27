/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:57:57 by mbar              #+#    #+#             */
/*   Updated: 2014/04/18 09:02:54 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*r1;
	const char		*r2;
	char			*temp;

	i = 0;
	r1 = s1;
	r2 = s2;
	temp = (char *)malloc(sizeof(*temp) * n);
	while (i < n)
	{
		temp[i] = r2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		r1[i] = temp[i];
		i++;
	}
	free(temp);
	return (s1);
}
