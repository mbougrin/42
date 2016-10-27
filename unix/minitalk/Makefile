# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/02/07 19:35:17 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Werror -Wextra
SRC_CLIENT= main.c \
	 		client.c

SRC_SERVER= server.c \
			get_signal.c \
			get_client_pid.c

OBJ_CLIENT= $(SRC_CLIENT:.c=.o)
OBJ_SERVER= $(SRC_SERVER:.c=.o)
NAME_CLIENT= client
NAME_SERVER= server
DIR_LFT= ./libft

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) 
	@(cd libft ; make)
	$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) -L$(DIR_LFT) -lft
$(NAME_SERVER): $(OBJ_SERVER)
	@(cd libft ; make)
	$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) -L$(DIR_LFT) -lft


%.o: %.c
	$(CC) -c $(CFLAGS) $< -I./ -I./libft

clean:
	@(cd libft ; make clean)
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	@(cd libft ; make fclean)
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: clean fclean re all
