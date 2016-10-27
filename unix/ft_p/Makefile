# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/14 12:03:24 by mbougrin          #+#    #+#              #
#    Updated: 2014/05/17 11:43:35 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serveur 
NAME1 = client
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -I includes
DIRSRC = src/
OBJ = 	$(DIRSRC)server.o \
		$(DIRSRC)ft_server.o
OBJ1 = 	$(DIRSRC)client.o 
SRC = 	$(DIRSRC)client.c \
		$(DIRSRC)server.c \
		$(DIRSRC)ft_server.c

all: $(NAME)

$(NAME): $(OBJ) $(OBJ1)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@$(CC) -o $(NAME1) $(OBJ1) $(LIB)
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\t\033[32;32;mDONE\033[32;32;0m"
	@echo "\033[31;31;1m=== Compilation $(NAME1)\t\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== O file $(NAME1)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@$(RM) $(OBJ1)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== O file $(NAME1)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@$(RM) $(OBJ1)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== $(NAME1)\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME) $(NAME1) 
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
