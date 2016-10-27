# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/10 18:42:12 by mblet             #+#    #+#              #
#    Updated: 2014/06/23 05:21:33 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../display

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O3

LIB3D		=	-L/usr/X11/lib -lmlx -lXext -lX11

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

LIBFT_DIR	=	../libft/

LIBFT_LIB	=	../libft/libft.a

SRCBASE		=	\
				check_action_mouse.c										\
				check_if_in_menu.c											\
				connect.c													\
				creat_bg.c													\
				creat_entity.c												\
				creat_img_bg.c												\
				creat_map.c													\
				creat_menu_img.c											\
				creat_mlx.c													\
				creat_team.c												\
				display.c													\
				draw_menu_info.c											\
				get_seg.c													\
				ini_display.c												\
				load_button_stats.c											\
				load_entity_img.c											\
				load_food_img.c												\
				load_ground_img.c											\
				main.c														\
				menu.c														\
				mlx_expose.c												\
				mlx_hook.c													\
				mlx_pixel_to_img.c											\
				mlx_pixel_to_menu.c											\
				my_mlx_font.c												\
				opt_arg.c													\
				print_button_stats.c										\
				print_entity.c												\
				print_entity_map.c											\
				print_loot.c												\
				print_menu.c												\
				print_popup.c												\
				print_popup_menu.c											\
				print_square.c												\
				print_view_entity_list.c									\
				read_cmd_func.c												\
				start_cmd.c													\
				thread_hook.c												\
				thread_launch.c												\
				thread_loop.c												\
				thread_read.c												\
				thread_write.c												\
				xpm_file_to_img.c

INCBASE		=	\
				check_action_nouse.h										\
				check_if_in_menu.h											\
				connect.h													\
				creat_bg.h													\
				creat_entity.h												\
				creat_img_bg.h												\
				creat_map.h													\
				creat_menu.h												\
				creat_menu_img.h											\
				creat_mlx.h													\
				creat_team.h												\
				display.h													\
				draw_menu_info.h											\
				get_seg.h													\
				ini_display.h												\
				load_button_stats.h											\
				load_entity_img.h											\
				load_food_img.h												\
				load_ground_img.h											\
				menu.h														\
				mlx_expose.h												\
				mlx_hook.h													\
				mlx_pixel_to_img.h											\
				mlx_pixel_to_menu.h											\
				my_mlx_font.h												\
				opt_arg.h													\
				print_button_stats.h										\
				print_entity.h												\
				print_entity_map.h											\
				print_loot.h												\
				print_menu.h												\
				print_popup.h												\
				print_popup_menu.h											\
				print_square.h												\
				print_view_entity_list.h									\
				read_cmd_func.h												\
				start_cmd.h													\
				thread_hook.h												\
				thread_launch.h												\
				thread_loop.h												\
				thread_read.h												\
				thread_read2.h												\
				thread_write.h												\
				xpm_file_to_img.h

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

INCS		=	$(addprefix $(INCDIR), $(INCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:		$(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(LIB3D) -o $(NAME) $(OBJS) $(LIBFT_LIB)
	echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"

$(OBJS):	$(SRCS) $(INCS)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) plz wait ...\033[0m\033[K"
	mkdir -p $(OBJDIR)
	make -C $(LIBFT_DIR)
	(cd $(OBJDIR);															\
	$(CC) $(FLAGS) $(LIB3D) -c $(addprefix ../, $(SRCS))					\
	-I $(addprefix ../, $(LIBFT_DIR)/$(INCDIR))								\
	-I $(addprefix ../, $(INCDIR)))

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C $(LIBFT_DIR) clean
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C $(LIBFT_DIR) fclean
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124m🔘  FCLEAN $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

debug:		CC = cc
debug:		FLAGS += --analyze
debug:		re

.PHONY:		fclean clean re
