# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/19 22:40:41 by mbougrin          #+#    #+#              #
#    Updated: 2014/03/27 05:54:41 by mbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
CC = gcc
RM = rm -f
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g -I includes
LFLAGS = -L /usr/lib/ -ltermcap
DIRSRC = src/
OBJ = $(SRC:.c=.o)
SRC = 	$(DIRSRC)forty_two_sh.c \
		$(DIRSRC)ft_forty_two_sh.c \
		$(DIRSRC)ft_envp.c \
		$(DIRSRC)ft_getenv.c \
		$(DIRSRC)ft_setenv.c \
		$(DIRSRC)ft_unsetenv.c \
		$(DIRSRC)ft_prompt.c \
		$(DIRSRC)ft_tilde.c \
		$(DIRSRC)ft_builtin.c \
		$(DIRSRC)ft_hash_binary.c \
		$(DIRSRC)ft_hash.c \
		$(DIRSRC)ft_execve.c \
		$(DIRSRC)ft_launch_command.c \
		$(DIRSRC)ft_check_access_command.c \
		$(DIRSRC)ft_shellsplit.c \
		$(DIRSRC)ft_shell_split.c \
		$(DIRSRC)ft_env.c \
		$(DIRSRC)ft_change_directory.c \
		$(DIRSRC)ft_cd.c \
		$(DIRSRC)ft_echo.c \
		$(DIRSRC)ft_signal.c \
		$(DIRSRC)ft_quote.c \
		$(DIRSRC)ft_bquote.c \
		$(DIRSRC)ft_modify_bquote.c \
		$(DIRSRC)ft_shell_script.c \
		$(DIRSRC)ft_back_slash.c \
		$(DIRSRC)ft_logical_operators.c \
		$(DIRSRC)ft_higher.c \
		$(DIRSRC)ft_lower.c \
		$(DIRSRC)ft_redirection_operator.c \
		$(DIRSRC)ft_pipe.c \
		$(DIRSRC)ft_tempnam.c \
		$(DIRSRC)ft_hash_error.c \
		$(DIRSRC)main.c \
		$(DIRSRC)ft_exit.c \
		$(DIRSRC)ft_iputchar.c \
		$(DIRSRC)ft_free_tab.c \
		$(DIRSRC)ft_new_term.c \
		$(DIRSRC)ft_reset_term.c \
		$(DIRSRC)ft_list.c \
		$(DIRSRC)ft_init_prompt.c \
		$(DIRSRC)ft_key.c \
		$(DIRSRC)ft_actions.c \
		$(DIRSRC)ft_add_char.c \
		$(DIRSRC)ft_repos_cursor.c \
		$(DIRSRC)ft_up.c \
		$(DIRSRC)ft_down.c \
		$(DIRSRC)ft_end.c \
		$(DIRSRC)ft_home.c \
		$(DIRSRC)ft_left.c \
		$(DIRSRC)ft_right.c \
		$(DIRSRC)ft_ret.c \
		$(DIRSRC)ft_shift_l.c \
		$(DIRSRC)ft_shift_r.c \
		$(DIRSRC)ft_del.c

all: $(NAME)

$(NAME): $(OBJ)
	@rm -f hist.txt
	@rm -f tmp/envp.txt
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS) $(LIB)
	@echo "\033[31;31;1m=== Compilation 42sh\t\t\t\033[32;32;mDONE\033[32;32;0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[31;31;1m=== O file 42sh\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)
	@make -C libft/ clean

clean_no_libft:
	@echo "\033[31;31;1m=== O file 42sh\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(OBJ)

fclean: clean_no_libft
	@rm -f tmp/envp.txt
	@rm -f hist.txt
	@echo "\033[31;31;1m=== 42sh\t\t\t\t\033[34;34;mREMOVED"
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all 

.PHONY: re fclean clean all clean_no_libft
