/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 18:49:14 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:48:11 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int				ft_shift_r(t_shell *sh)
{
	int		i;
	char	*str;

	if (sh->pos == (int)ft_strlen(sh->str))
		return (0);
	i = sh->pos;
	str = sh->str;
	if (ft_isspace(str[i]))
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		sh->pos = i;
	}
	else
	{
		while (ft_isspace(str[i]) == 0 && str[i])
			i++;
		while (ft_isspace(str[i]) && str[i])
			i++;
		sh->pos = i;
	}
	return (0);
}
