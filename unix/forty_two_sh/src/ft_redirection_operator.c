/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_operator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:37:55 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 06:18:14 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

int				ft_check_cmd_found(char *s)
{
	char	*tmp;

	tmp = ft_copy_str(s);
	if (access(tmp, X_OK | F_OK) == 0)
	{
		ft_strdel(&tmp);
		ft_strdel(&s);
		return (1);
	}
	return (0);
}

int				ft_check_command_found(char *line)
{
	char	*s;

	s = ft_strsub(line, 0, ft_strlen_space(line));
	if (s[0] == '/' && access(s, F_OK | X_OK) == 0)
	{
		ft_strdel(&s);
		return (1);
	}
	if (ft_strstr(s, "./") != NULL && ft_check_cmd_found(s) == 1)
		return (1);
	if (ft_hash_binary(ft_getenv("PATH"), ft_strsub(line, 0, \
					ft_strlen_space(line))) != NULL)
	{
		ft_strdel(&s);
		return (1);
	}
	ft_strdel(&s);
	return (0);
}

static char		*ft_check_operator(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
			return (ft_strdup("<<"));
		if (line[i] == '>' && line[i + 1] == '>')
			return (ft_strdup(">>"));
		if (line[i] == '|' && line[i + 1] == '|')
			return (ft_strdup("||"));
		if (line[i] == '&' && line[i + 1] == '&')
			return (ft_strdup("&&"));
		i++;
	}
	return (NULL);
}

static char		*ft_operator(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '<')
			return (ft_strdup("<\0"));
		if (line[i] == '>')
			return (ft_strdup(">\0"));
		if (line[i] == '|')
			return (ft_strdup("|\0"));
		i++;
	}
	return (NULL);
}

void			ft_redirection_operator(char *line)
{
	char	*str;

	str = ft_check_operator(line);
	if (str == NULL)
		str = ft_operator(line);
	if (ft_strcmp(str, "&&") == 0 || ft_strcmp(str, "||") == 0)
		ft_logical_operators(line);
	if (ft_strcmp(str, ">>") == 0)
		ft_higher_higher(line);
	if (ft_strcmp(str, ">") == 0)
		ft_higher(line);
	if (ft_strcmp(str, "<") == 0)
		ft_lower(line);
	if (ft_strcmp(str, "<<") == 0)
		ft_lower_lower(line);
	if (ft_strcmp(str, "|") == 0)
		ft_pipe(line);
	ft_strdel(&str);
}
