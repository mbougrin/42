/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 05:15:12 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/29 05:15:40 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

long int		ft_atol(char *str)
{
	long int		result;
	int				div;
	int				i;

	i = 0;
	result = 0;
	div = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r' \
			|| str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			div = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result / div);
}
