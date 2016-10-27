/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_file_to_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 23:05:48 by mblet             #+#    #+#             */
/*   Updated: 2014/06/23 11:54:24 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "load_entity_img.h"
#include "load_ground_img.h"
#include "load_food_img.h"
#include "load_button_stats.h"
#include "creat_menu_img.h"

void	ft_xpm_file_to_img(t_display *d)
{
	ft_load_entity_img(d);
	ft_load_ground_img(d);
	ft_load_loot_img(d);
	ft_load_button_stats_img(d);
	ft_creat_menu_img(d);
}
