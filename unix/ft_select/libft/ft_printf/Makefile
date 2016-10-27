# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 12:54:35 by mbougrin          #+#    #+#              #
#    Updated: 2014/01/09 16:32:17 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
AR = ar rc
RM = rm
RANLIB = ranlib
CFLAGS = -Wall -Wextra -Werror -I includes/
OBJ = $(SRC:.c=.o)
DIRSRC = src/
SRC =	$(DIRSRC)ft_printf.c \
		$(DIRSRC)ft_putall.c \
		$(DIRSRC)ft_all.c \
		$(DIRSRC)ft_put_all.c \
		$(DIRSRC)putall.c \
		$(DIRSRC)ft_printf_b.c

all: $(NAME)

$(NAME): $(OBJ) 
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)
	@echo "."
	@echo "finished compilation"
	@echo "libftprintf.a"

%.o: %.c
	@echo ".\c"
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@$(RM) -f $(DIRSRC)ft_printf.o
	@$(RM) -f $(DIRSRC)$(OBJ)

fclean: clean
	@echo "fclean libftprintf.a"
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
