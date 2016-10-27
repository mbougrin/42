/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 13:51:54 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:39:22 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void			ft_path_error(char *s, int i)
{
	if (i == 0)
	{
		ft_putstr_fd("PATH: permission denied: ", 2);
		ft_putendl_fd(s, 2);
	}
	else if (i == 1)
	{
		ft_putstr_fd("PATH: no such file or directory: ", 2);
		ft_putendl_fd(s, 2);
	}
}
