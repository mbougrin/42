# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 12:54:35 by mbougrin          #+#    #+#              #
#    Updated: 2014/01/26 06:15:17 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
AR = ar rc
RANLIB = ranlib
CFLAGS = -Wall -Wextra -Werror -I includes
DIRSRC = src/
SRC = $(DIRSRC)ft_printf.c \
	  $(DIRSRC)ft_putall.c \
	  $(DIRSRC)ft_all.c \
	  $(DIRSRC)ft_put_all.c \
	  $(DIRSRC)putall.c \
	  $(DIRSRC)ft_printf_b.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)
	@echo "\033[31;31;1m=== Compilation libftprintf.a\t\t\033[32;32;mDONE"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file libftprintf.a\t\t\033[34;34;mREMOVED"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[31;31;1m=== libftprintf.a\t\t\t\033[34;34;mREMOVED"
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
