/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 11:31:30 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/31 18:55:19 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_struc
{
	pid_t			f_nb;
	int				i;
	int				fd;
	int				fd1;
	int				error;
	char			*tmp;
	char			*tmp1;
	char			*str;
	char			*str1;
	char			**s_av;
	char			**s_av1;
	char			**s_path;
}					t_struc;

int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_strstrdel(char ***ass);
void			ft_cmd_error(char *s);
void			ft_check_file(char *s, char **envp);
void			ft_fork_error(void);
void			ft_pipe_error(void);
void			ft_check_file2(char *s, char **envp);

#endif
