/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:47:56 by scadoux           #+#    #+#             */
/*   Updated: 2014/03/26 21:48:04 by mbougrin         ###   ########.fr       */
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

static int		ft_get_word(char *str, int pos)
{
	int		left;
	int		i;
	int		wrd;

	left = pos;
	i = 0;
	wrd = 0;
	while (i < left)
	{
		if (str[i] == ' ')
			i++;
		else
		{
			wrd++;
			while (str[i] != ' ' && i < left)
				i++;
		}
	}
	return (wrd);
}

int				ft_shift_l(t_shell *sh)
{
	int		i;
	int		wrd;
	char	*str;

	if (sh->pos == 0)
		return (0);
	i = 0;
	str = sh->str;
	wrd = ft_get_word(str, sh->pos);
	while (wrd != 0)
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			wrd--;
			while (ft_isspace(str[i]) == 0 && wrd != 0)
				i++;
		}
	}
	sh->pos = i;
	return (0);
}
