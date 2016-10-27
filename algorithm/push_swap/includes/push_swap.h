/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 17:33:33 by mbougrin          #+#    #+#             */
/*   Updated: 2013/12/27 13:51:56 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct			s_list
{
	int					nb;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

typedef struct			s_struct
{
	int					ac_tmp;
	int					i;
	int					j;
	int					tmp_nb;
	int					tmp_nb1;
	struct s_list		*tmp_prev;
	struct s_list		*tmp_next;
	struct s_list		*tmp_prev1;
	struct s_list		*tmp_next1;
	t_list				*tmp;
	t_list				*alst_tmp;
	t_list				*alst_tmp1;
	t_list				*alst_1;
	t_list				*alst_2;
}						t_struct;

int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr(int n);
size_t				ft_strlen(const char *s);
void				check_alst(t_list **alst_1, t_list **alst_2, int i);
void				ft_lstprint(t_list **alst);
t_list				*ft_lstnew(char *s);
void				ft_lstadd(t_list **alst, char *s);
void				ft_lstadd_next(t_list **alst, char *s);
void				lst_s(t_list **alst, char *s);
void				lst_r(t_list **alst, char *s);
void				lst_rr(t_list **alst, char *s);
void				lst_sa_sb(t_list **alst_1, t_list **alst_2);
void				lst_ra_rb(t_list **alst_1, t_list **alst_2);
void				lst_rra_rrb(t_list **alst_1, t_list **alst_2);
void				lst_pa(t_list **alst_1, t_list **alst_2);
void				lst_pb(t_list **alst_1, t_list **alst_2);
void				lst_pb_b(t_list **alst_1, t_list **alst_2);

#endif
