/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 18:45:07 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/11 09:58:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (*s != '\0')
	{
		result[i] = f(*s);
		s++;
		i++;
	}
	return (result);
}
