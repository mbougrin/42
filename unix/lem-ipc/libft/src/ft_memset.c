/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:26:51 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/03 17:03:27 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char		charact;
	char				*ptr;

	ptr = (char *)b;
	charact = (unsigned char)c;
	while (len > 0)
	{
		*ptr = charact;
		ptr++;
		len--;
	}
	return (b);
}
