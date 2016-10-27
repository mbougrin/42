/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/05 08:49:30 by mbar              #+#    #+#             */
/*   Updated: 2014/05/12 11:11:11 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <libft.h>
# include <mlx.h>
# include <pthread.h>
# include <time.h>

# define NB_PH 7
# define MAX_LIFE 10
# define EAT_T 1
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 60

# define REST 0
# define EAT 1
# define THINK 2

typedef struct	s_ph
{
	int			id;
	int			life;
	int			status;
}				t_ph;

int				key_hook(int key, void *data);
void			ft_status(int status, int *pos, void *mlx_ptr, \
				void *mlx_win);
void			t_table(void *mlx_ptr, void *mlx_win, int y, int p);
void			ft_table(void *mlx_ptr, void *mlx_win);
void			ft_mlx(void *data);
void			ft_mlx_print_seven(void *mlx_ptr, void *mlx_win, \
				void *data, int i);
void			ft_mlx_print_six(void *mlx_ptr, void *mlx_win, \
				void *data, int i);
void			ft_mlx_print_five(void *mlx_ptr, void *mlx_win, \
				void *data, int i);
void			ft_mlx_print_four(void *mlx_ptr, void *mlx_win, \
				void *data, int i);
void			ft_mlx_print_three(void *mlx_ptr, void *mlx_win, \
				void *data, int i);
void			ft_mlx_print_two(void *mlx_ptr, void *mlx_win, \
				void *data, int i);
void			ft_mlx_print_one(void *mlx_ptr, void *mlx_win, \
				void *data, int i);
void			*ft_action(void *data);
void			*ft_time(void *data);

#endif
