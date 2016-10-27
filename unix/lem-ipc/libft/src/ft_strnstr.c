/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:23:49 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/05 00:26:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0)
	{
		if (n < ft_strlen(s2))
			break ;
		if (*s1 == '\0')
			break ;
		s1++;
		n--;
	}
	if (n < ft_strlen(s2) || ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	else if (*s1 == '\0' && n == 0)
		return (NULL);
	return ((char*)s1);
}
