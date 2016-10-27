/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:22:44 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/23 17:31:52 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

typedef struct			s_lst
{
	int					number_ants;
	char				*room;
	struct s_lst		*next;
	struct s_lst		*prev;
}						t_lst;

typedef struct			s_stc
{
	char				**map;
	char				*start;
	char				*end;
	int					ants;
}						t_stc;

void			ft_print_map(char **map);
void			ft_print_lst(t_lst **alst);
void			ft_print_move_ants(t_lst *alst, int count);
void			ft_move_ants(t_stc *stc, t_lst *alst);
int				ft_check_lst_ants(t_lst *alst);
void			ft_lst_move_ants(t_lst **alst, int ants);
void			ft_lst_move(t_lst **alst);
int				ft_check_map(char **map);
int				ft_check_error(char **map);
int				ft_check_start(char **map);
int				ft_check_end(char **map);
int				ft_check_tube(char **map);
int				ft_map(char **map, char *start, char *end);
int				ft_check_access_room(char *next, char **map);
char			*ft_create_next(char *map, char *next);
char			*ft_create_end(char **map);
char			*ft_create_start(char **map);
char			*ft_create(char *s);
void			lst_add(t_lst **alst, char *room);
void			ft_lemin(char **map);
void			ft_lst_map(t_lst **alst, char **map, char *start, char *end);
t_lst			*lst_new(char *room);

#endif
