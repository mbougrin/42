/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 13:42:06 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/26 13:45:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void					socketError(void)
{
	printf("socket error\n");
	free(singleton(NULL));
	exit(-1);
}

void					setSockOptError(void)
{
	printf("setsockopt error\n");
	free(singleton(NULL));
	exit(-1);
}

void					addrError(void)
{
	t_stc		*stc = singleton(NULL);

	printf("%s: unknown host %s\n", stc->name, stc->ip);
	free(stc);
	exit(-1);
}

void					connectError(void)
{
	printf("connect error\n");
	free(singleton(NULL));
	exit(-1);
}

void					showHelp(char *str)
{
	printf("Usage: %s [-hv] destination IP\n", str);
	free(singleton(NULL));
	exit(-1);
}
