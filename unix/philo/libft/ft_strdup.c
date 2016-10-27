/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:37:49 by mbar              #+#    #+#             */
/*   Updated: 2014/04/18 09:03:10 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*str;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	i = 0;
	while (i <= ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
