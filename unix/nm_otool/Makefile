# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
#    Updated: 2014/04/27 20:58:12 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm 
NAME1 = ft_otool
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
DIRSRC = src/
OBJ = 	$(DIRSRC)ft_nm.o \
		$(DIRSRC)nm.o \
		$(DIRSRC)ft_error.o
OBJ1 = 	$(DIRSRC)ft_otool.o \
		$(DIRSRC)ft_otool_64.o \
		$(DIRSRC)ft_error.o \
		$(DIRSRC)otool.o
SRC = 	$(DIRSRC)ft_nm.c \
		$(DIRSRC)ft_error.c \
		$(DIRSRC)ft_otool.c \
		$(DIRSRC)ft_otool_64.c \
		$(DIRSRC)nm.c.c \
		$(DIRSRC)otool.c

all: $(NAME)

$(NAME): $(OBJ) $(OBJ1)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@$(CC) -o $(NAME1) $(OBJ1) $(LIB)
	@echo "\033[31;31;1m=== Compilation ft_nm\t\t\t\033[32;32;mDONE\033[32;32;0m"
	@echo "\033[31;31;1m=== Compilation ft_otool\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file ft_nm\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== O file ft_otool\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@$(RM) $(OBJ1)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file ft_nm\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== O file ft_otool\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@$(RM) $(OBJ1)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== $(NAME1)\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME) $(NAME1) 
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
