/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 15:02:15 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 15:03:33 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void			ft_modify_split(char **split, int n)
{
	split[n] = NULL;
	n--;
	while (n > 0)
	{
		if (split[n][0] == '\0')
		{
			ft_strdel(&split[n]);
			split[n] = NULL;
		}
		n--;
	}
}
