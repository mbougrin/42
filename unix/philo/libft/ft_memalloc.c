/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:33:45 by mbar              #+#    #+#             */
/*   Updated: 2014/04/18 09:02:42 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int		i;
	char				*r;

	i = 0;
	r = (char *)malloc(sizeof(*r) * size);
	while (i < size)
	{
		r[i] = '\0';
		i++;
	}
	return ((void *)(r));
}
