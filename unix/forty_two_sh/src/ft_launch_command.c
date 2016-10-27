/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 13:40:07 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 06:25:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static char		*ft_create_cmd(char *line_tmp)
{
	int		i;

	i = ft_strlen(line_tmp);
	while (line_tmp[i] != '/')
		i--;
	return (ft_strsub(line_tmp, 0, i));
}

static int		ft_check_perm(char *line_tmp, char *cmd, char *line)
{
	int		ret;

	if (access(cmd, X_OK | R_OK) != 0)
	{
		ft_strdel(&cmd);
		ft_cmd_permission_denied(line_tmp);
		return (-1);
	}
	if (access(line_tmp, F_OK) != 0)
	{
		ft_strdel(&cmd);
		ft_cmd_not_found(line_tmp);
		return (-1);
	}
	if (access(line_tmp, F_OK | X_OK | R_OK) != 0)
	{
		ft_strdel(&cmd);
		ft_cmd_permission_denied(line_tmp);
		return (-1);
	}
	ret = ft_execve(line_tmp, ft_shellsplit(line, ' '));
	ft_strdel(&cmd);
	ft_strdel(&line_tmp);
	return (ret);
}

int				ft_launch_command(char *line)
{
	char	**tmp;
	char	*line_tmp;
	char	*cmd;

	tmp = ft_shellsplit(line, ' ');
	line_tmp = ft_strdup(tmp[0]);
	cmd = ft_create_cmd(line_tmp);
	ft_strstrdel(tmp);
	if (access(cmd, F_OK) == 0 && cmd[ft_strlen(cmd) - 1] != '/')
		return (ft_check_perm(line_tmp, cmd, line));
	else
	{
		ft_strdel(&cmd);
		if (ft_cmd_not_found(line_tmp) == NULL)
			return (-1);
	}
	ft_strdel(&line_tmp);
	return (0);
}
