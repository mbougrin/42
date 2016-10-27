
#include <string>
#include <iostream>
#include <queue>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include <SDL.h>
#include "GraphSDL.hpp"

int main()
{
	srand(time(0));
	srand48(time(0));

	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
	
	SDL_Window * window = SDL_CreateWindow("Titre", 0, 0, 640, 480, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Surface * screen = SDL_GetWindowSurface(window);

	GraphSDL<int>	prc(screen, renderer, 5, 0, 100);
	GraphSDL<float>	dbl(screen, renderer, 10, 0.f, 1.f);

	dbl.mutPos(200, 200);
	dbl.mutTaille(222, 222);

	int compteur = 0;
	while (1)
	{
		prc.ajouterValeurALaFile(rand() % 100);
		dbl.ajouterValeurALaFile(drand48());

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		prc.affichageQueue();
		dbl.affichageQueue();

		SDL_RenderPresent(renderer);

		SDL_Delay(1000); // ms
		if (++compteur > 10)
			break;
	}

	SDL_FreeSurface(screen);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}