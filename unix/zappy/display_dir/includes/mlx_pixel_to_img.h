/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_to_img.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 23:46:46 by mblet             #+#    #+#             */
/*   Updated: 2014/06/22 23:46:46 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PIXEL_TO_IMG_H
# define MLX_PIXEL_TO_IMG_H

void	ft_mlx_put_pixel_to_img(t_display *d, int x, int y);
void	ft_mlx_dec_pixel_to_img(t_display *d, int x, int y);
void	ft_mlx_check_pixel_to_img(t_display *d, int x, int y, int bg_color);

#endif
