/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:14:52 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/03 18:11:27 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

void		get_signal(void);
int			get_client_pid(int mode);

#endif
