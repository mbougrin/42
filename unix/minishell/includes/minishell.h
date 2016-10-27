/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:48:24 by mbougrin          #+#    #+#             */
/*   Updated: 2014/02/12 08:53:53 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <stdio.h>

# include <sys/ioctl.h>

void			ft_prompt(char **envp);
void			ft_exit(int nb);
void			ft_envp(char **slipt, char **envp);
void			ft_minishell(char **envp);
void			ft_signal(char **envp);
void			ft_signal_pid(pid_t pid);
void			ft_control_d(struct termios term);
void			ft_exit_split_nb(char **split);
void			ft_check_cmd(char **split, char **envp);
void			ft_unsetenv(const char *name, char **envp);
void			ft_cd_error(char *cmd, int nb);
char			**ft_change_directory(char **split, char **envp);
char			**ft_strsplit_minishell(char const *s, char c);
char			**ft_setenv(const char *name, const char *value, char **envp);
char			*ft_getenv(char *s, char **envp);
int				ft_check_setenv(const char *name, char **envp);
void			ft_execve_cmd(char *cmd, char **split, char **envp);
void			ft_higher(char **envp, char **split);
void			ft_higher_higher(char **envp, char **split);
void			ft_lower(char **envp, char **split);
void			ft_lower_lower(char **envp, char **split);
int				ft_check_access_cmd(char **envp, char **split);
char			**ft_tilde(char **envp, char **split);
int				ft_open_tmp(char *end);
void			ft_remove_tmp(char **envp);
void			ft_read_lower_lower(char **split);
void			ft_read_lower(int fd);
void			ft_cmd_pipe(char **envp, char **split);
char			*ft_termcaps(void);
void			ft_move_left(int nb);
void			ft_move_right(int nb);
int				t_putchar(int c);
int				ft_delete(char **line);
void			ft_end_termcaps(struct termios term);
void			ft_open_termcaps(struct termios term);
int				ft_pos_cursor(char *s);
void			ft_check_move_left(int nb);
void			ft_check_move_right(int nb);
void			ft_check_end(int nb);
void			ft_copy_pos_cursor(char **line, char c);
void			ft_copy_cursor_end(char **line, char c);

#endif
