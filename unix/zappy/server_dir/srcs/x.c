/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:30:57 by mbar              #+#    #+#             */
/*   Updated: 2014/06/04 16:50:17 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serv.h"

int		x_int(int err, int res, char *str, char *file)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s): %s\n",
				str, file, strerror(errno));
		exit (1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str, char *file)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s): %s\n",
				str, file, strerror(errno));
		exit (1);
	}
	return (res);
}
