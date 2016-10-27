# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/03 19:45:00 by mblet             #+#    #+#              #
#    Updated: 2014/06/27 08:33:57 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT__DIR	=	./libft/
LIBFT__LIB	=	./libft/libft.a

CLIENT_DIR	=	./client_dir/
CLIENT_EXE	=	./client

SERVER_DIR	=	./server_dir/
SERVER_EXE	=	./serveur

DISPL__DIR	=	./display_dir/
DISPL__EXE	=	./display

.SILENT:

all:		$(LIBFT__LIB) $(CLIENT_EXE) $(SERVER_EXE) $(DISPL__EXE)
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ -/g`\033[0m\033[K"

libft:		$(LIBFT__LIB)

$(LIBFT__LIB):
	make -C $(LIBFT__DIR)

client:
	make -C $(CLIENT_DIR)

serveur:
	make -C $(SERVER_DIR)

display:
	make -C $(DISPL__DIR)

clean:
	make -C $(LIBFT__DIR) clean
	make -C $(CLIENT_DIR) clean
	make -C $(SERVER_DIR) clean
	make -C $(DISPL__DIR) clean

fclean:
	make -C $(LIBFT__DIR) fclean
	make -C $(CLIENT_DIR) fclean
	make -C $(SERVER_DIR) fclean
	make -C $(DISPL__DIR) fclean

re:			fclean all

debug:		CC = cc
debug:		FLAGS += --analyze
debug:		re

.PHONY:		fclean clean re libft serveur client display
