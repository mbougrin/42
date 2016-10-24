/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:44 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/24 15:01:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
/*
static unsigned short	checksum(void *b, int len)
{
	unsigned short 	*buf = b;
	unsigned int 	sum = 0;
	unsigned short 	result = 0;

	for (sum = 0; len > 1; len -= 2)
		sum += *buf++;
	if (len == 1)
		sum += *(unsigned char*)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	return (result);
}
*/
static t_stc			*singleton(t_stc *stc)
{
	static t_stc	*singleton;

	if (stc != NULL)
		singleton = stc;
	return (singleton);
}

static void				showHelp(char *str)
{
	printf("Usage: %s [-hv] destination IP\n", str);
	free(singleton(NULL));
	exit(-1);
}

static void				addrError(void)
{
	t_stc		*stc = singleton(NULL);
	printf("%s: unknown host %s\n", stc->av[0], stc->ip);
	free(stc);
	exit(-1);
}

static void				connectError(void)
{
	printf("connect error\n");
	free(singleton(NULL));
	exit(-1);
}

void					ipConnect(void)
{
	t_stc		*stc = singleton(NULL);
//	t_addrinfo	hints;
	t_addrinfo	*tmp;
	t_addrinfo	*result;
	int			fd;

//	memset(&hints, 0, sizeof(t_addrinfo));
//	hints.ai_family = AF_UNSPEC; // ipv4 and ipv6 all socket
//	hints.ai_socktype = SOCK_DGRAM; // datagram socket
//	hints.ai_flags = 0;
//	hints.ai_protocol = 0;
	if ((getaddrinfo(stc->ip, NULL, &stc->hints, &result)) != 0)
		addrError();
	tmp = result;
	while (tmp != NULL)
	{
		fd = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);
		if (fd == -1)
			continue ;
		if (connect(fd, tmp->ai_addr, tmp->ai_addrlen) != -1)
		{
			close(fd);
			break ; // success
		}
		close(fd);
		tmp = tmp->ai_next;
	}
	if (tmp == NULL)
		connectError();
	stc->addr = tmp;
}

static void				initAddr(void)
{
	t_stc		*stc = singleton(NULL);

	stc->hints.ai_family = AF_UNSPEC;
	stc->hints.ai_socktype = SOCK_DGRAM;
	stc->hints.ai_flags = 0;
	stc->hints.ai_protocol = 0;
}

char					*arg(char **av)
{
	int			i;
   
	i = 1;
	while (av[i])
	{
		if (ft_strcmp(av[i], "-h") == 0)
			showHelp(av[0]);
		else if (ft_strcmp(av[i], "-v") != 0)
			return (av[i]);
		i++;
	}
	free(singleton(NULL));
	exit(-1);
}


int						main(int ac, char **av)
{
	t_stc	*stc;

	stc = (t_stc*)malloc(sizeof(t_stc));
	if (ac == 1)
		showHelp(av[0]);
	stc->av = av;
	stc->ip = arg(av);
	singleton(stc);
	printf("%s\n", stc->ip);
	initAddr();
	ipConnect();
	free(stc);
	return (0);
}
