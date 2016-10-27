/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:02:51 by mbougrin          #+#    #+#             */
/*   Updated: 2014/06/27 06:19:49 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLT_H
# define CLT_H

# include <libft.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <dirent.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <poll.h>

typedef struct		s_see
{
	int				player;
	int				feed;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
}					t_see;

typedef struct		s_stc
{
	int				x;
	int				y;
	int				nb;
	char			*addr;
	int				port;
	char			*team;
	int				sock;
	int				start;
	int				move;
	int				level;
	int				find;
	int				view;
	int				feed;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
}					t_stc;

void				create_player(int ac, char **argv);
void				ft_execve(char *cmd, char **arg);

int					ft_create_client(char *addr, int port);
void				ft_see_next(t_see *see, int sock, char **split);

void				ft_strstrdel(char **as);

int					ft_strlen_space(char *s);
int					ft_strlen_backslash(char *s);
void				ft_read(int sock, t_stc *stc);
int					ft_write(int sock, t_stc *stc);
void				ft_client(t_stc *stc);

void				ft_algo(int sock, t_stc *stc);
int					ft_check_level_up(t_stc *stc);

void				ft_top(int sock);
void				ft_left(int sock);
void				ft_right(int sock);
void				ft_spell(int sock, t_stc *stc);
void				ft_expels(int sock);
void				ft_take(int sock, char *s);
void				ft_laying(int sock, char *s);
void				ft_broadcast(int sock, char *s);
void				ft_fork(int sock);
int					ft_see(int sock, t_stc *stc);
void				ft_inventory(int sock, t_stc *stc);

void				ft_inventory_reset(t_stc *stc);

int					ft_level_one(t_stc *stc);
int					ft_level_two(t_stc *stc);
int					ft_level_three(t_stc *stc);
int					ft_level_four(t_stc *stc);

#endif
