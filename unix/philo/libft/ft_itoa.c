/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:12:57 by mbar              #+#    #+#             */
/*   Updated: 2014/04/18 09:02:07 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intsize(int n)
{
	int	i;

	i = 1;
	while (n > 9 || n < (-9))
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_strrev(char *s)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < (ft_strlen(s) / 2))
	{
		c = s[i];
		s[i] = s[ft_strlen(s) - 1 - i];
		s[ft_strlen(s) - 1 - i] = c;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s;

	i = 0;
	sign = 1;
	s = (char *)malloc(sizeof(*s) * (ft_intsize(n) + 1));
	if (!s)
		return (0);
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	while (n > 9)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	if (sign < 0)
		s[i + 1] = '-';
	s[i + 2] = '\0';
	return (ft_strrev(s));
}
