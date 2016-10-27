# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 18:37:08 by mbougrin          #+#    #+#              #
#    Updated: 2014/01/10 22:52:33 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CC = gcc
RM = rm
LIB = libft/libft.a
PRINTF_LIB = libft/ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L /usr/lib/ -ltermcap
INCLUDE = -I includes/
OBJ = $(SRC:.c=.o)
DIRSRC = src/
SRC = 	$(DIRSRC)ft_select.c \
		$(DIRSRC)lst_all.c \
		$(DIRSRC)lst_all_b.c \
		$(DIRSRC)ft_up.c \
		$(DIRSRC)ft_down.c \
		$(DIRSRC)select.c \
		$(DIRSRC)ft_space.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS) $(LIB) $(PRINTF_LIB)
	@echo "finished compilation"
	@echo "ft_select"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

clean:
	@$(RM) -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "fclean ft_select"
	@$(RM) -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: re fclean clean all
