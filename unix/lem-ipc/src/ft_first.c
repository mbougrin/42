/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:39:43 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:40:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_rand_first(t_stc **stc)
{
	int		tmp1;
	int		tmp2;

	tmp1 = (rand() % SHMSZ) + 1;
	tmp2 = (rand() % SHMSZ) + 1;
	if ((*stc)->shm[tmp1] == '\n')
		tmp1++;
	(*stc)->shm[tmp1] = '1';
	while (tmp1 == tmp2)
		tmp2 = (rand() % SHMSZ) + 1;
	if ((*stc)->shm[tmp2] == '\n')
		tmp2++;
	(*stc)->shm[tmp2] = '1';
}

void			ft_init(t_stc **stc)
{
	ft_bzero((void *)(*stc)->shm, SHMSZ + 2);
	(*stc)->shm[0] = '1';
	ft_create_map(stc);
	ft_init_ncurses();
	ft_print_menu(stc);
	(*stc)->shm[0] = '1';
}

void			ft_game_first(t_stc **stc)
{
	ft_init(stc);
	(*stc)->ncs = (t_ncs **)malloc(sizeof(t_ncs *) * SHMSZ);
	ft_malloc_ncs((*stc)->ncs, SHMSZ);
	ft_create_win((*stc)->ncs, SHMSZ);
	ft_rand_first(stc);
	while ((*stc)->shm[0] < '4')
	{
		if ((*stc)->shm[0] == '1')
		{
			if (ft_defeat(&(*stc)->shm[1]) == 1)
			{
				(*stc)->shm[0] = '4';
				ft_print_map((*stc)->ncs, (*stc)->shm);
				break ;
			}
			ft_move_random((*stc)->shm, '1');
			(*stc)->shm[0] = '2';
		}
		ft_print_map((*stc)->ncs, (*stc)->shm);
	}
	sleep(5);
	ft_free_ncs((*stc)->ncs, SHMSZ);
	shmctl((*stc)->shmid, IPC_RMID, &(*stc)->shmid_ds);
	endwin();
}
