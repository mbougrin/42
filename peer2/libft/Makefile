# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/02 10:49:38 by mbougrin          #+#    #+#              #
#    Updated: 2015/02/05 00:22:42 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 
CC = gcc
AR = ar rc
RANLIB = ranlib
RM = rm
CFLAGS = -Wall -Wextra -Werror -I includes
DIRSRC = src/
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)ft_atoi.c \
		$(DIRSRC)ft_strlen.c \
		$(DIRSRC)ft_strdup.c \
		$(DIRSRC)ft_strcpy.c \
		$(DIRSRC)ft_strncpy.c \
		$(DIRSRC)ft_strcmp.c \
		$(DIRSRC)ft_strncat.c \
		$(DIRSRC)ft_strcat.c \
		$(DIRSRC)ft_strncmp.c \
		$(DIRSRC)ft_strstr.c \
		$(DIRSRC)ft_isalpha.c \
		$(DIRSRC)ft_isdigit.c \
		$(DIRSRC)ft_isalnum.c \
		$(DIRSRC)ft_isascii.c \
		$(DIRSRC)ft_isprint.c \
		$(DIRSRC)ft_strchr.c \
		$(DIRSRC)ft_strrchr.c \
		$(DIRSRC)ft_memset.c \
		$(DIRSRC)ft_tolower.c \
		$(DIRSRC)ft_toupper.c \
		$(DIRSRC)ft_bzero.c \
		$(DIRSRC)ft_memcpy.c \
		$(DIRSRC)ft_strnstr.c \
		$(DIRSRC)ft_memccpy.c \
		$(DIRSRC)ft_memmove.c \
		$(DIRSRC)ft_memcmp.c \
		$(DIRSRC)ft_memchr.c \
		$(DIRSRC)ft_strlcat.c \
		$(DIRSRC)ft_memalloc.c \
		$(DIRSRC)ft_memdel.c \
		$(DIRSRC)ft_strclr.c \
		$(DIRSRC)ft_strnew.c \
		$(DIRSRC)ft_strdel.c \
		$(DIRSRC)ft_putchar.c \
		$(DIRSRC)ft_putstr.c \
		$(DIRSRC)ft_putnbr.c \
		$(DIRSRC)ft_putchar_fd.c \
		$(DIRSRC)ft_putstr_fd.c \
		$(DIRSRC)ft_putnbr_fd.c \
		$(DIRSRC)ft_putendl.c \
		$(DIRSRC)ft_putendl_fd.c \
		$(DIRSRC)ft_itoa.c \
		$(DIRSRC)ft_striter.c \
		$(DIRSRC)ft_striteri.c \
		$(DIRSRC)ft_strmap.c \
		$(DIRSRC)ft_strmapi.c \
		$(DIRSRC)ft_strequ.c \
		$(DIRSRC)ft_strnequ.c \
		$(DIRSRC)ft_strsub.c \
		$(DIRSRC)ft_strjoin.c \
		$(DIRSRC)ft_strtrim.c \
		$(DIRSRC)ft_strsplit.c \
		$(DIRSRC)ft_lstnew.c \
		$(DIRSRC)ft_lstdel.c \
		$(DIRSRC)ft_lstdelone.c \
		$(DIRSRC)ft_lstiter.c \
		$(DIRSRC)ft_lstmap.c \
		$(DIRSRC)ft_lstadd.c \
		$(DIRSRC)ft_lstprint.c \
		$(DIRSRC)ft_lstdel_all.c \
		$(DIRSRC)ft_lstadd_end.c \
		$(DIRSRC)ft_strstrdel.c \
		$(DIRSRC)ft_strstrdup.c \
		$(DIRSRC)ft_strstrjoin.c \
		$(DIRSRC)ft_strstrlen.c \
		$(DIRSRC)ft_strstrnew.c \
		$(DIRSRC)get_next_line.c	

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)
	@echo "\033[31;31;1m=== Compilation libft.a\t\t\t\033[32;32;mDONE"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file libft.a\t\t\t\033[34;34;mREMOVED"
	@$(RM) -f $(OBJ)

fclean: clean
	@echo "\033[31;31;1m=== libft.a\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) -f $(NAME)

re: fclean all 

.PHONY: re fclean clean all
