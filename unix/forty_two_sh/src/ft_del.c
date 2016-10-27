/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 19:14:57 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:45:19 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static int		ft_end_of_line(t_shell *sh)
{
	char	*tmp;
	char	*str;

	str = sh->str;
	tmp = ft_strsub(str, 0, ft_strlen(str) - 1);
	free(sh->str);
	sh->str = ft_strdup(tmp);
	ft_strdel(&tmp);
	sh->pos = sh->pos - 1;
	return (0);
}

int				ft_del(t_shell *sh)
{
	char	*left;
	char	*right;
	char	*tmp;
	char	*str;

	str = sh->str;
	if (sh->pos == 0)
		return (0);
	if (sh->pos == (int)ft_strlen(str))
		return (ft_end_of_line(sh));
	left = ft_strsub(str, 0, sh->pos - 1);
	right = ft_strsub(str, sh->pos, (int)ft_strlen(str) - sh->pos);
	tmp = ft_strjoin(left, right);
	free(sh->str);
	sh->str = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_strdel(&left);
	ft_strdel(&right);
	sh->pos = sh->pos - 1;
	return (0);
}
