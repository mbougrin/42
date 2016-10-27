#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/04 18:52:52 by mbar              #+#    #+#              #
#    Updated: 2014/06/27 07:30:12 by mbar             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	../serveur

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O3

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

LIBFT_DIR	=	../libft/

LIBFT_LIB	=	../libft/libft.a

SRCBASE		=	\
				check_fd.c													\
				clean_fd.c													\
				client_cmd.c												\
				client_read.c												\
				client_write.c												\
				clt.c														\
				clt2.c														\
				clt3.c														\
				clt4.c														\
				clt5.c														\
				clt6.c														\
				count_cmd.c													\
				creat_team.c												\
				do_select.c													\
				ft_cmd.c													\
				get_opt.c													\
				graph.c														\
				graph2.c													\
				init_env.c													\
				init_fd.c													\
				init_player.c												\
				main.c														\
				main_loop.c													\
				map_create.c												\
				opt_arg.c													\
				opt_arg2.c													\
				srv_accept.c												\
				srv_create.c												\
				team_exist.c												\
				nb_joueur.c													\
				add_food.c												\
				send_to_graph.c												\
				x.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:		$(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJS) $(INCDIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)
	echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"

$(OBJS):	$(SRCS)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) plz wait ...\033[0m\033[K"
	mkdir -p $(OBJDIR)
	make -C $(LIBFT_DIR)
	(cd $(OBJDIR);															\
	$(CC) $(FLAGS) -c $(addprefix ../, $(SRCS))								\
	-I $(addprefix ../, $(LIBFT_DIR)/$(INCDIR))								\
	-I $(addprefix ../, $(INCDIR)))

clean:
	printf "\r\033[38;5;25m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C $(LIBFT_DIR) clean
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;25m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
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
