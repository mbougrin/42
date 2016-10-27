/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 11:40:52 by mbougrin          #+#    #+#             */
/*   Updated: 2014/05/17 14:16:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header_server.h>

void			ft_pwd(int cs, char *s)
{
	static char		pwd[4096];
	int				i;

	if (s != NULL)
	{
		if (ft_strcmp(s, "cd") == 0)
			ft_strclr(pwd);
		else
		{
			ft_strcat(pwd, "/");
			ft_strcat(pwd, s);
			i = ft_strlen(pwd);
			while (i > 0)
			{
				if (s[i] == '.')
					pwd[i] = '\0';
				i--;
			}
			ft_strcat(pwd, "\n");
		}
	}
	else if (pwd[0] == '\0')
		write(cs, "/\n", 2);
	else
		write(cs, pwd, ft_strlen(pwd));
}

void			ft_cd(char *s)
{
	static int		count;
	static char		cwd[256];
	char			tmp_cwd[256];
	char			tmp[256];

	getcwd(tmp, sizeof(tmp));
	if (count == 0)
		getcwd(cwd, sizeof(cwd));
	count++;
	if (ft_strcmp(s, "cd") == 0)
	{
		chdir(cwd);
		ft_pwd(0, "cd");
	}
	else if (chdir(&s[3]) != -1)
	{
		getcwd(tmp_cwd, sizeof(tmp_cwd));
		if (ft_strlen(tmp_cwd) >= ft_strlen(cwd))
		{
			ft_pwd(0, &s[3]);
		}
		else
			chdir(tmp);
	}
}

int				ft_read(int cs)
{
	char	buff[4096];
	int		ret;

	while ((ret = read(cs, buff, 4096)) > 0)
	{
		buff[ret] = '\0';
		if (ft_strcmp(buff, "quit") == 0)
			return (0);
		else if (ft_strcmp(buff, "ls") == 0)
			ft_ls(cs);
		else if (ft_strcmp(buff, "pwd") == 0)
			ft_pwd(cs, NULL);
		else if (ft_strncmp(buff, "cd", ft_strlen("cd")) == 0)
			ft_cd(buff);
	}
	return (0);
}

void			ft_ls(int cs)
{
	DIR				*dir;
	struct dirent	*play;
	char			buff[4096];

	dir = opendir(".");
	while ((play = readdir(dir)))
	{
		if (play->d_name[0] != '.')
		{
			ft_strcat(buff, play->d_name);
			ft_strcat(buff, " ");
		}
	}
	ft_strcat(buff, "\n");
	write(cs, buff, ft_strlen(buff));
	ft_strclr(buff);
	closedir(dir);
}
