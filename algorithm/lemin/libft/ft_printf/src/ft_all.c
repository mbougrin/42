/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:40:10 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/03 18:28:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int					ftf_put_p(void *s)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->result = 0;
	print->result += ftf_putstr("0x10");
	print->result += ftf_put_h((size_t)s, 0);
	return (print->result);
}

int					ftf_ldputnbr(long int n)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->i = 0;
	print->lddiv = 1;
	if (n == -9223372036854775807)
	{
		ftf_putstr("-9223372036854775807");
		return (ftf_strlen("-9223372036854775807"));
	}
	if (n < 0)
	{
		n *= -1;
		ftf_putchar('-');
		print->i++;
	}
	while ((n / print->lddiv) >= 10)
		print->lddiv *= 10;
	while (print->lddiv > 0)
	{
		ftf_putchar((n / print->lddiv) % 10 + 48);
		print->lddiv /= 10;
		print->i++;
	}
	return (print->i);
}
