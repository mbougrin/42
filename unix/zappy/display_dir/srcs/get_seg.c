/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_seg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 07:26:01 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 07:55:55 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "display.h"
#include "my_mlx_font.h"

void		ft_get_seg(t_display *d)
{
	char	*tmp;

	if (d->winner != NULL)
	{
		tmp = ft_strjoin("The WINNER is :\n", d->winner);
		ft_mlx_font(d->font_img_big, MAX_WIDTH / 2 - 400,
				MAX_HEIGHT / 2 - 201, 0x000000, tmp,
				d->mlx->addr, d->mlx->bpp, d->mlx->size);
		ft_mlx_font(d->font_img_big, MAX_WIDTH / 2 - 401,
				MAX_HEIGHT / 2 - 200, 0x00FF00, tmp,
				d->mlx->addr, d->mlx->bpp, d->mlx->size);
		ft_strdel(&tmp);
	}
}
