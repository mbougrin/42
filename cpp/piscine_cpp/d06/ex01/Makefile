# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 10:07:41 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/13 19:38:26 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize 
CC = g++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
DIRSRC = src/
OBJ = 	$(SRC:.c=.o)
SRC =   serialize.cpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) 
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean:
	@echo "\033[31;31;1m=== $(NAME)\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)

re: fclean all 

.PHONY: re fclean clean all
