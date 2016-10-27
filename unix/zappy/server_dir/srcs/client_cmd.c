/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:51:48 by mbar              #+#    #+#             */
/*   Updated: 2014/06/26 12:42:25 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serv.h"

static char		*ft_strcpy_cmd(char *dst, char *src)
{
	int		i;
	int		j;
	char	temp[BUF_SIZE + 1];

	i = 0;
	while (src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	i++;
	ft_bzero(temp, BUF_SIZE);
	j = 0;
	while (src[i])
	{
		temp[j] = src[i];
		i++;
		j++;
	}
	ft_bzero(src, BUF_SIZE);
	ft_strcpy(src, temp);
	return (dst);
}

void			client_cmd(t_env *e, int cs)
{
	ft_strcpy_cmd(e->fds[cs].buf_read, e->fds[cs].buf_mem);
}
