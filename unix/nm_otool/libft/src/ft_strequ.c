/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:06:49 by mbougrin          #+#    #+#             */
/*   Updated: 2013/11/29 20:22:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	while (*s1 == *s2 && 0 < n)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (1);
	else if (*s1 != *s2)
		return (0);
	return (1);
}
