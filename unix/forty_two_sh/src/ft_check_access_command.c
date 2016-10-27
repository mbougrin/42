/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_access_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:35:05 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 17:35:22 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

char			*ft_copy_str(char *s)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(s) - 2);
	while (s[i])
	{
		if (s[i - 1] != '.' && s[i] == '.' && s[i + 1] == '/')
			i += 2;
		else
		{
			tmp[j] = s[i];
			j++;
			i++;
		}
	}
	return (tmp);
}

static int		ft_check(char *line)
{
	struct stat		s_stat;

	stat(line, &s_stat);
	if (S_ISDIR(s_stat.st_mode) == 1)
		return (1);
	return (0);
}

static int		ft_cmd_not_access(char **split, char *tmp, char *cmd)
{
	ft_strstrdel(split);
	ft_strdel(&tmp);
	ft_cmd_not_found(cmd);
	return (-1);
}

int				ft_check_access_command(char *line)
{
	char	*tmp;
	char	*cmd;
	char	**split;
	int		ret;

	split = ft_shellsplit(line, ' ');
	cmd = ft_strdup(split[0]);
	tmp = ft_copy_str(split[0]);
	if (access(tmp, F_OK) != 0)
		return (ft_cmd_not_access(split, tmp, cmd));
	else if (access(tmp, F_OK | R_OK | X_OK) == 0 && ft_check(tmp) == 0)
		ret = ft_execve(tmp, split);
	else
	{
		ft_strstrdel(split);
		ft_strdel(&tmp);
		ft_cmd_permission_denied(cmd);
		return (-1);
	}
	ft_strdel(&tmp);
	ft_strdel(&cmd);
	return (ret);
}
