/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:55 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/25 12:39:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>
# include <stdio.h>

# include <time.h>

# include <sys/socket.h>
# include <sys/wait.h>

# include <resolv.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>

# define PACKET_SIZE 64
# define NUMBER_PACKET 20
# define WAIT 1

typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr		t_sockaddr;
typedef struct icmphdr		t_icmphdr;
typedef struct addrinfo		t_addrinfo;

typedef struct				s_packet
{
	t_icmphdr				hdr;
	char					msg[PACKET_SIZE - sizeof(t_icmphdr)];
}							t_packet;

typedef struct				s_stc
{
	int						success;
	int						count;
	double					ms;
	char					*name;
	char					*ip;
	t_addrinfo				hints;
	t_addrinfo				*addr;
}							t_stc;

#endif
