#ifndef _GraphSDL_HPP
# define _GraphSDL_HPP

# include <iostream>
# include <string>
# include <queue>
# include <iterator>

# include <SDL.h>

template<typename T>
class GraphSDL
{
public:
	GraphSDL<T>(SDL_Surface *_surface, SDL_Renderer * _renderer, unsigned int _contenance, T _min, T _max) :
			m_surfaceSDL(_surface), m_rendererSDL(_renderer), m_queue(),
			m_posX(20), m_posY(20), m_tailleX(_contenance * 10), m_tailleY(_contenance * 10),
			m_contenance(_contenance), m_valMin(_min), m_valMax(_max)
	{ return ; }
	GraphSDL<T>(GraphSDL const& _inst) :
			m_surfaceSDL(_inst.m_surfaceSDL), m_rendererSDL(_inst.m_rendererSDL), m_queue(_inst.m_queue),
			m_posX(_inst.m_posX), m_posY(_inst.m_posY), m_tailleX(_inst.m_tailleX), m_tailleY(_inst.m_tailleY),
			m_contenance(_inst.m_contenance), m_valMin(_inst.m_valMin), m_valMax(_inst.m_valMax)
	{ return ; }
	~GraphSDL<T>() { return ; }

	GraphSDL<T>&	operator = (GraphSDL<T> const& _rhs)
	{
		if (&_rhs != this)
		{
			m_queue = _rhs.m_queue;
			m_contenance = _rhs.m_contenance;
			m_valMin = _rhs.m_valMin;
			m_valMax = _rhs.m_valMax;
		}
		return (*this);
	}

	int				accPosX() const { return (m_posX); }
	int				accPosY() const { return (m_posY); }
	int				accTailleX() const { return (m_tailleX); }
	int				accTailleY() const { return (m_tailleY); }
	unsigned int	accContenance() const { return (m_contenance); }
	T				accValMin() const { return (m_valMin); }
	T				accValMax() const { return (m_valMax); }
	void			mutPos(int _x, int _y) { m_posX = _x; m_posY = _y; }
	void			mutTaille(int _x, int _y) { m_tailleX = _x; m_tailleY = _y; }
	void			mutValMin(T _val) { if (_val < m_valMax) m_valMin = _val; }
	void			mutValMax(T _val) { if (_val > m_valMin) m_valMax = _val; }

	void	ajouterValeurALaFile(T _val)
	{
		if (m_valMax > _val && _val > m_valMin)
		{
			m_queue.push(_val);
			if (m_queue.size() > m_contenance)
				m_queue.pop();
		}
		return ;
	}

	void	affichageElement(T _val, int _pX, int _tX) const
	{
		float		prc = (_val - m_valMin) * 100.f / (m_valMax - m_valMin);
		SDL_Rect 	rect = {_pX, m_posY, _tX, m_tailleY};

		rect.h = (prc / 100.f) * m_tailleY;
		rect.y = m_posY + (m_tailleY - rect.h);

		std::cerr << m_valMin << " " << m_valMax << " " << _val << " " << prc << std::endl;

		if (prc > 85.f)
		{
			rect.h = (prc / 100.f) * m_tailleY;
			rect.y = m_posY + (m_tailleY - rect.h);
			SDL_SetRenderDrawColor(m_rendererSDL, 255, 0, 0, 255);
			SDL_RenderFillRect(m_rendererSDL, &rect);
			prc = 85.f;
		}
		if (prc > 60.f)
		{
			rect.h = (prc / 100.f) * m_tailleY;
			rect.y = m_posY + (m_tailleY - rect.h);
			SDL_SetRenderDrawColor(m_rendererSDL, 255, 255, 0, 255);
			SDL_RenderFillRect(m_rendererSDL, &rect);
			prc = 60.f;
		}
		rect.h = (prc / 100.f) * m_tailleY;
		rect.y = m_posY + (m_tailleY - rect.h);
		SDL_SetRenderDrawColor(m_rendererSDL, 0, 255, 0, 255);
		SDL_RenderFillRect(m_rendererSDL, &rect);
	}

	void	affichageQueue() const
	{
		std::queue<T>	tmp(m_queue);
		float 			posX_elem = static_cast<float>(m_posX);
		float 			tailleX_elem = static_cast<float>(m_tailleX) / m_contenance;
		SDL_Rect 		rect = {m_posX, m_posY, m_tailleX, m_tailleY};

		while (!tmp.empty())
		{
			affichageElement(tmp.front(), static_cast<int>(posX_elem), static_cast<int>(tailleX_elem));
			tmp.pop();
			posX_elem += tailleX_elem;
		}
		SDL_SetRenderDrawColor(m_rendererSDL, 100, 100, 100, 255);
		SDL_RenderDrawRect(m_rendererSDL, &rect);
	}

private:
	SDL_Surface *	m_surfaceSDL;
	SDL_Renderer *	m_rendererSDL;
	std::queue<T>	m_queue;
	int				m_posX;
	int 			m_posY;
	int 			m_tailleX;
	int 			m_tailleY;
	unsigned int	m_contenance;
	T				m_valMin;
	T				m_valMax;

	GraphSDL();
};

#endif