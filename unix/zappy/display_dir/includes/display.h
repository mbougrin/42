/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 08:38:37 by mblet             #+#    #+#             */
/*   Updated: 2014/06/27 08:38:42 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <pthread.h>

# include "my_mlx_font.h"

# define USAGE				"Usage : ./display -p <port> [-h <hostname>]"

# define IMG_ENTITY_LVL_1	"./display_dir/imgs/entity_lvl_1.xpm"
# define IMG_ENTITY_LVL_2	"./display_dir/imgs/entity_lvl_2.xpm"
# define IMG_ENTITY_LVL_3	"./display_dir/imgs/entity_lvl_3.xpm"
# define IMG_ENTITY_LVL_4	"./display_dir/imgs/entity_lvl_4.xpm"
# define IMG_ENTITY_LVL_5	"./display_dir/imgs/entity_lvl_5.xpm"
# define IMG_ENTITY_LVL_6	"./display_dir/imgs/entity_lvl_6.xpm"
# define IMG_ENTITY_LVL_7	"./display_dir/imgs/entity_lvl_7.xpm"
# define IMG_ENTITY_LVL_8	"./display_dir/imgs/entity_lvl_7.xpm"
# define IMG_GROUND			"./display_dir/imgs/ground.xpm"
# define IMG_LOOT			"./display_dir/imgs/loot.xpm"
# define IMG_BUTTON_STATS	"./display_dir/imgs/button_stats.xpm"
# define IMG_FONT_SMALL		"./display_dir/imgs/font_11.xpm"
# define IMG_FONT_BIG		"./display_dir/imgs/font_96.xpm"

# define COLOR_0			0x33FF00
# define COLOR_1			0x3498db
# define COLOR_2			0xFFFF00
# define COLOR_3			0xFF0000
# define COLOR_4			0xFF00FF
# define COLOR_5			0x720086
# define COLOR_6			0x
# define COLOR_7			0x
# define COLOR_8			0x
# define COLOR_9			0x
# define COLOR_10			0x
# define COLOR_11			0x
# define COLOR_12			0x
# define COLOR_13			0x
# define COLOR_14			0x
# define COLOR_15			0x
# define COLOR_16			0x
# define COLOR_17			0x
# define COLOR_18			0x
# define COLOR_19			0x
# define COLOR_20			0x
# define COLOR_21			0x
# define COLOR_22			0x
# define COLOR_23			0x
# define COLOR_24			0x
# define COLOR_25			0x
# define COLOR_26			0x
# define COLOR_27			0x
# define COLOR_28			0x
# define COLOR_29			0x

# define KEY_DELETE			0xFFFF
# define KEY_ESC			0xFF1B
# define KEY_PAD_ADD		0xFFAB
# define KEY_PAD_MINUS		0xFFAD

# define MOUSE_BUTTON_LEFT	1
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_UP	4

# define MAX_WIDTH			2560
# define MAX_HEIGHT			1395

# define MOVE_N				1
# define MOVE_E				2
# define MOVE_S				3
# define MOVE_W				4

typedef struct				s_ground_img
{
	int						w;
	int						h;
	void					*img_xpm;
	char					*ground_map;
	unsigned char			*addr;
	int						bpp;
	int						size;
	int						endian;
}							t_ground_img;

typedef struct				s_loot_img
{
	int						w;
	int						h;
	void					*img_xpm;
	unsigned char			*addr;
	int						bpp;
	int						size;
	int						endian;
}							t_loot_img;

typedef struct				s_menu_img
{
	int						w;
	int						h;
	void					*img;
	unsigned char			*addr;
	int						bpp;
	int						size;
	int						endian;
}							t_menu_img;

typedef struct				s_button_stats_img
{
	int						w;
	int						h;
	void					*img_xpm;
	unsigned char			*addr;
	int						bpp;
	int						size;
	int						endian;
}							t_button_stats_img;

typedef struct				s_entity_img
{
	int						w;
	int						h;
	void					*img_xpm[8];
	unsigned char			*addr[8];
	int						bpp[8];
	int						size[8];
	int						endian[8];
}							t_entity_img;

typedef struct				s_menu
{
	int						is_open;
	int						h;
	int						max;
	int						vertical_bar_y;
	int						vertical_bar_h;
	t_menu_img				*menu_img;
}							t_menu;

typedef struct				s_img
{
	t_entity_img			*entity_img;
	t_ground_img			*ground_img;
	t_loot_img				*loot_img;
	t_button_stats_img		*button_stats_img;
}							t_img;

typedef struct				s_popup
{
	int						x;
	int						y;
}							t_popup;

typedef struct				s_entity
{
	int						n;
	int						x;
	int						y;
	int						o;
	char					*t;
	int						lvl;
	int						anim;
	int						anim_2;
	int						color_team;
	int						loot[7];
}							t_entity;

typedef struct				s_case
{
	int						loot[7];
}							t_case;

typedef struct				s_map
{
	int						w;
	int						h;
	int						size_case;
	int						map_w;
	int						map_h;
	t_case					*map_case;
}							t_map;

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
	void					*img;
	void					*img2;
	void					*img3;
	unsigned char			*addr;
	unsigned char			*addr2;
	unsigned char			*addr3;
	int						bpp;
	int						size;
	unsigned char			*addr_t;
	int						bpp_t;
	int						sizeline_t;
	int						endian;
	int						color;
	int						color_d;
	int						x;
	int						y;
}							t_mlx;

typedef struct				s_connect
{
	char					*port;
	char					*hostname;
	int						sock;
}							t_connect;

typedef struct s_display	t_display;

typedef int					(*t_fptr)(t_display *, int, char **);
typedef int					(*t_read_cmd)(t_display *, char **);

struct						s_display
{
	t_connect				*connect;
	t_mlx					*mlx;
	t_img					*img;
	t_map					*map;
	t_popup					*popup;
	t_entity				**entity;
	t_font_img				*font_img_small;
	t_font_img				*font_img_big;
	t_menu					*menu;
	char					**team;
	char					*winner;
	unsigned int			fps;
	int						n;
	int						sgt;
	pthread_mutex_t			mutex_display;
	pthread_mutex_t			mutex_hook;
	t_fptr					opt_arg[2];
	t_read_cmd				read_cmd[7];
};

void						ft_display(int argc, char **argv);

#endif
