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

NAME = libft_malloc.so 
CC = clang
RM = rm -f
CFLAGS = -I ./
DIRSRC = ./
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)malloc.c \
		$(DIRSRC)realloc.c \
		$(DIRSRC)free.c \
		$(DIRSRC)lst.c 

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -shared -o $(NAME) $(OBJ) 
	@echo "\033[31;31;1m=== Compilation malloc\t\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file malloc\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

clean_no_libft:
	@echo "\033[31;31;1m=== O file malloc\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME) libft_malloc_$(HOSTTYPE).so 

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
