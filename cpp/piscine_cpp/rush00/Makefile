# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 10:07:41 by mbougrin          #+#    #+#              #
#    Updated: 2015/04/12 03:03:29 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro
CC = g++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -lncurses
DIRSRC = src/
OBJ = 	$(SRC:.c=.o)
SRC =   $(DIRSRC)main.cpp \
		$(DIRSRC)Class_ncurse.cpp \
		$(DIRSRC)Player.cpp \
		$(DIRSRC)GameEntity.cpp \
		$(DIRSRC)Bullet.cpp \
		$(DIRSRC)Ennemy.cpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -I includes $(CFLAGS) 
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean:
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)

re: fclean all 

.PHONY: re fclean clean all
