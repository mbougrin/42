DOSSIER = .
SOURCES = $(DOSSIER)/main_SDL_test.c
OBJETS = $(SOURCES:.c=.o)

GCC = gcc 
#GCC = gcc -Wall -Wextra -Werror 
#GCC = gcc -Wall -Wextra -Werror -g 
INCLUDES_SDL = -I /usr/local/include/SDL/ 
LINKS_SDL = -L.usr/local/lib/ -lSDL -lSDLmain 

BIN = test_SDL 

EFFACER_LIGNE = @echo "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"

.PHONY: $(BIN) all clean fclean re

all: $(BIN)

$(BIN): $(OBJETS)
	@$(GCC) -o $@ $^ $(INCLUDES_SDL) $(LINKS_SDL)
	@echo $@ ": \033[0;32mOK\033[0m"

%.o: %.c
	@echo "génération de" $@
	@$(GCC) -o $@ -c $< $(INCLUDES_SDL) $(LINKS_SDL)

clean:
	@echo "suppression de \033[0;31m" $(OBJETS) "\033[0m"
	@rm -f $(OBJETS)

fclean: clean
	@echo "suppression de \033[0;31m" $(BIN) "\033[0m"
	@rm -f $(BIN)

re: fclean all
