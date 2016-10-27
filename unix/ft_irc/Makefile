# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/14 12:03:24 by mbougrin          #+#    #+#              #
#    Updated: 2014/05/23 17:30:03 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serveur 
NAME1 = client
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -I includes
DIRSRC = src/
OBJ = 	$(DIRSRC)check_fd.o \
		$(DIRSRC)clean_fd.o \
		$(DIRSRC)client_read.o \
		$(DIRSRC)client_write.o \
		$(DIRSRC)do_select.o \
		$(DIRSRC)get_opt.o \
		$(DIRSRC)init_env.o \
		$(DIRSRC)init_fd.o \
		$(DIRSRC)main.o \
		$(DIRSRC)main_loop.o \
		$(DIRSRC)srv_accept.o \
		$(DIRSRC)srv_create.o \
		$(DIRSRC)x.o
OBJ1 = 	$(DIRSRC)client.o 
SRC = 	$(DIRSRC)client.c \
		$(DIRSRC)clean_fd.c \
		$(DIRSRC)client_read.c \
		$(DIRSRC)client_write.c \
		$(DIRSRC)do_select.c \
		$(DIRSRC)get_opt.c \
		$(DIRSRC)init_env.c \
		$(DIRSRC)init_fd.c \
		$(DIRSRC)main.c \
		$(DIRSRC)main_loop.c \
		$(DIRSRC)srv_accept.c \
		$(DIRSRC)srv_create.c \
		$(DIRSRC)x.c

all: $(NAME)

$(NAME): $(OBJ) $(OBJ1)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@$(CC) -o $(NAME1) $(OBJ1) $(LIB)
	@echo "\033[31;31;1m=== Compilation $(NAME)\t\t\033[32;32;mDONE\033[32;32;0m"
	@echo "\033[31;31;1m=== Compilation $(NAME1)\t\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== O file $(NAME1)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@$(RM) $(OBJ1)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file $(NAME)\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== O file $(NAME1)\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@$(RM) $(OBJ1)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== $(NAME)\t\t\t\t\033[34;34;mREMOVED"
	@echo "\033[31;31;1m=== $(NAME1)\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME) $(NAME1) 
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
