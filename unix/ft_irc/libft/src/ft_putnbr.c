/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:42:00 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/23 16:34:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_putnbr(int n)
{
	int		div;

	div = 1;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar('-');
		}
		while ((n / div) >= 10)
			div *= 10;
		while (div > 0)
		{
			ft_putchar((n / div) % 10 + 48);
			div /= 10;
		}
	}
}
