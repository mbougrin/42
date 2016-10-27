/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:48:08 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/03 18:28:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int					ftf_put_o(size_t n, int i)
{
	if (n < 8)
		i += ftf_putchar('0' + n);
	else
	{
		i += ftf_put_o(n / 8, i);
		return (ftf_put_o(n % 8, i));
	}
	return (i);
}

int					ftf_put_h(unsigned int n, int i)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->base = "0123456789abcdef";
	if (n < 16)
		i += ftf_putchar(print->base[n]);
	else
	{
		i += ftf_put_h(n / 16, i);
		return (ftf_put_h(n % 16, i));
	}
	return (i);
}

int					ftf_x_put_h(unsigned int n, int i)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->base = "0123456789ABCDEF";
	if (n < 16)
		i += ftf_putchar(print->base[n]);
	else
	{
		i += ftf_x_put_h(n / 16, i);
		return (ftf_x_put_h(n % 16, i));
	}
	return (i);
}
