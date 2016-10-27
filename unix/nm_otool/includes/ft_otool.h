/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 13:41:35 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/27 21:35:14 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

typedef struct section_64			t_stc_64;
typedef struct mach_header_64		t_header;
typedef struct segment_command_64	t_sc_64;
typedef struct stat					t_stat;

int									ft_arg_error(void);
int									ft_open_error(void);
int									ft_stat_error(void);
int									ft_mmap_error(void);
int									ft_munmap_error(void);
char								ft_base(int n);
void								ft_print_hexa(int c);
void								ft_print_addr(int n, char *base);
void								magic_number(char *ptr);
void								ft_print(struct section_64 *ft_seg_64, \
									char *ptr);
t_stc_64							*ft_segment_64(char *ptr, char *segname, \
									char *sectname);
t_stc_64							*ft_seg_64(char *segname, char *sectname, \
									struct mach_header_64 *header, \
									unsigned int i);
t_stc_64							*ft_seg64(char *sectname, char *segname, \
									t_stc_64 *s_64, t_sc_64 *sc_64);

#endif
