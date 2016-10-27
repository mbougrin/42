/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 21:31:40 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/10 22:56:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

long int				ftf_atoi(const char *str)
{
	long int		result;
	long int		div;

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

int						ftf_atoi_i(const char *str, int i)
{
	int		result;
	int		div;

	result = 0;
	div = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' \
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str == NULL)
		return (0);
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
