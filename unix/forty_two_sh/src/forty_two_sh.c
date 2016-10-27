/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forty_two_sh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:30:47 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 22:01:51 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_check_line(char **line)
{
	char			c;
	struct stat		s_stat;

	stat(&line[0][2], &s_stat);
	if (*line == NULL)
		return ;
	if (ft_strstr(*line, "./") != NULL && s_stat.st_mode == 33188)
		ft_shell_script(&*line);
	if (ft_check_bquote(*line) != 0)
		ft_modify_bquote(&*line, '`');
	if ((c = ft_check_quote(*line) == -1))
		ft_quote(&*line, c);
	if (ft_strchr(*line, '~') != NULL)
		ft_tilde(&*line);
	if (ft_strchr(*line, '\t') != NULL)
		ft_replace_tabulation(&*line);
	if (ft_strchr(*line, '`') != NULL)
		ft_replace_bquote(&*line);
	if (ft_check_space(*line) == 0)
		ft_shelltrim(&*line);
	if (ft_strstr(*line, "\\") != NULL)
		ft_back_slash(&*line);
}

int				ft_check_command_line(char *line)
{
	int		ret;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	if (line == NULL || line[0] == '\0' || line[0] == ' ')
		return (-1);
	if (ft_strstr(tmp[0], "./") != NULL)
		ret = ft_check_access_command(line);
	else if (line[0] == '/')
		ret = ft_launch_command(line);
	else if (line[0] != '\0' && ft_builtin(line) == 0)
		ret = ft_execve(ft_hash_binary(ft_getenv("PATH"), ft_strsub(line, 0, \
						ft_strlen_space(line))), ft_shellsplit(line, ' '));
	ft_strstrdel(tmp);
	return (ret);
}

static int		ft_check_separator(char *line)
{
	if (ft_strstr(line, "||") != NULL || ft_strstr(line, "&&") != NULL)
		return (0);
	if (ft_strstr(line, "<<") != NULL || ft_strstr(line, ">>") != NULL)
		return (0);
	if (ft_strchr(line, '<') != NULL || ft_strchr(line, '>') != NULL \
			|| ft_strchr(line, '|') != NULL)
		return (0);
	return (-1);
}

static void		ft_semicolon(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ';');
	if (split == NULL)
		return ;
	while (split[i])
	{
		ft_check_line(&split[i]);
		if (ft_check_separator(split[i]) == 0)
			ft_redirection_operator(split[i]);
		else
			ft_check_command_line(split[i]);
		i++;
	}
	ft_strstrdel(split);
}

void			ft_forty_two_sh(char *s)
{
	char	*line;

	line = ft_strdup(s);
	ft_check_line(&line);
	if (ft_strchr(line, ';') == NULL)
	{
		if (ft_check_separator(line) == 0)
			ft_redirection_operator(line);
		else
			ft_check_command_line(line);
	}
	else
		ft_semicolon(line);
	ft_strdel(&line);
}
