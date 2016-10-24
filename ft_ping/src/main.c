/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:02:44 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/24 13:23:48 by mbougrin         ###   ########.fr       */
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

static void				showHelp(char *str)
{
	printf("Usage: %s [-hv] destination IP\n", str);
	free(singleton(NULL));
	exit(-1);
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

t_stc					*singleton(t_stc *stc)
{
	static t_stc	*singleton;

	if (stc != NULL)
		singleton = stc;
	return (singleton);
}

int						main(int ac, char **av)
{
	t_stc	*stc;

	stc = (t_stc*)malloc(sizeof(t_stc));
	if (ac == 1)
		showHelp(av[0]);
	stc->ip = arg(av);
	printf("%s\n", stc->ip);
	free(stc);
	return (0);
}
