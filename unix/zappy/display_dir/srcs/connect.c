/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 18:48:18 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 18:37:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "display.h"
#include "start_cmd.h"
#include "creat_mlx.h"
#include "thread_launch.h"

static int	ft_hostname_to_ip(char *hostname, char *ip)
{
	struct hostent	*he;
	struct in_addr	**addr_list;
	int				i;

	if ((he = gethostbyname(hostname)) == NULL)
		return (-1);
	addr_list = (struct in_addr **)he->h_addr_list;
	i = 0;
	while (addr_list[i] != NULL)
	{
		ft_strcpy(ip, inet_ntoa(*addr_list[i]));
		i++;
		return (0);
	}
	return (-1);
}

static int	ft_creat_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
	char				ip[100];

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	if ((ft_hostname_to_ip(addr, ip) == -1))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(ip);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (-1);
	return (sock);
}

void		ft_connect(t_display *d)
{
	if ((d->connect->sock = ft_creat_client(d->connect->hostname,
					ft_atoi(d->connect->port))) == -1)
		return (ft_error("find server"));
	if (ft_start_cmd(d) == -1)
		return (ft_error("bad server"));
	ft_thread_launch(d);
	ft_creat_mlx(d);
}
