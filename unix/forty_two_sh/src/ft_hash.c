/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:43:01 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 04:46:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

char			*ft_cmd_not_found(char *cmd)
{
	ft_putstr_fd("42sh: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	ft_strdel(&cmd);
	return (NULL);
}

char			*ft_cmd_permission_denied(char *cmd)
{
	ft_putstr_fd("42sh: permission denied: ", 2);
	ft_putendl_fd(cmd, 2);
	ft_strdel(&cmd);
	return (NULL);
}

void			ft_hash_delete(int **hash, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	while (len > i)
	{
		if (hash[i] != NULL)
		{
			tmp = (char *)hash[i];
			ft_strclr(tmp);
		}
		i++;
	}
}

int				ft_check_path(char *path)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(&path[5], ':');
	while (split[i])
	{
		if (access(split[i], F_OK | R_OK | X_OK) == 0)
		{
			ft_strstrdel(split);
			return (1);
		}
		i++;
	}
	ft_strstrdel(split);
	return (0);
}

int				ft_hash(char *cmd)
{
	int		number_hash;
	int		i;

	number_hash = 0;
	i = 0;
	while (cmd[i])
	{
		number_hash += cmd[i];
		i++;
	}
	return (number_hash);
}
