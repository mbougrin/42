/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:55 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/24 11:13:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>
# include <stdio.h>

# include <errno.h>
# include <time.h>

# include <sys/socket.h>
# include <sys/wait.h>

# include <fcntl.h>
# include <resolv.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>

# define PACKET_SIZE 64
# define NUMBER_PACKET 20
# define WAIT 2

typedef struct			s_packet
{
	icmphdr				hdr;
	char				msg[PACKET_SIZE - sizeof(icmphdr)];
}						t_packet;

#endif
