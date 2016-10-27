/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 11:37:29 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/10 15:04:54 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <sys/types.h>
# include <pwd.h>

# define SIXMONTHS	15768000

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef	struct		s_flags
{
	int				a;
	int				t;
	int				r;
	int				l;
	int				gr;
}					t_flags;

typedef struct		s_lstc
{
	char			*prot;
	int				nb_link;
	char			*user;
	char			*group;
	int				size;
	char			*name;
	char			*time;
	int				uid;
	int				gid;
	int				itime;
	int				block;
	int				mode;
	char			path[1024];
}					t_lstc;

typedef struct		s_lst
{
	t_lstc			*lstc;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_stc
{
	int				total;
	int				ret;
	DIR				*dir;
	t_dirent		*dirent;
	t_stat			stt;
}					t_stc;

void				ft_print_l_time(char *time, int itime);
void				ft_ls(char *str, t_flags *flg);
t_flags				*ft_flags(char *str);
t_lst				*ft_lst_add(void);
void				ft_ls_not_found(char *str);
int					ft_ls_error(char *str, t_flags *flg);
char				*ft_prot(struct stat stt);
void				ft_print_l(t_lst *lst, t_flags *flg);
void				ft_print_lst(t_lst *lst, t_flags *flg);
t_lst				*ft_create_lst(char *str, t_flags *flg);
int					ft_create_lst_add(t_lst **lst, t_flags *flg, \
					struct dirent *dirent, char *str);
int					ft_create_l(t_lst **lst, t_flags *flg, \
					struct dirent *dirent, char *str);
int					ft_check_nb_link(t_lst *lst);
int					ft_check_name(t_lst *lst);
int					ft_check_group(t_lst *lst);
int					ft_check_size(t_lst *lst);
int					ft_check_nb_link_prev(t_lst *lst);
int					ft_check_name_prev(t_lst *lst);
int					ft_check_group_prev(t_lst *lst);
int					ft_check_size_prev(t_lst *lst);
void				ft_print_space(int nb, int tab, t_lst *lst, t_flags *flg);
int					ft_ret_space(t_lst *lst, int nb);
int					ft_ret_space_size(t_lst *lst);
int					ft_ret_space_link(t_lst *lst);
int					ft_create_space(t_lst *lst, int nb, t_flags *flg);
void				ft_parse(int ac, char **av);
void				ft_free(t_lst **lst, t_flags **flg);
void				ft_print_link(char *name, char *path);
void				ft_empty(void);
void				ft_add_loop_found(char **tab, int i, int *j, char **av);
int					ft_loop_not_found(char **av);
int					ft_print_not_found(char **tab);
int					ft_print_tab(char **tab);
void				ft_loop_empty(char **av);
void				ft_print_r(char *str, t_flags *flg);
void				ft_ls_perm(char *str);
void				ft_sort_time_r(t_lst **lst);
void				ft_sort_ascii_r(t_lst **lst);
void				ft_sort_time(t_lst **lst);
void				ft_sort_ascii(t_lst **lst);
int					ft_check_point(char *name);
t_lst				*ft_return_lst(t_lst *new, t_lst *lst, t_flags *flg);
void				ft_print_total_r(t_lst *lst);
char				**ft_swap_folder(char **tab);
int					ft_check_value(char **tab);
char				**ft_sort_tab_time(char **tab);
char				**ft_reverse_tab(char **tab);
void				ft_free_parse(char **tab, t_flags *flg, int res, int len);
int					ft_check_nb(char *str);
void				ft_loop_parse(char **tab, t_flags *flg, int res, int len);
void				ft_print_single(char *str, t_flags *flg);
void				ft_print_single_l(t_stc stc);
int					ft_check_ln(char *str, t_flags *flg);
void				ft_cpy_path(t_lst **lst, char *str, char *ptr);

#endif
