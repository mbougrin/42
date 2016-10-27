# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
#    Updated: 2014/03/23 17:32:16 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g -I includes
DIRSRC = src/
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)lemin.c \
		$(DIRSRC)main.c \
		$(DIRSRC)ft_check_error.c \
		$(DIRSRC)ft_error.c \
		$(DIRSRC)ft_print.c \
		$(DIRSRC)ft_create.c \
		$(DIRSRC)ft_lst.c

all: $(NAME)

$(NAME): $(OBJ)
	@rm -f tmp/envp.txt
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[31;31;1m=== Compilation lem-in\t\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file lem-in\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file lem-in\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== lem-in\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
