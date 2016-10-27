/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 22:41:12 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/29 05:14:18 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>
# include <limits.h>

typedef struct		s_lst
{
	int				nb;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

t_lst				*lst_add(void);
t_lst				*ft_create_lst(char **av, int ac);
void				ft_print_lst(t_lst *alst);
void				ft_pb(t_lst **alst);
void				ft_ra(t_lst **alst);
void				ft_rra(t_lst **alst);
t_lst				*ft_blst(t_lst *tmp);
int					ft_check_value(char **av);
int					ft_check_sort(t_lst *alst);
int					ft_check_ra(t_lst **alst, int nb);
int					ft_check_rra(t_lst **alst, int nb);
t_lst				*ft_check_order(t_lst *alst);
void				ft_check_one_pa(t_lst **alst);
void				ft_check_pa(t_lst **alst);
int					ft_check_min(t_lst *alst);
int					ft_check_dbl(char **av);
int					ft_check_number(char **av);
void				ft_pb(t_lst **alst);
void				ft_pa(t_lst **alst);
void				ft_sa(t_lst **alst);
void				ft_ra(t_lst **alst);
void				ft_rra(t_lst **alst);
void				ft_pb_next(t_lst **alst, t_lst *tmp, t_lst *blst);
void				ft_swap_sa(t_lst **alst);
void				ft_swap_rra_pb(t_lst **alst, int rra, int nb);
void				ft_swap_ra_pb(t_lst **alst, int ra, int nb);
void				ft_swap_pa(t_lst **alst);
long int			ft_atol(char *str);

#endif
