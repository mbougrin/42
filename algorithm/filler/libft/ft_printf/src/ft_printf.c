/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:42:31 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/03 18:32:44 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int					ftf_plus(const char *format, int i, va_list ap)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->result = 0;
	print->i = i;
	if (format[print->i + 1] == '+' || format[print->i + 1] == ' ')
		print->result += ftf_print_space(format, print->i, ap);
	else if (format[print->i + 1] == '0' && format[print->i + 2] == '+')
		print->result += ftf_print_zero(format, print->i, ap);
	else if (format[print->i + 1] == '0' && format[print->i + 2] == ' ')
		print->result += ftf_print_zero(format, print->i, ap);
	else if (format[print->i + 1] == '#')
		print->result += ftf_format_zero(format, print->i, ap);
	else if (format[print->i + 1] == '0')
		print->result += ftf_format(format, print->i + 1, ap);
	else
		print->result += ftf_format(format, print->i, ap);
	return (print->result);
}

int					ftf_print_b(const char *format, va_list ap, int i)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->result = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			print->result += ftf_plus(format, i, ap);
			if (format[i + 1] == '0')
				i++;
			if (format[i + 1] == '#' || format[i + 2] == 'd' \
					|| format[i + 1] == '+' || format[i + 1] == ' ')
				i++;
			while (format[i + 1] > 47 || 58 < format[i + 1])
				i++;
			i++;
		}
		else
		{
			print->result += ftf_putchar(format[i]);
			i++;
		}
	}
	return (print->result);
}

int					ft_printf(const char *format, ...)
{
	t_struct	*print;

	print = (t_struct *)malloc(sizeof(t_struct));
	print->result = 0;
	print->i = 0;
	va_start(print->ap, format);
	print->result += ftf_print_b(format, print->ap, print->i);
	va_end(print->ap);
	return (print->result);
}
