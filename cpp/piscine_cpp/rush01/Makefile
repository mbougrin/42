#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 10:29:42 by mbar              #+#    #+#              #
#    Updated: 2015/04/19 04:02:24 by mbougrin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_gkrellm
DST = src/
SDL = lib/libSDL2.dylib lib/libSDL2_ttf.dylib lib/libSDL2_image.dylib
SRC = 	$(DST)main.cpp \
		$(DST)IMonitorModule.cpp \
		$(DST)IMonitorDisplay.cpp \
		$(DST)NameModule.cpp \
		$(DST)InfoModule.cpp \
		$(DST)TimeModule.cpp \
		$(DST)Class_ram.cpp \
		$(DST)Class_sdl.cpp \
		$(DST)Class_network.cpp \
		$(DST)Class_cpu.cpp \
		$(DST)GraphSDL.cpp \
		$(DST)GraphNcurses.cpp

CFLAGS = -Wall -Wextra -Werror -I include

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@g++ -o $(NAME) $(OBJ) $(CFLAGS) $(SDL) -lncurses

%.o: %.cpp
		g++ -o $@ $(CFLAGS) -c $<

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
