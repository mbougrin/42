/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:49:22 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/03 18:28:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int					ftf_strlen(char *s)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->i = 0;
	while (s[print->i] != '\0')
		print->i++;
	return (print->i);
}

int					ftf_putstr(char *s)
{
	if (s)
	{
		write(1, s, ftf_strlen(s));
		return (ftf_strlen(s));
	}
	else
		write(1, "(null)", 6);
	return (6);
}

int					ftf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int					ftf_putnbr(int n)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->i = 0;
	print->div = 1;
	if (n == -2147483648)
	{
		ftf_putstr("-2147483648");
		return (ftf_strlen("-2147483648"));
	}
	if (n < 0)
	{
		n *= -1;
		ftf_putchar('-');
		print->i++;
	}
	while ((n / print->div) >= 10)
		print->div *= 10;
	while (print->div > 0)
	{
		ftf_putchar((n / print->div) % 10 + 48);
		print->div /= 10;
		print->i++;
	}
	return (print->i);
}

int					ftf_uputnbr(unsigned int n)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->i = 0;
	print->div = 1;
	while ((n / print->div) >= 10)
		print->div *= 10;
	while (print->div > 0)
	{
		ftf_putchar((n / print->div) % 10 + 48);
		print->div /= 10;
		print->i++;
	}
	return (print->i);
}
