/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 14:21:19 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/20 18:21:04 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header_server.h>

static int		ft_arg(char *s)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(" <port>\n", 2);
	return (-1);
}

static int		ft_create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == NULL)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("bind error", 2);
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}

static void		ft_fork(int sock)
{
	int						cs;
	struct sockaddr_in		*csin;
	pid_t					pid;
	unsigned int			cslen;

	while (1)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
		if ((pid = fork()) == 0)
		{
			ft_read(cs);
			close(cs);
			break ;
		}
	}
}

int				main(int ac, char **av)
{
	int						port;
	int						sock;

	if (ac != 2)
		return (ft_arg(av[0]));
	port = ft_atoi(av[1]);
	sock = ft_create_server(port);
	if (sock == -1)
		return (0);
	ft_fork(sock);
	close(sock);
	return (0);
}
