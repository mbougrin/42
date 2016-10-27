/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 11:30:37 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/31 18:56:56 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char			*ft_check_path(char **envp, char *s)
{
	t_struc		*pp;

	pp = (t_struc *)malloc(sizeof(t_struc));
	pp->i = 0;
	pp->s_path = ft_strsplit(ft_strsub(envp[0], 5, ft_strlen(envp[0])), ':');
	while (pp->s_path[pp->i] != NULL)
	{
		pp->tmp = ft_strjoin(pp->s_path[pp->i], ft_strjoin("/", s));
		if (access(pp->tmp, F_OK) == 0)
			return (pp->tmp);
		pp->i++;
	}
	free(pp);
	return (NULL);
}

static void			ft_child(char **av, char **envp, int *tab_fd)
{
	t_struc		*pp;

	pp = (t_struc *)malloc(sizeof(t_struc));
	if ((pp->fd = open(av[1], O_RDONLY)) == -1)
	{
		write(2, "pipe failed\n", 12);
		_exit(-1);
	}
	pp->s_av = ft_strsplit(av[2], ' ');
	if ((pp->tmp = ft_check_path(envp, pp->s_av[0])) == NULL)
		ft_cmd_error(pp->str);
	close(tab_fd[0]);
	dup2(pp->fd, 0);
	dup2(tab_fd[1], 1);
	execve(pp->tmp, pp->s_av, envp);
}

static void			ft_father(char **av, char **envp, int *tab_fd)
{
	t_struc		*pp;

	pp = (t_struc *)malloc(sizeof(t_struc));
	pp->fd1 = open(av[4], O_WRONLY | O_RDONLY | O_CREAT | O_TRUNC, 0644);
	if (pp->fd1 == -1)
	{
		write(2, "pipe failed\n", 12);
		_exit(-1);
	}
	pp->s_av1 = ft_strsplit(av[3], ' ');
	if ((pp->tmp1 = ft_check_path(envp, pp->s_av1[0])) == NULL) 
		ft_cmd_error(pp->str1);
	close(tab_fd[1]);
	dup2(pp->fd1, 1);
	dup2(tab_fd[0], 0);
	execve(pp->tmp1, pp->s_av1, envp);
}

static void			pipex(char **av, char **envp)
{
	t_struc		*pp;
	int			tab_fd[2];

	ft_check_file(av[1], envp);
	ft_check_file2(av[4], envp);
	pp = (t_struc *)malloc(sizeof(t_struc));
	if ((pp->error = pipe(tab_fd)) == -1)
		ft_pipe_error();
	if ((pp->f_nb = fork()) < 0)
		ft_fork_error();
	if (pp->f_nb > 0)
	{
		wait(NULL);
		ft_father(av, envp, tab_fd);
	}
	if (pp->f_nb == 0)
		ft_child(av, envp, tab_fd);
}

int					main(int ac, char **av, char **envp)
{
	if (ac > 5)
		write(2, "too many arguments\n", 19);
	else if (ac < 5)
		write(2, "too few arguments\n", 18);
	else if (ft_strcmp(av[2], "") == 0 || ft_strcmp(av[3], "") == 0 \
			|| ft_strcmp(av[2], " ") == 0 || ft_strcmp(av[3], " ") == 0)
	{
		write(2, "argv command failed\n", 20);
		_exit(-1);
	}
	else if (envp[0] == NULL)
	{
		write(2, "envp failed\n", 12);
		_exit(-1);
	}
	else
		pipex(av, envp);
	return (0);
}
