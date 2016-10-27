/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forty_two_sh.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:28:51 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/27 05:55:17 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORTY_TWO_SH_H
# define FORTY_TWO_SH_H

# include "../libft/includes/libft.h"

# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <dirent.h>

typedef struct		s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct	s_shell
{
	char		buff[10];
	int			pos;
	char		*str;
	t_list		*hist;
	char		**nenv;
}				t_shell;

typedef struct	s_tab
{
	char		*keycode;
	int			(*f)(t_shell *);
}				t_tab;

typedef enum	e_key
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	SHIFT_V,
	SHIFT_C,
	CTRL_R,
	TAB,
	HOME,
	END,
	SHIFT_L,
	SHIFT_R,
	DEL,
	RET,
	CTRL_D
}				t_key;

int				ft_cd_check(char *s);
int				ft_hash(char *cmd);
int				ft_builtin(char *s);
int				ft_strlen_space(char *s);
int				ft_check_space(char *line);
int				ft_check_path(char *path);
int				ft_execve(char *cmd, char **arg);
int				ft_check_access_command(char *line);
int				ft_launch_command(char *line);
int				ft_check_command_line(char *line);
int				ft_check_bquote(char *line);
int				ft_check_command_found(char *line);
int				ft_open_tmp(char *end);
char			ft_check_quote(char *s);
char			*ft_cmd_not_found(char *cmd);
char			*ft_cmd_permission_denied(char *cmd);
char			**ft_envp(char **envp, char *s);
char			*ft_getenv(char *s);
char			*ft_hash_binary(char *path, char *cmd);
char			**ft_shellsplit(char const *s, char c);
char			*ft_copy_str(char *s);
void			ft_remove_tmp(void);
void			ft_modify_bquote(char **line, char c);
void			ft_replace_tabulation(char **line);
void			ft_shelltrim(char **line);
void			ft_prompt(void);
void			ft_forty_two_sh(char *s);
void			ft_tilde(char **s);
void			ft_exit(int nb, char *s);
void			ft_hash_delete(int **hash, int len);
void			ft_env(char *s, char **split);
void			ft_setenv(char **split);
void			ft_unsetenv(char **split);
void			ft_echo(char **split);
void			ft_change_directory(char **split);
void			ft_signal(void);
void			ft_signal_pid(pid_t pid);
void			ft_quote(char **line, char c);
void			ft_shell_script(char **line);
void			ft_back_slash(char **line);
void			ft_logical_operators(char *line);
void			ft_replace_bquote(char **line);
void			ft_delete(void);
void			ft_redirection_operator(char *line);
void			ft_higher_higher(char *line);
void			ft_higher(char *line);
void			ft_lower(char *line);
void			ft_lower_lower(char *line);
void			ft_pipe(char *line);
void			ft_path_error(char *s, int i);
void			ft_modify_split(char **split, int n);
pid_t			ft_shell_pid(pid_t pid);

t_list			*ft_create_elem(char *str);
void			ft_list_push_back(t_list **root, char *str);
void			ft_list_push_front(t_list **root, char *str);
void			ft_free_tab(char **split);
int				ft_iputchar(int c);
void			ft_new_term(void);
void			ft_reset_term(void);
void			ft_init_prompt(t_shell *sh);
int				ft_key(t_shell *sh);
void			ft_add_char(t_shell *sh);
void			ft_repos_cursor(t_shell *sh);
int				ft_shift_l(t_shell *sh);
int				ft_shift_r(t_shell *sh);
int				ft_del(t_shell *sh);
int				ft_down(t_shell *sh);
int				ft_end(t_shell *sh);
int				ft_home(t_shell *sh);
int				ft_left(t_shell *sh);
int				ft_right(t_shell *sh);
int				ft_up(t_shell *sh);
int				ft_ret(t_shell *sh);
int				ft_shift_v(t_shell *sh);
int				ft_shift_c(t_shell *sh);
int				ft_ctrl_r(t_shell *sh);
int				ft_tab(t_shell *sh);
int				ft_ctrl_d(t_shell *sh);

#endif
