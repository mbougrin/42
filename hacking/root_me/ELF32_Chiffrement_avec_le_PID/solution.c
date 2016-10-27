/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:19:11 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/06 15:06:17 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <crypt.h>
#include <unistd.h>

int main (int ac, char **av)
{
	char pid[16];
	if (ac == 1 || ac > 2)
	{
		printf("./a.out binary4\n");
		return (0);
	}
	snprintf(pid, sizeof(pid), "%i", getpid());
	av[2] = crypt(pid, "$1$awesome");
	av[3] = NULL;
	execve("/challenge/binary/binary4/binary4", &av[1], NULL);
	return (0);
}
