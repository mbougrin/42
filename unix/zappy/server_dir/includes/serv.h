/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:00:45 by mbar              #+#    #+#             */
/*   Updated: 2014/06/27 07:57:20 by mbar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERV_H
# define SERV_H

# include <libft.h>
# include <sys/select.h>
# include <stdlib.h>
# include <time.h>

# define AFF_SERV			1

# define FD_FREE			0
# define FD_SERV			1
# define FD_CLIENT			2

# define BUF_SIZE			1024

# define XV(err,res,str)	(x_void(err,res,str,__FILE__))
# define X(err,res,str)		(x_int(err,res,str,__FILE__))
# define MAX(a,b)			((a > b) ? a: b)

# define QT_MAX				10

typedef struct s_env	t_env;
typedef int				(*t_fptr)(t_env *, int, char **);

typedef enum	e_dir
{
	N,
	E,
	S,
	O
}				t_dir;

typedef struct	s_case
{
	int			food;
	int			linemate;
	int			deraumere;
	int			sibur;
	int			mendiane;
	int			phiras;
	int			thystame;
}				t_case;

typedef struct	s_pl
{
	char		*team;
	int			pos_x;
	int			pos_y;
	int			food;
	int			linemate;
	int			deraumere;
	int			sibur;
	int			mendiane;
	int			phiras;
	int			thystame;
	t_dir		dir;
	int			lvl;
	int			die;
	clock_t		time_life;
	clock_t		time_block;
}				t_pl;

typedef struct	s_data
{
	int			size_x;
	int			size_y;
	int			max_client;
	int			nb_client;
	int			d_time;
	char		**teams;
	t_case		**map;
}				t_data;

typedef struct	s_fd
{
	int			type;
	void		(*fct_read)();
	void		(*fct_cmd)();
	void		(*fct_write)();
	char		buf_read[BUF_SIZE + 1];
	char		buf_write[BUF_SIZE + 1];
	char		buf_mem[BUF_SIZE + 1];
	t_pl		player;
}				t_fd;

struct			s_env
{
	t_fd		*fds;
	t_data		data;
	int			port;
	int			maxfd;
	int			max;
	int			r;
	fd_set		fd_read;
	fd_set		fd_write;
	t_fptr		opt_arg[6];
};

typedef int		(*t_cmd_reader)(t_env *, int);

void			init_env(t_env *e);
void			get_opt(t_env *e, int ac, char **av);
void			main_loop(t_env *e);
void			srv_create(t_env *e, int port);
void			srv_accept(t_env *e, int s);
void			client_read(t_env *e, int cs);
void			client_write(t_env *e, int cs);
void			clean_fd(t_fd *fd);
int				x_int(int err, int res, char *str, char *file);
void			*x_void(void *err, void *res, char *str, char *file);
void			init_fd(t_env *e);
void			do_select(t_env *e);
void			check_fd(t_env *e);

void			map_create(t_env *e);
void			client_cmd(t_env *e, int cs);
int				ft_cmd(t_env *e, int cs);
int				ft_opt_arg_p(t_env *e, int i, char **argv);
int				ft_opt_arg_x(t_env *e, int i, char **argv);
int				ft_opt_arg_y(t_env *e, int i, char **argv);
int				ft_opt_arg_n(t_env *e, int i, char **argv);
int				ft_opt_arg_c(t_env *e, int i, char **argv);
int				ft_opt_arg_t(t_env *e, int i, char **argv);
void			ft_creat_team(t_env *e, char *name);
int				count_cmd(char *s);
void			init_player(t_env *e, int cs);
int				team_exist(char **teams, char *team);
int				nb_joueur(t_env *e, int x, int y);
int				clt_incantation_1(t_env *e, int cs);
int				clt_incantation_2(t_env *e, int cs);
int				clt_incantation_3(t_env *e, int cs);
int				clt_incantation_4(t_env *e, int cs);
int				clt_incantation_5(t_env *e, int cs);
int				clt_incantation_6(t_env *e, int cs);
int				clt_incantation_7(t_env *e, int cs);
void			add_food_map(t_env *e);
void			send_to_graph(t_env *e, char *s);

int				graph_msz(t_env *e, int cs);
int				graph_mct(t_env *e, int cs);
int				graph_tna(t_env *e, int cs);
int				graph_ppos(t_env *e, int cs);
int				graph_sgt(t_env *e, int cs);
int				graph_sst(t_env *e, int cs);
int				graph_seg(t_env *e, int cs);

int				clt_avance(t_env *e, int cs);
int				clt_tourne(t_env *e, int cs);
int				clt_inventaire(t_env *e, int cs);
int				clt_mort(t_env *e, int cs);
int				clt_prend(t_env *e, int cs);
int				clt_pose(t_env *e, int cs);
int				clt_voir(t_env *e, int cs);
int				clt_incantation(t_env *e, int cs);

#endif
