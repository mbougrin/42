/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:31:55 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:47:18 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

int		ft_left(t_shell *sh)
{
	if (sh->pos > 0)
		sh->pos = sh->pos - 1;
	return (0);
}
