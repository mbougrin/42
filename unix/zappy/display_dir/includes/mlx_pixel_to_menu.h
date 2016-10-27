/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_to_menu.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 09:29:01 by mblet             #+#    #+#             */
/*   Updated: 2014/06/26 09:29:01 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PIXEL_TO_MENU_H
# define MLX_PIXEL_TO_MENU_H

void	ft_put_pixel_to_menu(t_display *d, int x, int y);
void	ft_check_pixel_to_menu(t_display *d, int x, int y, int bg_color);
void	ft_check_pixel_to_menu_x_2(t_display *d, int x, int y, int bg_color);

#endif
