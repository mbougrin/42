/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:13:28 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/10 23:06:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int			ft_alloc(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	while (n < 0)
	{
		n *= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (ft_alloc(n) + 1));
	*p = 0;
	if (n == 0)
		return ("0");
	if (n >= 0)
	{
		while (n != 0)
		{
			*--p = '0' + (n % 10);
			n /= 10;
		}
		return (p);
	}
	else
	{
		while (n != 0)
		{
			*--p = '0' - (n % 10);
			n /= 10;
		}
		*--p = '-';
	}
	return (p);
}
