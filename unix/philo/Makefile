#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 12:22:51 by mbar              #+#    #+#              #
#    Updated: 2014/05/11 18:41:11 by mbougrin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo

LIB = libft.a

LIBDIR = libft

SRC = main.c \
	  ft_print_philo.c \
	  print_philo.c \
	  thread.c \
	  mlx.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(LIBDIR)/$(LIB) $(NAME)

$(LIBDIR)/$(LIB):
		make -C $(LIBDIR)

$(NAME): $(OBJ)
		@gcc -o $(NAME) $(OBJ) $(CFLAGS) -I./$(LIBDIR) -L./$(LIBDIR) -lft -L/usr/X11/lib -lmlx -lXext -lX11

%.o: %.c
		gcc $(CFLAGS) -c $^ -I./$(LIBDIR)

clean:
		@make clean -C $(LIBDIR)
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C $(LIBDIR)
		@rm -f $(NAME)

re: fclean all
