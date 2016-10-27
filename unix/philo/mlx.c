/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 14:09:32 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/10 17:31:40 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			ft_mlx(void *data)
{
	static int		count;
	static void		*mlx_ptr;
	static void		*mlx_win;

	if (data == NULL)
	{
		mlx_string_put(mlx_ptr, mlx_win, 250, 500, 0xFF0000, \
				"press esc to quit");
		mlx_key_hook(mlx_win, key_hook, data);
		mlx_loop(mlx_ptr);
	}
	if (count == 0)
	{
		mlx_ptr = mlx_init();
		mlx_win = mlx_new_window(mlx_ptr, 600, 600, "philo");
		ft_table(mlx_ptr, mlx_win);
	}
	ft_mlx_print_one(mlx_ptr, mlx_win, data, 0);
	ft_mlx_print_two(mlx_ptr, mlx_win, data, 1);
	ft_mlx_print_three(mlx_ptr, mlx_win, data, 2);
	ft_mlx_print_four(mlx_ptr, mlx_win, data, 3);
	ft_mlx_print_five(mlx_ptr, mlx_win, data, 4);
	ft_mlx_print_six(mlx_ptr, mlx_win, data, 5);
	ft_mlx_print_seven(mlx_ptr, mlx_win, data, 6);
	count++;
}

int				key_hook(int key, void *data)
{
	(void)data;
	if (key == 65307)
		_exit(0);
	return (key);
}

void			ft_status(int status, int *pos, void *mlx_ptr, void *mlx_win)
{
	mlx_string_put(mlx_ptr, mlx_win, pos[0], pos[1], 0x000000, "rest");
	mlx_string_put(mlx_ptr, mlx_win, pos[0], pos[1], 0x000000, "eat");
	mlx_string_put(mlx_ptr, mlx_win, pos[0], pos[1], 0x000000, "think");
	if (status == 0)
		mlx_string_put(mlx_ptr, mlx_win, pos[0], pos[1], 0xFF0000, "rest");
	else if (status == 1)
		mlx_string_put(mlx_ptr, mlx_win, pos[0], pos[1], 0xFF0000, "eat");
	else if (status == 2)
		mlx_string_put(mlx_ptr, mlx_win, pos[0], pos[1], 0xFF0000, "think");
}

void			t_table(void *mlx_ptr, void *mlx_win, int y, int p)
{
	int		j;
	int		i;
	int		d;

	j = 450;
	i = 0;
	d = 0;
	while (i < 150)
	{
		d = y;
		while (y < j + 1)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, y, p, 0xB0C4DE);
			y++;
		}
		j -= 1;
		y = d + 1;
		p++;
		i++;
	}
}

void			ft_table(void *mlx_ptr, void *mlx_win)
{
	int		p;
	int		y;
	int		j;
	int		i;
	int		d;

	p = 150;
	y = 300;
	j = 300;
	i = 0;
	d = 0;
	while (i < 150)
	{
		d = y;
		while (y < j + 1)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, y, p, 0xB0C4DE);
			y++;
		}
		j += 1;
		y = d - 1;
		p++;
		i++;
	}
	t_table(mlx_ptr, mlx_win, y, p);
}
