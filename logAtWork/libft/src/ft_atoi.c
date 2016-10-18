/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:24:03 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/04 19:42:00 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_atoi(const char *str)
{
	int		result;
	int		div;
	int		i;

	i = 0;
	result = 0;
	div = 1;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
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
