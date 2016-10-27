/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 18:25:46 by mblet             #+#    #+#             */
/*   Updated: 2014/06/24 18:25:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ENTITY_H
# define PRINT_ENTITY_H

void	ft_print_entity_to_menu(t_display *d, int type, int lvl);
void	ft_print_text(t_display *d, int x, int y, t_entity *e);
int		ft_find_color_team(t_display *d, char *t);
void	ft_print_entity(t_display *d, int x, int y, t_entity *e);
void	ft_print_entity_run(t_display *d, int x, int y, t_entity *e);

#endif
