# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                   =i>              +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 10:07:41 by mbougrin          #+#    #+#              #
#    Updated: 2015/04/06 09:26:35 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook 
CC = g++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I includes
DIRSRC = src/
OBJ = 	$(SRC:.c=.o)
SRC =   Class_phonebook.cpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 
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
