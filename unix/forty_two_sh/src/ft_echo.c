/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:51:47 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:33:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void			ft_echo(char **split)
{
	int		i;

	if (split[1] == NULL \
			|| (ft_strcmp(split[1], "-n") == 0 && split[2] == NULL))
		ft_putchar('\n');
	else if (split[1][0] == '-' && split[1][1] == 'n' && split[1][2] == '\0')
		ft_putstr(split[2]);
	else if (ft_strcmp(split[1], "-n") != 0)
	{
		i = 0;
		while (split[1][i] != '\0')
		{
			ft_putchar(split[1][i]);
			i++;
		}
		ft_putchar('\n');
	}
	ft_strstrdel(split);
}
