/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 14:28:04 by mblet             #+#    #+#             */
/*   Updated: 2014/03/25 18:35:39 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	len;

	if (s == NULL)
		return (NULL);
	tmp = (char *)s;
	while (ft_isspace(*tmp))
		tmp++;
	len = ft_strlen(tmp);
	if (len)
	{
		while (ft_isspace(tmp[--len]) || *tmp == '\0')
			;
		tmp = ft_strsub(tmp, 0, (len + 1));
	}
	else
	{
		tmp = ft_strnew(1);
	}
	return (tmp);
}
