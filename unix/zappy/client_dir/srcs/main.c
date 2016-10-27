/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:54:58 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 06:43:20 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

char			**g_argv;
int				g_argc;

static int		hostname_to_ip(char *hostname, char *ip)
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

int				ft_create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
	char				ip[100];

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	if ((hostname_to_ip(addr, ip) == -1))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(ip);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("connect error", 2);
		return (-1);
	}
	return (sock);
}

void			ft_sig_handler(int sig)
{
	pid_t	pid;

	sig = sig;
	if ((pid = fork()) < 0)
	{
		ft_putendl("error fork");
		exit(0);
	}
	if (pid == 0)
	{
		create_player(g_argc, g_argv);
	}
	else
	{
		;
	}
}

void			create_player(int ac, char **av)
{
	t_stc	*stc;

	stc = (t_stc *)malloc(sizeof(t_stc));
	if (ac < 7 || ac > 7)
	{
		ft_putendl_fd("Usage: ./client -n <team> -p <port> -h <hostname>", 2);
		return ;
	}
	if (ft_strcmp(av[3], "-p") == 0)
		stc->port = ft_atoi(av[4]);
	if (ft_strcmp(av[1], "-n") == 0)
		stc->team = ft_strdup(av[2]);
	if (ft_strcmp(av[5], "-h") == 0)
	{
		stc->addr = ft_strdup(av[6]);
		stc->sock = ft_create_client(av[6], stc->port);
		if (stc->sock == -1)
			return ;
	}
	ft_client(stc);
	close(stc->sock);
}

int				main(int ac, char **av)
{
	g_argc = ac;
	g_argv = av;
	signal(SIGUSR1, ft_sig_handler);
	ft_sig_handler(0);
	while (1)
		;
	return (0);
}
