# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
##   Updated: 2014/11/02 03:11:35 by mbougrin         ###   ########.fr       ##
#                                                                              #
# **************************************************************************** #

NAME = arkanoid 
CC = gcc
RM = rm -f
LIB = libft/libft.a 
LIB1 = glfw/src/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
INC = -I include -I libft/includes -I glfw/include/
CFLAGS = -Wall -Wextra -Werror
DIRSRC = src/
OBJ = 	$(SRC:.c=.o)
SRC = 	$(DIRSRC)main.c \
		$(DIRSRC)ft_check_col.c \
		$(DIRSRC)ft_print_rect.c \
		$(DIRSRC)gener_block.c \

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB) $(INC) $(LIB1)
	@echo "\033[31;31;1m=== Compilation $(NAME)\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	    @git submodule init
		@git submodule update
			@cd glfw; cmake .; make; cd ..
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file $(NAME)\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
