/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 04:10:31 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:47:12 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>
#include "../includes/ft_func.h"

int		ft_key(t_shell *sh)
{
	t_key	key;

	key = UP;
	while (g_func[key].f != NULL)
	{
		if (ft_strcmp(g_func[key].keycode, sh->buff) == 0)
		{
			g_func[key].f(sh);
			return (1);
		}
		key++;
	}
	return (0);
}
