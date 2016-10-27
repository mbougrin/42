//#include "SDL.h"   /* All SDL App's need this */
#include "/usr/local/include/SDL/SDL.h" // relou, voir l'inclusion à la compil
//#include <SDL.h>
#include <unistd.h>
#include <stdio.h>


//void display_bmp(char *file_name);
Uint32 getpixel(SDL_Surface *surface, int x, int y);
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);


int main(int argc, char **argv)
{
	printf("Initializing SDL.\n");

	/* Initialize defaults, Video and Audio */
	if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1))
	{ 
		printf("Could not initialize SDL: %s.\n", SDL_GetError());
		exit(-1);
	}
	printf("SDL initialized.\n");

	/* Initialize the SDL library */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(-1);
	}

	/* Clean up on exit */
	atexit(SDL_Quit);
	
	/*
	** Initialize the display in a 640x480 8-bit palettized mode,
	** requesting a software surface
	*/
	SDL_Surface *screen;

	screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE);
	if (screen == NULL)
	{
		fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
			SDL_GetError());
		exit(-1);
	}

	/* Have a preference for 8-bit, but accept any depth */
	screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE | SDL_ANYFORMAT);
	if (screen == NULL)
	{
		fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
			SDL_GetError());
		exit(-1);
	}
	printf("Set 640x480 at %d bits-per-pixel mode\n",
		screen->format->BitsPerPixel);


	/* Code to set a yellow pixel at the center of the screen */

	int x, y;
	Uint32 yellow;

	/* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
	   Note:  If the display is palettized, you must set the palette first.
	*/
	yellow = SDL_MapRGB(screen->format, 0xff, 0xff, 0x00);

	x = screen->w / 2;
	y = screen->h / 2;

	/* Lock the screen for direct access to the pixels */
	if (SDL_MUSTLOCK(screen))
		if (SDL_LockSurface(screen) < 0)
		{
			fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
			return (0);
		}

	putpixel(screen, x, y, yellow);

	if (SDL_MUSTLOCK(screen))
		SDL_UnlockSurface(screen);

	/* Update just the part of the display that we've changed */
	SDL_UpdateRect(screen, x, y, 1, 1);

	SDL_Rect 	rect = {x + 20, y + 20, 100, 100};
	SDL_FillRect(screen, &rect, yellow);
	SDL_UpdateRect(screen, x + 20, y + 20, 100, 100);


	//while (1);
	sleep(3); // secondes, usleep() en microsecondes

	printf("Quiting SDL.\n");
	/* Shutdown all subsystems */
	SDL_Quit();
	printf("Quiting....\n");

	return (0);
}

/*
void display_bmp(char *file_name)
{
	SDL_Surface *image;

	// Load the BMP file into a surface
	image = SDL_LoadBMP(file_name);
	if (image == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", file_name, SDL_GetError());
		return ;
	}

	// Palettized screen modes will have a default palette (a standard
	// 8*8*4 colour cube), but if the image is palettized as well we can
	// use that palette for a nicer colour matching
	
	if (image->format->palette && screen->format->palette)
	{
		SDL_SetColors(screen, image->format->palette->colors, 0,
			image->format->palette->ncolors);
	}

	// Blit onto the screen surface
	if(SDL_BlitSurface(image, NULL, screen, NULL) < 0)
		fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());

	SDL_UpdateRect(screen, 0, 0, image->w, image->h);

	// Free the allocated BMP surface
	SDL_FreeSurface(image);
}
*/

/*
** Return the pixel value at (x, y)
** NOTE: The surface must be locked before calling this!
*/
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp)
	{
		case 1:
			return *p;

		case 2:
			return *(Uint16 *)p;

		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;

		case 4:
			return *(Uint32 *)p;

		default:
			return 0;       /* shouldn't happen, but avoids warnings */
	}
}

/*
** Set the pixel at (x, y) to the given value
** NOTE: The surface must be locked before calling this!
*/
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int bpp = surface->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to set */
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp)
	{
		case 1:
			*p = pixel;
			break;

		case 2:
			*(Uint16 *)p = pixel;
			break;

		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			{
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			}
			else
			{
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
			}
			break;

		case 4:
			*(Uint32 *)p = pixel;
			break;
	}
}
