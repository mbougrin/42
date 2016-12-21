# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 10:07:41 by mbougrin          #+#    #+#              #
#    Updated: 2016/12/21 16:17:11 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = taskmaster
CC = clang++
RM = rm -f
INC = includes
LIB = -pthread
CFLAGS = -Wall -Wextra -Werror -std=c++11
DIRSRC = src/
OBJ = 	$(SRC:.cpp=.o)
SRC =   $(DIRSRC)main.cpp \
	    $(DIRSRC)ClassSocket.cpp \
	    $(DIRSRC)ClassConfig.cpp \
	    $(DIRSRC)ClassProgram.cpp \
	    $(DIRSRC)Tintin_reporter.cpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -I $(INC) $(CFLAGS) 
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(INC) $(LIB)

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)

re: fclean all 

.PHONY: re fclean clean all
