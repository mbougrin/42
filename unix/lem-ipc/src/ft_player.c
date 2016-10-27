/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:41:54 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:42:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_rand_player(t_stc **stc, int tmp3, int tmp4)
{
	while (1)
	{
		if ((*stc)->shm[tmp3] != '1')
		{
			if ((*stc)->shm[tmp3] == '\n')
				tmp3++;
			(*stc)->shm[tmp3] = '2';
			break ;
		}
		else
			tmp3 = (rand() % SHMSZ) + 1;
	}
	while (1)
	{
		if ((*stc)->shm[tmp4] != '1' && (*stc)->shm[tmp4] != '2')
		{
			if ((*stc)->shm[tmp4] == '\n')
				tmp4++;
			(*stc)->shm[tmp4] = '2';
			break ;
		}
		else
			tmp4 = (rand() % SHMSZ) + 1;
	}
}

void			ft_game_player(t_stc **stc)
{
	int		tmp3;
	int		tmp4;

	(*stc)->shm[0] += 1;
	sleep(1);
	tmp3 = (rand() % SHMSZ) + 1;
	tmp4 = (rand() % SHMSZ) + 1;
	ft_rand_player(stc, tmp3, tmp4);
	while ((*stc)->shm[0] < '4')
	{
		if ((*stc)->shm[0] == '2')
		{
			ft_move_random((*stc)->shm, '2');
			(*stc)->shm[0] = '1';
		}
	}
	sleep(1);
}
