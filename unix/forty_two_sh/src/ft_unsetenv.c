/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 19:03:35 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:38:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static int		ft_check_envp(char **envp, char *s)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strstr(envp[i], s) != NULL)
		{
			if (envp[i][0] == s[0])
			{
				if (envp[i][ft_strlen(s)] == '=')
					return (i);
			}
		}
		i++;
	}
	return (-1);
}

void			ft_unsetenv(char **split)
{
	char	**envp;
	int		count;
	int		j;
	int		i;

	envp = ft_envp(NULL, "return");
	i = 1;
	while (split[i])
	{
		if ((count = ft_check_envp(envp, split[i])) != -1)
		{
			j = count;
			while (envp[j] != NULL)
			{
				if (envp[j + 1] == NULL)
					break ;
				ft_swap((int *)&envp[j], (int *)&envp[j + 1]);
				j++;
			}
			ft_strdel(&envp[j]);
		}
		i++;
	}
	ft_envp(envp, NULL);
	ft_strstrdel(split);
}
