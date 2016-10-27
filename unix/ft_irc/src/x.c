/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:17:32 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/23 17:50:22 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bircd.h"

int		x_int(int err, int res, char *str, char *file)
{
	if (res == err)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" error (", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(")\n", 2);
		exit (1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str, char *file)
{
	if (res == err)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" error (", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(")\n", 2);
		exit (1);
	}
	return (res);
}
