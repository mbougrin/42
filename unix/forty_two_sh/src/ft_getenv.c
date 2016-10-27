/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 11:58:17 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 04:08:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

char			*ft_getenv(char *s)
{
	char	**envp;
	int		i;

	i = 0;
	envp = ft_envp(NULL, "return");
	while (envp[i])
	{
		if (ft_strncmp(envp[i], s, ft_strlen(s)) == 0)
			return (ft_strdup(envp[i]));
		i++;
	}
	return (NULL);
}
