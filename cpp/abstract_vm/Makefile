# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 10:07:41 by mbougrin          #+#    #+#              #
#    Updated: 2015/03/10 16:14:40 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract_vm
CC = g++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
DIRSRC = src/
OBJ = 	$(SRC:.c=.o)
SRC =   $(DIRSRC)main.cpp \
	    $(DIRSRC)Class_parse.cpp \
	    $(DIRSRC)Class_int8.cpp \
	    $(DIRSRC)Class_int16.cpp \
	    $(DIRSRC)Class_int32.cpp \
	    $(DIRSRC)Class_float.cpp \
	    $(DIRSRC)Class_double.cpp

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
