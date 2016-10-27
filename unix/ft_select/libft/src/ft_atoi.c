/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:24:03 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/03 16:26:22 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_atoi(const char *str)
{
	int		result;
	int		div;

	result = 0;
	div = 1;
	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\r' \
			|| *str == '\v' || *str == '\n')
		str++;
	if (str == NULL)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			div = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		result *= 10;
		result += *str - 48;
		str++;
	}
	return (result / div);
}
