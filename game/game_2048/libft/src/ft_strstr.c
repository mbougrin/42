/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:57:51 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/11 09:53:25 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>

char			*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0)
	{
		if (*s1 == '\0')
			return (NULL);
		s1++;
	}
	return ((char*)s1);
}
