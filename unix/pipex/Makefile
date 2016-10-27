# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 11:29:48 by mbougrin          #+#    #+#              #
#    Updated: 2013/12/31 17:27:41 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex 
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -I includes
DIRSRC = src/
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)pipex.c \
		$(DIRSRC)ft_strsub.c \
		$(DIRSRC)ft_strlen.c \
		$(DIRSRC)ft_strcmp.c \
		$(DIRSRC)ft_strjoin.c \
		$(DIRSRC)ft_strcpy.c \
		$(DIRSRC)ft_strdup.c \
		$(DIRSRC)ft_memalloc.c \
		$(DIRSRC)ft_strdel.c \
		$(DIRSRC)ft_memdel.c \
		$(DIRSRC)ft_strchr.c \
		$(DIRSRC)ft_strstrdel.c \
		$(DIRSRC)ft_error.c \
		$(DIRSRC)ft_strsplit.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) 

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: re fclean clean all
