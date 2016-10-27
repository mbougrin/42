/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:27:16 by mblet             #+#    #+#             */
/*   Updated: 2014/02/22 14:27:55 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	size_t	j;

	if (s == NULL || len <= 0)
		return (NULL);
	i = start;
	j = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		while (s[i] && j < len)
		{
			str[j] = s[i];
			i++;
			j++;
		}
		str[j] = '\0';
	}
	return (str);
}
