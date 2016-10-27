/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:12:47 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/07 20:33:16 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <libft.h>

int		main(void)
{
	pid_t	pid;

	ft_putstr("Server started.\nPID = ");
	pid = getpid();
	ft_putnbr((int) pid);
	ft_putendl(".");
	get_client_pid(1);
	get_signal();
	return (0);
}
