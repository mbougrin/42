# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mblet <mblet@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 11:00:17 by mblet             #+#    #+#              #
#    Updated: 2014/06/03 22:22:48 by mblet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft

FLAG		=	-Wall -Wextra -Werror

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

SRCBASE		=	\
				atoi.c														\
				bzero.c														\
				error.c														\
				get_next_line.c												\
				isalnum.c													\
				isalpha.c													\
				isascii.c													\
				isdigit.c													\
				isprint.c													\
				itoa.c														\
				memalloc.c													\
				memccpy.c													\
				memchr.c													\
				memcmp.c													\
				memcpy.c													\
				memdel.c													\
				memmove.c													\
				memset.c													\
				putchar.c													\
				putchar_fd.c												\
				putendl.c													\
				putendl_fd.c												\
				putendlcolor.c												\
				putnbr.c													\
				putnbr_fd.c													\
				putstr.c													\
				putstr_fd.c													\
				putstrcolor.c												\
				strcat.c													\
				strchr.c													\
				strclr.c													\
				strcmp.c													\
				strcolor.c													\
				strcpy.c													\
				strdel.c													\
				strdup.c													\
				strequ.c													\
				stridel.c													\
				strijoin.c													\
				striter.c													\
				striteri.c													\
				strjoin.c													\
				strlcat.c													\
				strlen.c													\
				strlistdel.c												\
				strlistlen.c												\
				strmap.c													\
				strmapi.c													\
				strncat.c													\
				strncmp.c													\
				strncpy.c													\
				strnequ.c													\
				strnew.c													\
				strnstr.c													\
				strrchr.c													\
				strsplit.c													\
				strstr.c													\
				strsub.c													\
				strtrim.c													\
				tolower.c													\
				toupper.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:		$(NAME)

$(NAME):	$(OBJS)

$(OBJS):	$(SRCS)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAME) plz wait ...\033[0m\033[K"
	mkdir -p $(OBJDIR)
	(cd $(OBJDIR);															\
	gcc $(FLAG) -c $(addprefix ../, $(SRCS))								\
	-I $(addprefix ../, $(INCDIR)))
	ar rc $(NAME).a $(OBJS)
	ranlib $(NAME).a
	echo -en "\r\033[38;5;25m☑️  MAKE   $(NAME)\033[0m\033[K"

clean:
	printf "\r\033[38;5;25m⌛  CLEAN  $(NAME) plz wait ...\033[0m\033[K"
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAME)\033[0m\033[K";			\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;25m⌛  FCLEAN $(NAME) plz wait ...\033[0m\033[K"
	if [[ `rm $(NAME).a &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m🔘  FCLEAN $(NAME)\033[0m\033[K";			\
	else																	\
		printf "\r";														\
	fi

re:			fclean all

.PHONY: fclean clean re
