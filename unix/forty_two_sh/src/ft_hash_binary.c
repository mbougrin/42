/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 12:43:13 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 06:02:18 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_add_hash(DIR *rep, int **hash, char **split, int i)
{
	int					j;
	struct dirent		*play;
	char				*tmp;

	while ((play = readdir(rep)))
	{
		if (hash[ft_hash(play->d_name)] == NULL && play->d_name[0] != '.')
		{
			tmp = ft_strjoin("/", play->d_name);
			hash[ft_hash(play->d_name)] = (int *)ft_strjoin(split[i], tmp);
			ft_strdel(&tmp);
		}
		else if (hash[ft_hash(play->d_name)] != NULL && play->d_name[0] != '.')
		{
			j = 0;
			while (hash[ft_hash(play->d_name) + j] != NULL)
				j++;
			tmp = ft_strjoin("/", play->d_name);
			hash[ft_hash(play->d_name) + j] = (int *)ft_strjoin(split[i], tmp);
			ft_strdel(&tmp);
		}
	}
}

static void		ft_create_hash(char *path, int **hash)
{
	DIR					*rep;
	char				**split;
	int					i;

	i = 0;
	split = ft_strsplit(&path[5], ':');
	while (split[i])
	{
		if (access(split[i], F_OK | X_OK | R_OK) == 0)
		{
			rep = opendir(split[i]);
			ft_add_hash(rep, hash, split, i);
			closedir(rep);
		}
		else if (access(split[i], F_OK) == 0)
			ft_path_error(split[i], 0);
		else
			ft_path_error(split[i], 1);
		i++;
	}
	if (split != NULL)
		ft_strstrdel(split);
}

static char		*ft_check_permission(int **hash, int i, char *cmd)
{
	char	*tmp;

	tmp = (char *)hash[ft_hash(cmd) + i];
	if (hash[ft_hash(cmd) + i] != NULL && tmp[0] == '/')
	{
		if (access((char *)hash[ft_hash(cmd) + i], F_OK | X_OK | R_OK) != 0)
		{
			ft_strdel(&tmp);
			return (ft_cmd_permission_denied(cmd));
		}
		else if (access((char *)hash[ft_hash(cmd) + i], F_OK) != 0)
		{
			ft_strdel(&tmp);
			return (ft_cmd_not_found(cmd));
		}
	}
	else if (hash[ft_hash(cmd) + i] == NULL || tmp[0] != '/')
	{
		ft_strdel(&tmp);
		return (ft_cmd_not_found(cmd));
	}
	return (cmd);
}

static char		*ft_check_command(int **hash, char *cmd)
{
	int		j;
	int		i;
	char	*command;

	i = 0;
	while (hash[ft_hash(cmd) + i] != NULL)
	{
		command = (char *)hash[ft_hash(cmd) + i];
		j = ft_strlen(command);
		while (j > 0)
		{
			if (command[j - 1] == '/')
				break ;
			j--;
		}
		if (ft_strcmp(&command[j], cmd) == 0)
			break ;
		i++;
	}
	if (ft_check_permission(hash, i, cmd) == NULL)
		return (NULL);
	ft_strdel(&cmd);
	return (command);
}

char			*ft_hash_binary(char *path, char *cmd)
{
	static char		*path_tmp;
	static int		*hash[4096];

	if (path != NULL && path_tmp == NULL && path[ft_strlen(path) - 1] != '=' \
			&& ft_check_path(path) != 0)
	{
		path_tmp = path;
		ft_create_hash(path_tmp, hash);
		return (ft_check_command(hash, cmd));
	}
	else if (path != NULL && ft_strcmp(path_tmp, path) != 0 \
			&& path[ft_strlen(path) - 1] != '=' && ft_check_path(path) != 0 \
			&& ft_strchr(path, ':') != NULL)
	{
		ft_strdel(&path_tmp);
		path_tmp = path;
		ft_hash_delete(hash, 4096);
		ft_create_hash(path_tmp, hash);
		return (ft_check_command(hash, cmd));
	}
	if (path != NULL)
		ft_strdel(&path);
	return (ft_check_command(hash, cmd));
}
