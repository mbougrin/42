/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 19:03:29 by mbougrin          #+#    #+#             */
/*   Updated: 2014/01/26 09:05:54 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct		s_filler
{
	int				x_map;
	int				y_map;
	int				x_piece;
	int				y_piece;
	int				x_coor;
	int				y_coor;
	int				player;
	int				i;
	int				j;
	int				ok;
	int				pos;
	char			*line;
	char			**map;
	char			**split;
	char			**piece;
	char			c;
	char			b;
}					t_filler;

void			ft_play(t_filler *stc);
void			ft_player(t_filler *stc);
void			ft_creat_map(t_filler *stc);
void			ft_creat_coor(t_filler *stc);
void			ft_creat_piece(t_filler *stc);
int				ft_check_valid(char c, char b);
void			ft_check_coor_end(t_filler *stc);
int				ft_check_pos_piece(t_filler *stc);
void			ft_check_coor_first(t_filler *stc);

#endif
