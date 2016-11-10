/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 12:36:14 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 23:38:50 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void			copy(void)
{
	t_opt		*opt;

	opt = singleton(NULL);
	setsid();
	if ((ioctl(opt->slave, TIOCSCTTY, NULL)) == -1)
		ioctlerror();
	dup2(opt->slave, 0);
	dup2(opt->slave, 1);
	dup2(opt->slave, 2);
	close(opt->slave);
}

void			ft_execve(void)
{
	t_opt		*opt;
	char		*tab[3];

	opt = singleton(NULL);
	copy();
	tab[0] = opt->shell;
	tab[1] = "-i";
	tab[2] = NULL;
	if ((execve(opt->shell, tab, opt->env)) == -1)
		return ;
}

char			*ft_getenv(char *env)
{
	t_opt		*opt;
	char		**split;
	char		*ret;
	int			i;

	i = 0;
	ret = NULL;
	opt = singleton(NULL);
	while (opt->env[i] != NULL)
	{
		split = ft_strsplit(opt->env[i], '=');
		if (ft_strncmp(env, split[0], ft_strlen(env)) == 0 \
				&& opt->env[i][ft_strlen(env)] == '=')
		{
			ret = ft_strdup(split[1]);
			ft_strstrdel(split);
			break ;
		}
		ft_strstrdel(split);
		i++;
	}
	return (ret);
}
