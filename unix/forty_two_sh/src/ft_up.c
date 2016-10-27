/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:27:34 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:48:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

int		ft_up(t_shell *sh)
{
	if (sh->hist->prev)
		sh->hist = sh->hist->prev;
	if (sh->hist->str)
	{
		free(sh->str);
		sh->str = ft_strdup(sh->hist->str);
	}
	sh->pos = (int)ft_strlen(sh->hist->str);
	return (0);
}
