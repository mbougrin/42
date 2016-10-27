/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:25:44 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/15 04:23:17 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int        ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int    i;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}
