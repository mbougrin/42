/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_four.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 19:37:59 by mbougrin          #+#    #+#             */
/*   Updated: 2014/03/09 18:40:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POWER_FOUR_H
# define FT_POWER_FOUR_H

# include "../libft/includes/libft.h"
# include <time.h>

void			ft_print_map(char **map, int column);
void			ft_game(char **map, int line);
void			ft_game_ia(char **map);
void			ft_game_player(char **map, int player);
int				ft_check_win(int player, char **map);
int				ft_check_play(char **map);

int				ft_check_column(char **map, char c);
int				ft_check_line(char **map, char c);
int				ft_check_diagonal_right(char **map, char c);
int				ft_check_diagonal_left(char **map, char c);
int				ft_map_error(void);
void			ft_game_ia(char **map);

#endif
