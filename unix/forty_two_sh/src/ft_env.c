/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:15:35 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 05:48:37 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_print_envp(void)
{
	char	**envp;
	int		i;

	i = 0;
	envp = ft_envp(NULL, "return");
	while (envp[i])
	{
		ft_putendl(envp[i]);
		i++;
	}
}

static int		ft_split_len(char **split)
{
	int		i;
	char	*str;
	char	**tmp;

	i = 0;
	while (split[i])
	{
		if (ft_strcmp(split[i], "env") == 0)
			i++;
		else if (ft_strcmp(split[i], "-i") == 0)
			i++;
		else if (ft_strchr(split[i], '=') != NULL)
		{
			str = ft_strjoin("setenv=", split[i]);
			tmp = ft_strsplit(str, '=');
			ft_setenv(tmp);
			i++;
			ft_strdel(&str);
		}
		else if (ft_strchr(split[i], '=') == NULL)
			break ;
	}
	return (i);
}

static char		*ft_create_cmd(char **split)
{
	if (split[ft_split_len(split)] != NULL)
		return (split[ft_split_len(split)]);
	return (NULL);
}

static int		ft_line_start(char *s, char **split)
{
	int		i;
	int		len;

	len = ft_split_len(split);
	i = 0;
	while (len > 0)
	{
		while (s[i])
		{
			if (s[i] == ' ')
				break ;
			i++;
		}
		while (s[i] == ' ')
			i++;
		len--;
	}
	return (i);
}

void			ft_env(char *s, char **split)
{
	char	**save_envp;
	char	*cmd;
	char	*line;

	save_envp = ft_strstrdup(ft_envp(NULL, "return"));
	cmd = ft_create_cmd(split);
	line = ft_strsub(s, ft_line_start(s, split), \
			(ft_strlen(s) - ft_line_start(s, split)));
	if (cmd == NULL && ft_strstr(s, "-i") == NULL)
		ft_print_envp();
	if (ft_strstr(s, "-i") != NULL && cmd != NULL)
		ft_envp(NULL, "env");
	if (ft_strstr(s, "-i") != NULL && cmd == NULL)
		ft_envp(NULL, "env");
	if (cmd != NULL && ft_strstr(cmd, "./") != NULL)
		ft_check_access_command(line);
	else if (cmd != NULL && cmd[0] == '/')
		ft_launch_command(line);
	else if (cmd != NULL)
		ft_execve(ft_hash_binary(NULL, ft_strdup(cmd)), \
						ft_strstrdup(&split[ft_split_len(split)]));
	ft_strdel(&line);
	ft_envp(save_envp, "add");
	ft_strstrdel(split);
}
