# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/02 10:49:38 by mbougrin          #+#    #+#              #
#    Updated: 2015/01/27 10:15:53 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
CC = nasm -f macho64
AR = ar rc
RANLIB = ranlib
RM = rm
DIRSRC = src/
OBJ = $(SRC:.s=.o)
SRC = ft_puts.s \
	  ft_bzero.s \
	  ft_isalpha.s \
	  ft_isdigit.s \
	  ft_isalnum.s \
	  ft_isascii.s \
	  ft_isprint.s \
	  ft_toupper.s \
	  ft_tolower.s \
	  ft_strcat.s \
	  ft_strlen.s \
	  ft_memset.s \
	  ft_memcpy.s \
	  ft_strdup.s \
	  ft_cat.s \
	  ft_strcmp.s \
	  ft_strncmp.s \
	  ft_putstr.s 

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\t\033[32;32;mDONE"

%.o: %.s
	@$(CC) $< -o $@

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\033[34;34;mREMOVED"
	@$(RM) -f $(OBJ)

clean_no_printf:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\033[34;34;mREMOVED"
	@$(RM) -f $(OBJ)

fclean: clean_no_printf
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) -f $(NAME)

re: fclean all 

.PHONY: re fclean clean all
