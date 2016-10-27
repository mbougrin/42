/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:28:59 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:45:24 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

int		ft_down(t_shell *sh)
{
	if (sh->hist->next)
		sh->hist = sh->hist->next;
	else
		return (0);
	if (sh->hist->str)
	{
		free(sh->str);
		sh->str = ft_strdup(sh->hist->str);
	}
	sh->pos = (int)ft_strlen(sh->hist->str);
	return (0);
}
