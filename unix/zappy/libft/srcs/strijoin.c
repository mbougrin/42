/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strijoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 22:13:32 by mblet             #+#    #+#             */
/*   Updated: 2014/06/03 22:12:34 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strijoin(char *s, ...)
{
	va_list		args;
	char		*str;
	char		*tmp;
	int			len;

	len = 0;
	len += ft_strlen(s);
	va_start(args, s);
	while ((str = (char *)va_arg(args, char *)))
		len += ft_strlen(str);
	va_end(args);
	str = ft_strnew(len + 1);
	str = ft_strcat(str, s);
	va_start(args, s);
	while ((tmp = (char *)va_arg(args, char *)))
		str = ft_strcat(str, tmp);
	va_end(args);
	return (str);
}
