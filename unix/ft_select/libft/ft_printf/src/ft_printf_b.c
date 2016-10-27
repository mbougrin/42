/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:50:39 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/10 22:56:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int					ftf_format(const char *format, int i, va_list ap)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->i = i;
	if (format[print->i + 1] == 's')
		print->result += ftf_putstr(va_arg(ap, char *));
	else if (format[print->i + 1] == 'd' || format[print->i + 1] == 'i')
		print->result += ftf_putnbr(va_arg(ap, int));
	else if (format[print->i + 1] == 'c')
		print->result += ftf_putchar((char)va_arg(ap, int));
	else if (format[print->i + 1] == 'u')
		print->result += ftf_uputnbr(va_arg(ap, unsigned int));
	else if (format[print->i + 1] == 'x')
		print->result += ftf_put_h(va_arg(ap, unsigned int), 0);
	else if (format[print->i + 1] == 'X')
		print->result += ftf_x_put_h(va_arg(ap, unsigned int), 0);
	else if (format[print->i + 1] == 'l' && format[print->i + 2] == 'd')
		print->result += ftf_ldputnbr(va_arg(ap, long int));
	else if (format[print->i + 1] == 'p')
		print->result += ftf_put_p(va_arg(ap, void *));
	else if (format[print->i + 1] == 'o')
		print->result += ftf_put_o(va_arg(ap, size_t), 0);
	else if (format[print->i + 1] == 'h')
		ftf_format(format, (i + 1), ap);
	return (print->result);
}

int					ftf_format_print(const char *format, int i, va_list ap)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->i = i;
	if (format[print->i] == 's')
		print->result += ftf_putstr(va_arg(ap, char *));
	else if (format[print->i] == 'd' || format[print->i + 1] == 'i')
		print->result += ftf_putnbr(va_arg(ap, int));
	else if (format[print->i] == 'c')
		print->result += ftf_putchar((char)va_arg(ap, int));
	else if (format[print->i] == 'u')
		print->result += ftf_uputnbr(va_arg(ap, unsigned int));
	else if (format[print->i] == 'x')
		print->result += ftf_put_h(va_arg(ap, unsigned int), 0);
	else if (format[print->i] == 'X')
		print->result += ftf_x_put_h(va_arg(ap, unsigned int), 0);
	else if (format[print->i] == 'l' && format[print->i + 1] == 'd')
		print->result += ftf_ldputnbr(va_arg(ap, long int));
	else if (format[print->i] == 'p')
		print->result += ftf_put_p(va_arg(ap, void *));
	else if (format[print->i] == 'o')
		print->result += ftf_put_o(va_arg(ap, size_t), 0);
	else if (format[print->i] == 'h')
		ftf_format_print(format, (i + 1), ap);
	return (print->result);
}

int					ftf_format_zero(const char *format, int i, va_list ap)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->i = i + 1;
	if (format[print->i + 1] == 'x')
	{
		print->result = 2;
		ftf_putstr("0x");
		print->result += ftf_put_h(va_arg(ap, unsigned int), 0);
	}
	else if (format[print->i + 1] == 'X')
	{
		print->result = 2;
		ftf_putstr("0X");
		print->result += ftf_x_put_h(va_arg(ap, unsigned int), 0);
	}
	else if (format[print->i + 1] == 'o')
	{
		print->result = 1;
		ftf_putnbr(0);
		print->result += ftf_put_o(va_arg(ap, size_t), 0);
	}
	else
		print->result += ftf_format(format, print->i, ap);
	return (print->result);
}

int					ftf_print_space(const char *format, int i, va_list ap)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	i++;
	print->k = 0;
	print->result = 0;
	print->k = ftf_atoi_i(format, i);
	while (print->k > 0)
	{
		ftf_putchar(' ');
		print->result++;
		print->k--;
	}
	i++;
	while (format[i] > 47 && format[i] < 58)
		i++;
	print->result--;
	print->result += ftf_format_print(format, i, ap);
	return (print->result);
}

int					ftf_print_zero(const char *format, int i, va_list ap)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	i = i + 2;
	print->k = 0;
	print->result = 0;
	print->k = ftf_atoi_i(format, i);
	while (print->k > 0)
	{
		ftf_putchar('0');
		print->result++;
		print->k--;
	}
	print->str[print->result] = '\0';
	i++;
	while (format[i] > 47 && format[i] < 58)
		i++;
	print->result--;
	print->result += ftf_format_print(format, i, ap);
	return (print->result);
}
