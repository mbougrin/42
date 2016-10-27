# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
##   Updated: 2014/11/02 03:11:35 by mbougrin         ###   ########.fr       ##
#                                                                              #
# **************************************************************************** #

NAME = game_2048 
CC = gcc
RM = rm -f
LIB = libft/libft.a -lncurses
INC = -I includes -I libft/includes
CFLAGS = -g -Wall -Wextra -Werror
DIRSRC = src/
OBJ = 	$(SRC:.c=.o)
SRC = 	$(DIRSRC)main.c \
		$(DIRSRC)ft_ncurses.c \
		$(DIRSRC)addelem.c \
		$(DIRSRC)defeat.c \
		$(DIRSRC)freegrid.c \
		$(DIRSRC)initgrid.c \
		$(DIRSRC)movedown.c	\
		$(DIRSRC)moveleft.c	\
		$(DIRSRC)moverigth.c \
		$(DIRSRC)ft_init_ncurses.c \
		$(DIRSRC)ft_loop.c \
		$(DIRSRC)ft_check.c \
		$(DIRSRC)moveup.c \
		$(DIRSRC)victory.c \
		$(DIRSRC)score.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB) $(INC)
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file $(NAME)\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
