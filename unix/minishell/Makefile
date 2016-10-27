# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
#    Updated: 2014/02/09 12:31:44 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell3
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g -I includes
LFLAGS = -L /usr/lib/ -ltermcap
DIRSRC = src/
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)minishell.c \
		$(DIRSRC)ft_minishell.c \
		$(DIRSRC)ft_envp.c \
		$(DIRSRC)ft_cmd.c \
		$(DIRSRC)ft_check_cmd.c \
		$(DIRSRC)ft_change_directory.c \
		$(DIRSRC)ft_setenv.c \
		$(DIRSRC)ft_cd_error.c \
		$(DIRSRC)ft_higher.c \
		$(DIRSRC)ft_lower.c \
		$(DIRSRC)ft_tilde.c \
		$(DIRSRC)ft_split.c \
		$(DIRSRC)ft_signal_pid.c \
		$(DIRSRC)ft_tempnam.c \
		$(DIRSRC)ft_read.c \
		$(DIRSRC)ft_pipe.c \
		$(DIRSRC)ft_termcaps.c \
		$(DIRSRC)ft_move_termcaps.c \
		$(DIRSRC)ft_pos_cursor.c \
		$(DIRSRC)ft_open_termcaps.c \
		$(DIRSRC)ft_copy_cursor.c \
		$(DIRSRC)ft_signal.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS) $(LIB)
	@echo "\033[31;31;1m=== Compilation minishell3\t\t\033[32;32;mDONE"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file minishell3\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file minishell3\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@echo "\033[31;31;1m=== minishell3\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all
