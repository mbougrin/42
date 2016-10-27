/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 11:01:21 by scadoux           #+#    #+#             */
/*   Updated: 2013/12/15 04:09:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define BUFF_SIZE 1

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_data
{
	char			*k_word;
	char			*value;
	struct s_data  	*next;
}					t_data;

typedef struct		s_struct
{
	t_data			*alst;
	char			*k_word;
	char			*value;
	char			*str;
	char			*buff;
	char			*ptr;
	char			*tmp;
	int				ret;
	int				i;
	int				j;
	int				len;
}					t_struct;

t_data		*lst_new(char *k_word, char *value);

void		ft_bzero(void *s, size_t n);
void		ft_putendl(char const *s);
void		hotrace(void);
void		ft_putchar(char c);
void		ft_putstr(char const *str);
void		lst_print(t_data **alst);
void		lst_add(t_data **alst, char *k_word, char *value);
void		print_list(t_data **t_data);

char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_strnew(size_t size);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		ft_strcpy(char *s1, const char *s2);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);

#endif /* !HOTRACE_H */
