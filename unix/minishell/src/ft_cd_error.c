/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 15:42:43 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/04 15:48:41 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void				ft_cd_error(char *cmd, int nb)
{
	if (nb == 0)
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(cmd);
	}
	else if (nb == 1)
	{
		ft_putstr("cd: not a directory: ");
		ft_putendl(cmd);
	}
	else if (nb == 2)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(cmd);
	}
}
