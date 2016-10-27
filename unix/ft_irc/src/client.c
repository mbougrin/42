/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 14:21:19 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/24 06:13:56 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header_client.h>

int				ft_arg(char *s)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(" <addr> <port>\n", 2);
	return (-1);
}

int				ft_create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("connect error", 2);
		return (-1);
	}
	return (sock);
}

void			ft_read(int sock)
{
	char		buff[4096];
	int			ret;

	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	ft_putstr(buff);
	ft_strclr(buff);
}

void			ft_write(int sock)
{
	char		buff[4096];
	int			ret;
	fd_set		fd_read;

	while (1)
	{
		FD_ZERO(&fd_read);
		FD_ZERO(&fd_read);
		FD_SET(sock, &fd_read);
		FD_SET(0, &fd_read);
		select(sock + 1, &fd_read, NULL, NULL, NULL);
		if (FD_ISSET(sock, &fd_read))
			ft_read(sock);
		if (FD_ISSET(0, &fd_read))
		{
			ret = read(0, buff, 4096);
			buff[ret - 1] = '\0';
			if (ft_strcmp(buff, "/quit") == 0)
				break ;
			write(sock, buff, ft_strlen(buff));
			ft_strclr(buff);
		}
	}
}

int				main(int ac, char **av)
{
	int			port;
	int			sock;

	if (ac != 3)
		return (ft_arg(av[0]));
	port = ft_atoi(av[2]);
	if (ft_strcmp(av[1], "localhost") == 0)
		sock = ft_create_client("127.0.0.1", port);
	else
		sock = ft_create_client(av[1], port);
	if (sock == -1)
		return (0);
	ft_write(sock);
	close(sock);
	return (0);
}
