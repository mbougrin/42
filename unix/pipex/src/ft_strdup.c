/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:20:49 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/30 21:48:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char		*ft_strdup(const char *s1)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1) + 1;
	dest = (char*)malloc(sizeof(char) * (len));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}
