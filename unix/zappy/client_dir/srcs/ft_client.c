/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 16:49:38 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/27 06:17:54 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

extern	pid_t	g_ppid;

void			ft_client(t_stc *stc)
{
	stc->find = 0;
	stc->level = 1;
	stc->move = 0;
	stc->view = 3;
	stc->start = 0;
	while (1)
	{
		if (stc->start == 0)
			ft_read(stc->sock, stc);
		if (stc->start == 1)
			ft_algo(stc->sock, stc);
	}
}

void			ft_read(int sock, t_stc *stc)
{
	char		buff[4096];
	int			ret;
	static int	count;

	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	if (ft_strcmp(buff, "BIENVENUE\n") == 0)
	{
		ft_strclr(buff);
		ft_strcat(buff, stc->team);
		ft_strcat(buff, "\n");
		write(sock, buff, ft_strlen(buff));
	}
	else if (count == 1)
	{
		stc->nb = ft_atoi(buff);
		stc->x = ft_atoi(&buff[ft_strlen_backslash(buff)]);
		stc->y = ft_atoi(&buff[ft_strlen_space(buff)]);
		if (stc->nb > 0)
			kill(getppid(), SIGUSR1);
		stc->start = 1;
	}
	count++;
	ft_strclr(buff);
}
