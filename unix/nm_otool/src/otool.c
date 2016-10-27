/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 20:25:26 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/26 20:30:21 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_otool.h"

char			ft_base(int n)
{
	if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	return ('0' + n);
}

void			ft_print_hexa(int c)
{
	char		r;

	if (c < 0)
		c += 256;
	r = ft_base(c / 16);
	write(1, &r, 1);
	r = ft_base(c % 16);
	write(1, &r, 1);
}

void			ft_print_addr(int n, char *base)
{
	char			*addr;
	int				i;

	addr = ft_strdup("00000000\0");
	i = 7;
	while (1)
	{
		if (n < 16)
			break ;
		addr[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	addr[i] = base[n];
	ft_putstr(addr);
	ft_strdel(&addr);
}
