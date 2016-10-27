# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
#    Updated: 2014/04/20 17:32:31 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so 
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g -I includes
DIRSRC = src/
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)malloc.c \
		$(DIRSRC)show_alloc_mem.c \
		$(DIRSRC)alloc.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -shared -o $(NAME) $(OBJ) $(LIB)
	@ln -s $(NAME) libft_malloc_$(HOSTTYPE).so 
	@echo "\033[31;31;1m=== Compilation malloc\t\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file malloc\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file malloc\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME) libft_malloc_$(HOSTTYPE).so 
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
