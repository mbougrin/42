/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_sdl.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 17:44:38 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/18 19:18:33 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_SDL_HPP
# define CLASS_SDL_HPP

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <iostream>
# define SDL_INIT_FLAGS SDL_INIT_EVERYTHING
# define SDL_WIN_FLAGS SDL_WINDOW_SHOWN

class		Class_sdl
{
	public:
		Class_sdl(void);
		Class_sdl(Class_sdl const &src);
		Class_sdl(std::string name, int h, int w, int y, int x);
		virtual ~Class_sdl(void);

		void				ft_refresh(void);
		void				ft_init_sdl_rect(int w, int h, int x, int y);
		void				ft_init_sdl_color(int r, int g, int b);
		void				ft_init_font(void);
		void				ft_write_tty(const char *str);
		void				ft_init_ttf(void);
		void				ft_init_renderer(void);
		void				ft_init_sdl(void);
		void				ft_create_win_sdl(void);
		void    			ft_write_on_screen(std::string str, int h, int x, int y, int color);
		SDL_Renderer *		getRenderer();

		Class_sdl&			operator=(Class_sdl const &src);
	private:
		std::string			_name;
		SDL_Window			*_win;
		TTF_Font			*_font;
		SDL_Renderer		*_renderer;
		SDL_Color 			color;
		SDL_Rect			pos;
		int					_h;
		int					_w;
		int					_y;
		int					_x;
		int					_r;
		int					_g;
		int					_b;
};

#endif
