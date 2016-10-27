/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:26:25 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/14 11:12:25 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;

	i = 0;
	dst = ft_strnew(len + 1);
	if (dst == NULL)
		return (NULL);
	while (len > 0)
	{
		dst[i] = s[start];
		start++;
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}
