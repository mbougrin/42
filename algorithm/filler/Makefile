# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/25 19:02:44 by mbougrin          #+#    #+#              #
#    Updated: 2014/01/26 09:04:47 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g -I includes
DIRSRC = src/
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)filler.c \
		$(DIRSRC)ft_filler.c \
		$(DIRSRC)ft_check.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[31;31;1m=== Compilation filler\t\t\t\033[32;32;mDONE"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file filler\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(DIRSRC)$(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file filler\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== filler\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all
