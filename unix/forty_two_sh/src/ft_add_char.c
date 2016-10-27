/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 14:13:04 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 22:07:09 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

void	ft_add_char(t_shell *sh)
{
	char	*left;
	char	*right;
	char	*tmp;
	char	*ptr;
	int		size;

	ptr = sh->str;
	left = ft_strsub(ptr, 0, sh->pos);
	size = (int)ft_strlen(ptr);
	if (sh->pos == size)
		right = ft_strnew(1);
	else
		right = ft_strsub(ptr, sh->pos, size - sh->pos);
	tmp = ft_strjoin(left, sh->buff);
	free(sh->str);
	sh->str = ft_strjoin(tmp, right);
	ft_strdel(&left);
	ft_strdel(&right);
	ft_strdel(&tmp);
	sh->pos = sh->pos + 1;
}
