/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 00:51:58 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:52:02 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			ft_create_map(t_stc **stc)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (j < SIZE_MAP)
	{
		ft_memset((void *)&(*stc)->shm[i], '0', SIZE_MAP);
		i += SIZE_MAP;
		(*stc)->shm[i] = '\n';
		i++;
		j++;
	}
}

void			ft_move_random(char *map, char c)
{
	int		i;
	int		rnd;

	i = 1;
	while (map[i])
	{
		if (map[i] == c)
		{
			while (1)
			{
				rnd = 0;
				if (ft_check_rand(map, c, i, rnd) == 1)
					break ;
			}
			map[i] = '0';
		}
		i++;
	}
}

void			ft_check_memory(t_stc **stc)
{
	if (((*stc)->shmid = shmget(KEY, SHMSZ + 2 + SIZE_MAP, \
					IPC_CREAT | IPC_EXCL | FLAGS)) < 0)
	{
		if (((*stc)->shmid = shmget(KEY, SHMSZ, FLAGS)) < 0)
			perror("shmget");
		if (((*stc)->shm = shmat((*stc)->shmid, NULL, 0)) == (char *)-1)
		{
			ft_putendl("shmat error");
			perror("shmat");
			exit(0);
		}
		ft_game_player(stc);
	}
	else
	{
		if (((*stc)->shm = shmat((*stc)->shmid, NULL, 0)) == (char *)-1)
		{
			ft_putendl("shmat error");
			perror("shmat");
			exit(0);
		}
		ft_game_first(stc);
	}
}

int				main(void)
{
	t_stc	*stc;

	srand(time(NULL));
	stc = (t_stc *)malloc(sizeof(t_stc));
	ft_check_memory(&stc);
	free(stc);
	return (0);
}
