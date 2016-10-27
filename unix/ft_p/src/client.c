/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 14:21:19 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/17 12:15:32 by mbougrin         ###   ########.fr       */
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

	ft_putendl("SUCCESS");
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	write(1, buff, ft_strlen(buff));
}

void			ft_write(int sock)
{
	int			ret;
	char		buff[4096];

	ft_putstr("client $> ");
	while ((ret = read(0, buff, 4096)) > 0)
	{
		buff[ret - 1] = '\0';
		write(sock, buff, ft_strlen(buff));
		if (ft_strcmp(buff, "quit") == 0)
			return (ft_putendl("SUCCESS"));
		else if (ft_strcmp(buff, "ls") == 0)
			ft_read(sock);
		else if (ft_strcmp(buff, "pwd") == 0)
			ft_read(sock);
		else if (ft_strncmp(buff, "cd", ft_strlen("cd")) == 0)
			ft_putendl("SUCCESS");
		else
			ft_putendl("ERROR");
		ft_putstr("client $> ");
	}
}

int				main(int ac, char **av)
{
	int			port;
	int			sock;

	if (ac != 3)
		return (ft_arg(av[0]));
	port = ft_atoi(av[2]);
	sock = ft_create_client(av[1], port);
	if (sock == -1)
		return (0);
	ft_write(sock);
	close(sock);
	return (0);
}
