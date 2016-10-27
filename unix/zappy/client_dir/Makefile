# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/04 13:51:21 by mblet             #+#    #+#              #
#    Updated: 2014/06/27 01:15:37 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../client

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -g

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

LIBFT_DIR	=	../libft/

LIBFT_LIB	=	../libft/libft.a

SRCBASE		=	\
				main.c \
				ft_client.c \
				ft_len.c \
				ft_execve.c \
				ft_sock.c \
				f_sock.c \
				sock.c \
				ft_level.c \
				level.c \
				ft_strstrdel.c \
				ft_algo.c

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
