/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tilde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 17:46:12 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:38:21 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static int			ft_len_tilde(char *s, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '~')
			j++;
		i++;
	}
	return (j * len);
}

void				ft_tilde(char **s)
{
	char	*home;
	char	*tmp;
	int		i;
	int		j;

	home = ft_getenv("HOME");
	i = 0;
	j = 0;
	tmp = ft_strnew((ft_len_tilde(*s, ft_strlen(&home[4])) + ft_strlen(*s)));
	while (s[0][i] != '\0')
	{
		if (s[0][i] == '~' && s[0][i - 1] == ' ')
		{
			ft_strcpy(&tmp[j], &home[5]);
			j += ft_strlen(&home[5]) - 1;
		}
		else
			tmp[j] = s[0][i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	ft_strdel(&home);
	ft_strdel(&*s);
	s[0] = tmp;
}
