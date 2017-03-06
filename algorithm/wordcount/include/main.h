#ifndef MAIN_H
# define MAIN_H

//size to read for get_next_line
# define BUFF_SIZE 127
//size struct word
# define WORD_SIZE 300000

# include <stdbool.h>
//include malloc and free
# include <stdlib.h>
//include write and pointer NULL
# include <unistd.h>
//include open read and close
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//prototype tool.c
int		ft_strlen(const char *str);
void		ft_putendl(char *str);
void		ft_putstr(char *str);
void		ft_putchar(char c);
void		ft_putnbr(unsigned int n);
void		ft_strdel(char **as);
int		get_next_line(int fd, char **line);
int		find_char(const char *str, char c);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

typedef struct	s_stc
{
	char	*name;
	int	count;
}		t_stc;

t_stc	*g_stc[WORD_SIZE];

#endif
