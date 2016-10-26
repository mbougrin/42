/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 13:42:06 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/26 14:19:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void					socketerror(void)
{
	printf("socket error\n");
	free(singleton(NULL));
	exit(-1);
}

void					setsockopterror(void)
{
	printf("setsockopt error\n");
	free(singleton(NULL));
	exit(-1);
}

void					addrerror(void)
{
	t_stc		*stc;

	stc = singleton(NULL);
	printf("%s: unknown host %s\n", stc->name, stc->ip);
	free(stc);
	exit(-1);
}

void					connecterror(void)
{
	printf("connect error\n");
	free(singleton(NULL));
	exit(-1);
}

void					sendtoerror(void)
{
	t_stc		*stc;

	stc = singleton(NULL);
	printf("sendto error\n");
	free(stc);
	exit(-1);
}
