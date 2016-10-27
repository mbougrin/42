/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 00:52:23 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:54:59 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <stdio.h>
# include <time.h>
# include <curses.h>

# define KEY 5678
# define SIZE_MAP 10
# define FLAGS 0755
# define SHMSZ SIZE_MAP * SIZE_MAP

typedef struct shmid_ds		t_shmid;

typedef struct		s_tmp
{
	int				i;
	int				x;
	int				y;
	int				x_tmp;
	int				y_tmp;
}					t_tmp;

typedef struct		s_ncs
{
	WINDOW			*win;
	int				color;
}					t_ncs;

typedef struct		s_stc
{
	int				shmid;
	char			*shm;
	t_shmid			shmid_ds;
	t_ncs			**ncs;
}					t_stc;

void				ft_print_menu(t_stc **stc);
void				ft_init_ncurses(void);
void				ft_print_map(t_ncs **ncs, char *map);
void				ft_free_ncs(t_ncs **ncs, int nb);
void				ft_check_color(t_ncs **ncs, int nb, char *map);
void				ft_create_win(t_ncs **ncs, int nb);
void				ft_malloc_ncs(t_ncs **ncs, int nb);
void				ft_init_background(t_ncs **ncs, int nb);
void				ft_resize(t_ncs **ncs, int nb);
void				ft_game_first(t_stc **stc);
void				ft_init(t_stc **stc);
void				ft_rand_first(t_stc **stc);
void				ft_rand_player(t_stc **stc, int tmp3, int tmp4);
void				ft_game_player(t_stc **stc);
void				ft_move_random(char *map, char c);
void				ft_create_map(t_stc **stc);
void				ft_move_random(char *map, char c);
int					ft_check_rand(char *map, char c, int i, int rnd);
int					ft_check_player_two(char *map, int i, int len);
int					ft_check_player_one(char *map, int i, int len);
int					ft_defeat(char *map);

#endif
