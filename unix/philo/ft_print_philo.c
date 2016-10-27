/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 14:15:53 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/10 18:42:04 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_mlx_print_six(void *mlx_ptr, void *mlx_win, void *data, int i)
{
	static int		nb;
	int				pos[2];

	mlx_string_put(mlx_ptr, mlx_win, 180, 580, 0x000000, ft_itoa(nb));
	mlx_string_put(mlx_ptr, mlx_win, 180, 560, 0xFF0000, "philo 5");
	mlx_string_put(mlx_ptr, mlx_win, 180, 580, 0xFF0000, \
			ft_itoa(((t_ph **)data)[i]->life));
	pos[0] = 180;
	pos[1] = 600;
	ft_status(((t_ph **)data)[i]->status, pos, mlx_ptr, mlx_win);
	nb = ((t_ph **)data)[i]->life;
}

void		ft_mlx_print_seven(void *mlx_ptr, void *mlx_win, void *data, int i)
{
	static int		nb;
	int				pos[2];

	mlx_string_put(mlx_ptr, mlx_win, 360, 580, 0x000000, ft_itoa(nb));
	mlx_string_put(mlx_ptr, mlx_win, 360, 560, 0xFF0000, "philo 6");
	mlx_string_put(mlx_ptr, mlx_win, 360, 580, 0xFF0000, \
			ft_itoa(((t_ph **)data)[i]->life));
	pos[0] = 360;
	pos[1] = 600;
	ft_status(((t_ph **)data)[i]->status, pos, mlx_ptr, mlx_win);
	nb = ((t_ph **)data)[i]->life;
}
