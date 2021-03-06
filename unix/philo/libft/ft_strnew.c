/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:05:26 by mbar              #+#    #+#             */
/*   Updated: 2014/04/18 09:04:23 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*s;

	i = 0;
	s = (char *)malloc(sizeof(*s) * size + 1);
	while (i <= size)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
