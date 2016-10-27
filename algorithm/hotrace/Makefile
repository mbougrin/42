#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scadoux <scadoux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 13:32:33 by scadoux           #+#    #+#              #
#    Updated: 2013/12/15 05:16:33 by mbougrin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = hotrace

CFLAGS = -Wall -Wextra -Werror

SRC = main.c hotrace.c ft_putendl.c ft_strchr.c ft_strjoin.c \
ft_strdup.c ft_strnew.c ft_strsub.c ft_strcmp.c \
ft_strlen.c get_next_line.c ft_strcpy.c ft_putchar.c \
ft_putstr.c lst_all.c ft_strncmp.c

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) $(SRC)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
