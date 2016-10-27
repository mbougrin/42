/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 09:53:09 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/26 14:33:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <forty_two_sh.h>

static void		ft_save_envp(char **envp)
{
	int		i;
	int		fd;

	i = 0;
	if ((fd = open("tmp/envp.txt", O_WRONLY | O_CREAT | O_TRUNC \
					| O_APPEND, 0644)) == -1)
		return ;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], fd);
		i++;
	}
	close(fd);
}

static int		ft_open_read_len(int fd)
{
	int		i;
	char	*line;

	if (fd == -1)
		return (0);
	i = 1;
	while (get_next_line(fd, &line))
	{
		i++;
		ft_strdel(&line);
	}
	close(fd);
	return (i);
}

static char		**ft_back_up_envp(void)
{
	int		len;
	int		i;
	int		fd;
	char	**tmp;

	len = 0;
	i = 0;
	len = ft_open_read_len(open("tmp/envp.txt", O_RDONLY));
	if (len == 0)
		return (NULL);
	tmp = ft_strstrnew(len);
	fd = open("tmp/envp.txt", O_RDONLY);
	while (get_next_line(fd, &tmp[i]))
		i++;
	tmp[i] = NULL;
	close(fd);
	return (tmp);
}

static int		ft_no_envp(int nb)
{
	static int		count;

	if (nb == 0)
		count++;
	else if (count == 1)
	{
		count = 0;
		return (1);
	}
	return (0);
}

char			**ft_envp(char **envp, char *s)
{
	static char		**tmp_envp;

	if (ft_no_envp(1) == 1)
		return (NULL);
	else if (s != NULL && ft_strcmp(s, "env") == 0 && ft_no_envp(0) == 0)
		return (tmp_envp);
	if (s != NULL && ft_strcmp(s, "return") == 0)
		return (tmp_envp);
	else if (envp[0] == NULL)
		tmp_envp = ft_back_up_envp();
	else if (s != NULL && ft_strcmp(s, "add") == 0)
	{
		ft_save_envp(envp);
		ft_strstrdel(tmp_envp);
		tmp_envp = ft_strstrdup(envp);
		ft_strstrdel(envp);
	}
	else
	{
		ft_save_envp(envp);
		tmp_envp = ft_strstrdup(envp);
		ft_strstrdel(envp);
	}
	return (tmp_envp);
}
