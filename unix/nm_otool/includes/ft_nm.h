/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 13:40:51 by mbougrin          #+#    #+#             */
/*   Updated: 2014/04/27 21:28:08 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

typedef	struct						s_stc
{
	char							*name;
	uint64_t						value;
	uint8_t							type;
	uint8_t							sect;
	int								nsyms;
}									t_stc;

typedef struct segment_command_64	t_sc_64;
typedef struct section_64			t_s64;

int									ft_arg_error(void);
int									ft_open_error(void);
int									ft_stat_error(void);
int									ft_mmap_error(void);
int									ft_munmap_error(void);
void								ft_sort(t_stc **stc, int nsyms);
void								ft_print_addr(int n, char *base);
char								ft_sym_char(t_stc *stc, struct \
									mach_header_64 *mh);
void								ft_check_mh_magic(char *ptr);
void								ft_handle_64(char *ptr);
void								ft_add_sym(int nsyms, int symoff, \
									int stroff, char *ptr);
void								ft_print_sym(t_stc *stc, struct \
									mach_header_64 *mh);
t_s64								*ft_getsect(struct mach_header_64 *mh, \
									uint32_t off, uint32_t i);

#endif
