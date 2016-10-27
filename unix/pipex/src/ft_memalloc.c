/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:12:37 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/31 10:28:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void			*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (void *)malloc(sizeof(void) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > i)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
