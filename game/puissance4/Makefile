# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
#    Updated: 2014/03/09 17:06:20 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -I includes
DIRSRC = src/
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)ft_power_four.c \
		$(DIRSRC)ft_game.c \
		$(DIRSRC)ft_artificial_intelligence.c \
		$(DIRSRC)ft_check_win.c \
		$(DIRSRC)ft_game_ia.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[31;31;1m=== Compilation puissance4\t\t\033[32;32;mDONE"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file puissance4\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file puissance4\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== puissance4\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
