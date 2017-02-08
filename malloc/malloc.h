#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>

# define UNUSED 0
# define USED   1


typedef struct 		s_lst
{
	size_t		size;
	void		*addr;
	int		used;
	struct s_lst	*next;
}			t_lst;

void    		*malloc(size_t size);
void			printmalloc(void);
void			lstadd(size_t size, void *addr);
void			*findunused(size_t size);
void			free(void *ptr);
void			*realloc(void *ptr, size_t size);

#endif
