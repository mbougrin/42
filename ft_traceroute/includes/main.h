/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:55 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/27 12:14:06 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>
# include <stdio.h>

# include <time.h>

# include <sys/socket.h>
# include <sys/wait.h>
# include <sys/time.h>

# include <resolv.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>

# include <arpa/inet.h>

# define PACKET_SIZE 64
# define NUMBER_PACKET 20
# define WAIT 1
# define SLEEP 1
# define BUFFSIZE IP_MAXPACKET
# define DEFMAXTTL 64

void						initaddr(void);
unsigned short				checksum(void *b, int len);
void						ipconnect(void);
void						showhelp(char *str);
void						socketconfig(void);

void						socketerror(void);
void						setsockopterror(void);
void						addrerror(void);
void						connecterror(void);
void						sendtoerror(void);

typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr		t_sockaddr;
typedef struct icmphdr		t_icmphdr;
typedef struct addrinfo		t_addrinfo;
typedef struct iphdr		t_iphdr;
typedef struct icmp			t_icmp;
typedef struct ip			t_ip;

void						firstprint(t_addrinfo *tmp);

void						print(void);
void						firstprint(t_addrinfo *tmp);
void						printsigint(void);

typedef struct				s_packet
{
	t_icmphdr				hdr;
	char					msg[PACKET_SIZE - sizeof(t_icmphdr)];
}							t_packet;

typedef struct				s_stc
{
	int						success;
	int						count;
	int						ttl;
	int						pid;
	int						sd;
	int						packetreceiv;
	int						fd;
	int						len;
	double					allms;
	double					ms;
	char					*name;
	char					*ip;
	char					blop[1024];
	t_addrinfo				hints;
	t_addrinfo				*addr;
}							t_stc;

t_stc						*singleton(t_stc *stc);
char						*arg(char **av);
void						sig_handler(int sig);

t_packet					sendpacket(t_addrinfo *addr_info);
void						recvpacket(struct timeval tend, \
							struct timeval tstart, t_packet packet);
void						timeout(void);

#endif
