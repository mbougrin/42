/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 14:35:26 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/27 01:52:29 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <clt.h>

void			ft_print(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		ft_putendl(split[i]);
		i++;
	}
}

void			ft_see_next(t_see *see, int sock, char **split)
{
	int		i;

	i = 0;
	see->player = 0;
	ft_print(split);
	while (1)
	{
		see->feed = ft_atoi(split[i]);
		see->linemate = ft_atoi(split[i + 1]);
		see->deraumere = ft_atoi(split[i + 2]);
		see->sibur = ft_atoi(split[i + 3]);
		see->mendiane = ft_atoi(split[i + 4]);
		see->phiras = ft_atoi(split[i + 5]);
		see->thystame = ft_atoi(split[i + 6]);
		see->player = ft_atoi(split[i + 7]);
		if (see->player > 0 && i == 8)
		{
			ft_expels(sock);
			break ;
		}
		i += 8;
		if (split[i] == NULL)
			break ;
	}
}

void			ft_inventory_reset(t_stc *stc)
{
	stc->feed = 0;
	stc->linemate = 0;
	stc->deraumere = 0;
	stc->sibur = 0;
	stc->mendiane = 0;
	stc->phiras = 0;
	stc->thystame = 0;
}

int				ft_tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void			ft_inventory(int sock, t_stc *stc)
{
	char	buff[4096];
	char	**split;
	int		ret;

	ft_inventory_reset(stc);
	write(sock, "inventaire\n", ft_strlen("inventaire\n"));
	ret = read(sock, buff, 4096);
	buff[ret] = '\0';
	split = ft_strsplit(buff, ' ');
	if (split == NULL)
		exit(0);
	stc->feed = ft_atoi(split[0]);
	stc->linemate = ft_atoi(split[1]);
	stc->deraumere = ft_atoi(split[2]);
	stc->sibur = ft_atoi(split[3]);
	stc->mendiane = ft_atoi(split[4]);
	stc->phiras = ft_atoi(split[5]);
	stc->thystame = ft_atoi(split[6]);
	ft_strstrdel(split);
	ft_strclr(buff);
}
