/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 14:11:02 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/18 18:19:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "../libft/includes/libft.h"
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>

# define TINY 42
# define SMALL 84

typedef struct		s_stc
{
	void			*s;
	size_t			size;
	size_t			len_mem;
	int				use;
	int				number;
}					t_stc;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem(void);
void				*alloc_mem(char *s);
void				*alloc_tiny(char *s, size_t size, void *free);
void				*alloc_small(char *s, size_t size, void *free);
void				*alloc_large(char *s, size_t size, void *free);
void				print_alloc_mem(void *ptr);
t_stc				*stock_tiny(t_stc *stc);

#endif
