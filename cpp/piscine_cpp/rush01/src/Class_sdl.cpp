/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_sdl.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 17:44:38 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/18 19:19:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class_sdl.hpp"

void		Class_sdl::ft_init_font(void)
{
	if ((this->_font = TTF_OpenFont("font/FreeSansBold.ttf", 65)) == NULL)
	{
	//	ft_putstr_fd("TTF_OpenFont error ", 2);
	//	ft_putendl_fd(TTF_GetError(), 2);
		exit(-1);
	}
}

void		Class_sdl::ft_write_tty(const char* str)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = NULL;
	texture = NULL;
	if ((surface = TTF_RenderText_Blended(this->_font, str, this->color)) == NULL)
	{
	//	ft_putstr_fd("TTF_RenderTextSolid error ", 2);
	//	ft_putendl_fd(TTF_GetError(), 2);
		exit(-1);
	}
	if ((texture = SDL_CreateTextureFromSurface(this->_renderer, surface)) == 0)
	{
	//	ft_putstr_fd("SDL_CreateTextureFromSurface error ", 2);
	//	ft_putendl_fd(SDL_GetError(), 2);
		exit(-1);
	}
	SDL_FreeSurface(surface);
	if (SDL_RenderCopy(this->_renderer, texture, NULL, &this->pos) < 0)
	{
	//	ft_putstr_fd("SDL_RenderCopy error ", 2);
	//	ft_putendl_fd(SDL_GetError(), 2);
		exit(-1);

	}
	SDL_DestroyTexture(texture);
}

void    Class_sdl::ft_write_on_screen(std::string str, int h, int x, int y, int color)
{
    
    ft_init_sdl_rect(str.length() * ((h + h) / 5), h, x, y);
    ft_init_sdl_color(color & 0xFF, (color >> 8) & 0xFF, (color >> 16) & 0xFF);
    ft_write_tty(str.c_str());
}


void		Class_sdl::ft_init_ttf(void)
{
	if (TTF_Init() < 0)
	{
	//	ft_putstr_fd("TTF_init error ", 2);
	//	ft_putendl_fd(TTF_GetError(), 2);
		exit(-1);
	}
}

void		Class_sdl::ft_init_sdl_rect(int w, int h, int x, int y)
{
	this->pos.h = h;
	this->pos.w = w;
	this->pos.x = x;
	this->pos.y = y;
}

void		Class_sdl::ft_init_sdl_color(int r, int g, int b)
{
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;	
}

void		Class_sdl::ft_init_renderer(void)
{
	if ((this->_renderer = SDL_CreateRenderer(this->_win, -1, \
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC \
					)) == NULL)
	{
	//	ft_putstr_fd("SDL_Create_Renderer error ", 2);
	//	ft_putendl_fd(SDL_GetError(), 2);
		exit(-1);
	}
}

void		Class_sdl::ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_FLAGS) < 0)
	{
	//	ft_putstr_fd("SDL_Init error ", 2);
	//	ft_putendl_fd(SDL_GetError(), 2);
		exit(-1);
	}
}

void		Class_sdl::ft_create_win_sdl(void)
{
	if ((this->_win = SDL_CreateWindow(this->_name.c_str(), this->_x, this->_y, this->_w, this->_h, SDL_WIN_FLAGS)) == NULL)
	{
	//	ft_putstr_fd("SDL_CreateWindow error ", 2);
	//	ft_putendl_fd(SDL_GetError(), 2);
		exit(-1);
	}
}

void		Class_sdl::ft_refresh(void)
{
	SDL_RenderPresent(this->_renderer);
	SDL_RenderClear(this->_renderer);
}

Class_sdl::Class_sdl(void) { return ; }

Class_sdl::Class_sdl(std::string name, int h, int w, int y, int x)
	: _name(name), _h(h), _w(w), _y(y), _x(x)
{
	this->_r = 0;
	this->_g = 0;
	this->_b = 0;
	ft_init_sdl();
	ft_init_ttf();
	ft_create_win_sdl();
	ft_init_renderer();
	ft_init_font();
}

SDL_Renderer *	Class_sdl::getRenderer() { return (this->_renderer);}

Class_sdl::Class_sdl(Class_sdl const &src) { if (this != &src) { *this = src ; } return ; }

Class_sdl::~Class_sdl(void) { return ; }

Class_sdl&		Class_sdl::operator=(Class_sdl const &src) { if (this != &src) { } return *this; }
