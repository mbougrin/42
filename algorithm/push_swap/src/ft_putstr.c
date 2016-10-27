/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:22:55 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/25 16:59:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <push_swap.h>

void				ft_putstr(char const *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
}
