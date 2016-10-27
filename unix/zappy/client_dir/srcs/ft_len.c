/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 17:00:30 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/11 17:04:35 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

int				ft_strlen_space(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

int				ft_strlen_backslash(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}
