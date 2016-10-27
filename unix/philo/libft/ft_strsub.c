/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:32:05 by mbar              #+#    #+#             */
/*   Updated: 2014/04/18 09:04:51 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*r;

	i = start;
	r = (char *)malloc(sizeof(*r) * len + 1);
	while (i < start + len)
	{
		r[i - start] = s[i];
		i++;
	}
	r[i - start] = '\0';
	return (r);
}
