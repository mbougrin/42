/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 23:09:43 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/10 22:53:02 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <../libft/includes/libft.h>
# include <string.h>
# include <term.h>
# include <curses.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <sys/ioctl.h>

# define BUFFER_SIZE 2048

typedef struct		s_lst
{
	char			*data;
	int				select;
	int				cursor;
	int				loc_nb;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_tmp_lst
{
	t_lst			*tmp;
	t_lst			*alst_tmp;
}					t_tmp_lst;

int					t_putchar(int c);
int					ft_up(t_lst **alst, int i, int j);
int					ft_down(t_lst **alst, int i, int j);
int					ft_space(int i, int j, t_lst **alst);
int					ft_cursor_up(int i, t_lst **alst);
int					ft_lst_print(t_lst **alst);
int					t_putchar(int c);
int					ft_delete(t_lst **alst);
t_lst				*ft_lst_new(char *s);
t_lst				*ft_lst_del(t_lst **alst);
t_lst				*ft_sort_first(t_lst **alst);
void				ft_lst_add(t_lst **alst, char *s);
void				ft_lst_add_next(t_lst **alst, char *s);
void				ft_print_cursor(t_lst **alst);
void				ft_print_select(t_lst **alst);
void				ft_print_cursor_and_select(t_lst **alst);
void				ft_print_select_return(t_lst **alst);
void				ft_select(t_lst *alst, int i);

#endif
