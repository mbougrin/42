/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repos_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:27:56 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 23:00:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void	ft_repos_cursor(t_shell *sh)
{
	int		pos;

	pos = (int)ft_strlen(sh->str) - sh->pos;
	while (pos--)
		tputs(tgetstr("le", NULL), 1, ft_iputchar);
}
