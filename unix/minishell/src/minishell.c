/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:46:04 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/12 08:53:46 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_check_str(char **split, char *s)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		if (ft_strcmp(split[i], s) == 0)
			break ;
		i++;
	}
	if (split[i] == NULL)
		return (-1);
	return (0);
}

static char		**ft_check_split(char **envp, char **split)
{
	if (ft_strcmp(split[0], "exit") == 0)
		ft_exit_split_nb(split);
	else if (ft_check_str(split, "|") == 0)
		ft_cmd_pipe(envp, split);
	else if (ft_check_str(split, "<") == 0)
		ft_lower(envp, split);
	else if (ft_check_str(split, "<<") == 0)
		ft_lower_lower(envp, split);
	else if (ft_check_str(split, ">") == 0)
		ft_higher(envp, split);
	else if (ft_check_str(split, ">>") == 0)
		ft_higher_higher(envp, split);
	else if (ft_strcmp(split[0], "env") == 0)
		ft_envp(split, envp);
	else if (ft_strcmp(split[0], "setenv") == 0 && split[1] != NULL)
		envp = ft_setenv(split[1], split[2], envp);
	else if (ft_strcmp(split[0], "unsetenv") == 0 && split[1] != NULL)
		ft_unsetenv(split[1], envp);
	else if (ft_strcmp(split[0], "cd") == 0)
		envp = ft_change_directory(split, envp);
	else
		ft_check_cmd(split, envp);
	return (envp);
}

static char		**ft_split_semicolon(char *line, char **envp)
{
	char	**split;
	char	**tmp_split;
	int		i;

	split = ft_strsplit(line, ';');
	if (split == NULL)
		return (envp);
	i = 0;
	while (split[i] != NULL)
	{
		tmp_split = ft_strsplit_minishell(split[i], ' ');
		envp = ft_check_split(envp, tmp_split);
		ft_strstrdel(tmp_split);
		i++;
	}
	ft_strstrdel(split);
	return (envp);
}

void			ft_minishell(char **envp)
{
	char		**split;
	char		*line;

	while (1)
	{
		ft_signal(envp);
		ft_prompt(envp);
		line = ft_termcaps();
		if (line[0] != '\0')
		{
			if (ft_strchr(line, ';') == NULL)
			{
				split = ft_strsplit_minishell(line, ' ');
				if (split != NULL)
				{
					envp = ft_check_split(envp, split);
					ft_strstrdel(split);
				}
			}
			else
				envp = ft_split_semicolon(line, envp);
		}
		ft_strdel(&line);
	}
}

int				main(int ac, char **av, char **envp)
{
	char	**tmp_envp;
	char	*tmp;
	char	*pwd;
	char	tmp1[256];

	if (envp[0] == NULL)
	{
		ft_putendl_fd("envp not found", 2);
		return (-1);
	}
	else if (ac == 1 && av[1] == NULL)
	{
		tmp_envp = ft_strstrdup(envp);
		pwd = ft_getenv("PWD", tmp_envp);
		tmp = ft_strjoin(pwd, "/ft_minishell3");
		ft_setenv("SHELL", tmp, tmp_envp);
		ft_strdel(&tmp);
		tmp = ft_strdup(getcwd(tmp1, sizeof(tmp1)));
		ft_setenv("PWD", tmp, tmp_envp);
		ft_strdel(&tmp);
		ft_minishell(tmp_envp);
	}
	else
		ft_putendl_fd("too many arguments", 2);
	return (0);
}
