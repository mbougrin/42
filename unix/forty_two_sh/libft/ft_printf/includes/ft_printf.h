/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 14:15:18 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/19 19:28:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct			s_struct
{
	va_list			ap;
	char			*str;
	char			*tmp;
	char			*base;
	unsigned int	end;
	long int		lddiv;
	int				result;
	int				div;
	int				i;
	int				k;
	long int		j;
}						t_struct;

int					ftf_format(const char *format, int i, va_list ap);
int					ftf_format_zero(const char *format, int i, va_list ap);
int					ftf_format_print(const char *format, int i, va_list ap);
int					ftf_print_space(const char *format, int i, va_list ap);
int					ftf_print_zero(const char *format, int i, va_list ap);
int					ftf_plus(const char *format, int i, va_list ap);
int					ftf_print_b(const char *format, va_list ap, int i);
int					ft_printf(const char *format, ...);
int					ftf_put_p(void *s);
int					ftf_puthexa(unsigned int n);
int					ftf_p_puthexa(unsigned int n);
int					ftf_x_puthexa(unsigned int n);
int					ftf_ldputnbr(long int n);
int					ftf_uputnbr(unsigned int n);
int					ftf_putnbr(int n);
int					ftf_putstr(char *s);
int					ftf_putchar(char c);
int					ftf_strlen(char *s);
int					ftf_atoi_i(const char *str, int i);
long int			ftf_atoi(const char *str);
int					ftf_put_o(size_t n, int i);
int					ftf_put_h(unsigned int n, int i);
int					ftf_x_put_h(unsigned int n, int i);

#endif
