/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 14:13:17 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/10 16:47:17 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_mlx_print_one(void *mlx_ptr, void *mlx_win, void *data, int i)
{
	static int		nb;
	int				pos[2];

	mlx_string_put(mlx_ptr, mlx_win, 10, 30, 0x000000, ft_itoa(nb));
	mlx_string_put(mlx_ptr, mlx_win, 10, 10, 0xFF0000, "philo 0");
	mlx_string_put(mlx_ptr, mlx_win, 10, 30, 0xFF0000, \
			ft_itoa(((t_ph **)data)[i]->life));
	pos[0] = 10;
	pos[1] = 50;
	ft_status(((t_ph **)data)[i]->status, pos, mlx_ptr, mlx_win);
	nb = ((t_ph **)data)[i]->life;
}

void		ft_mlx_print_two(void *mlx_ptr, void *mlx_win, void *data, int i)
{
	static int		nb;
	int				pos[2];

	mlx_string_put(mlx_ptr, mlx_win, 300, 30, 0x000000, ft_itoa(nb));
	mlx_string_put(mlx_ptr, mlx_win, 300, 10, 0xFF0000, "philo 1");
	mlx_string_put(mlx_ptr, mlx_win, 300, 30, 0xFF0000, \
			ft_itoa(((t_ph **)data)[i]->life));
	pos[0] = 300;
	pos[1] = 50;
	ft_status(((t_ph **)data)[i]->status, pos, mlx_ptr, mlx_win);
	nb = ((t_ph **)data)[i]->life;
}

void		ft_mlx_print_three(void *mlx_ptr, void *mlx_win, void *data, int i)
{
	static int		nb;
	int				pos[2];

	mlx_string_put(mlx_ptr, mlx_win, 550, 30, 0x000000, ft_itoa(nb));
	mlx_string_put(mlx_ptr, mlx_win, 550, 10, 0xFF0000, "philo 2");
	mlx_string_put(mlx_ptr, mlx_win, 550, 30, 0xFF0000, \
			ft_itoa(((t_ph **)data)[i]->life));
	pos[0] = 550;
	pos[1] = 50;
	ft_status(((t_ph **)data)[i]->status, pos, mlx_ptr, mlx_win);
	nb = ((t_ph **)data)[i]->life;
}

void		ft_mlx_print_four(void *mlx_ptr, void *mlx_win, void *data, int i)
{
	static int		nb;
	int				pos[2];

	mlx_string_put(mlx_ptr, mlx_win, 10, 320, 0x000000, ft_itoa(nb));
	mlx_string_put(mlx_ptr, mlx_win, 10, 300, 0xFF0000, "philo 3");
	mlx_string_put(mlx_ptr, mlx_win, 10, 320, 0xFF0000, \
			ft_itoa(((t_ph **)data)[i]->life));
	pos[0] = 10;
	pos[1] = 340;
	ft_status(((t_ph **)data)[i]->status, pos, mlx_ptr, mlx_win);
	nb = ((t_ph **)data)[i]->life;
}

void		ft_mlx_print_five(void *mlx_ptr, void *mlx_win, void *data, int i)
{
	static int		nb;
	int				pos[2];

	mlx_string_put(mlx_ptr, mlx_win, 550, 320, 0x000000, ft_itoa(nb));
	mlx_string_put(mlx_ptr, mlx_win, 550, 300, 0xFF0000, "philo 4");
	mlx_string_put(mlx_ptr, mlx_win, 550, 320, 0xFF0000, \
			ft_itoa(((t_ph **)data)[i]->life));
	pos[0] = 550;
	pos[1] = 340;
	ft_status(((t_ph **)data)[i]->status, pos, mlx_ptr, mlx_win);
	nb = ((t_ph **)data)[i]->life;
}
