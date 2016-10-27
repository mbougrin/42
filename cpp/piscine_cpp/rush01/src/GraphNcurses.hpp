#ifndef _GraphNcurses_HPP
# define _GraphNcurses_HPP

# include <iostream>
# include <string>
# include <queue>
# include <iterator>

# include <ncurses.h>

# include "IMonitorDisplay.hpp"

template<typename T>
class GraphNcurses : public IMonitorDisplay<T>
{
public:
	GraphNcurses<T>(WINDOW * _win, unsigned int _contenance, T _min, T _max, bool _block) :
			m_windowNcurses(_win), m_queue(),
			m_posX(20), m_posY(20), m_tailleX(20), m_tailleY(1),
			m_contenance(_contenance), m_valMin(_min), m_valMax(_max), m_intervaleBloque(_block)
	{
		while (_contenance-- > 0)
			ajouterValeurALaFile(_min);
		return ;
	}
	GraphNcurses<T>(GraphNcurses const& _inst) :
			m_windowNcurses(_inst.m_windowNcurses), m_queue(_inst.m_queue),
			m_posX(_inst.m_posX), m_posY(_inst.m_posY), m_tailleX(_inst.m_tailleX), m_tailleY(_inst.m_tailleY),
			m_contenance(_inst.m_contenance), m_valMin(_inst.m_valMin), m_valMax(_inst.m_valMax),
			m_intervaleBloque(_inst.m_intervaleBloque)
	{ return ; }
	~GraphNcurses<T>() { return ; }

	GraphNcurses<T>&	operator = (GraphNcurses<T> const& _rhs)
	{
		if (&_rhs != this)
		{
			m_windowNcurses = _rhs.m_windowNcurses;
			m_queue = _rhs.m_queue;
			m_posX = _rhs.m_posX;
			m_contenance = _rhs.m_contenance;
			m_posY = _rhs.m_posY;
			m_tailleX = _rhs.m_tailleX;
			m_tailleY = _rhs.m_tailleY;
			m_valMin = _rhs.m_valMin;
			m_valMax = _rhs.m_valMax;
			m_intervaleBloque = _rhs.m_intervaleBloque;
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
		// adaptation de l'intervale
		if (_val > m_valMax)
		{
			if (m_intervaleBloque)
			{
				_val = m_valMax;
			}
			else
			{
				if (_val - m_valMax > m_valMax - m_valMin)
					_val = m_valMax + (m_valMax - m_valMin);
				m_valMax = _val;
			}
		}
		else if (_val < m_valMin)
		{
			if (m_intervaleBloque)
			{
				_val = m_valMin;
			}
			else
			{
				if (m_valMin - _val < m_valMax - m_valMin)
					_val = m_valMin - (m_valMax - m_valMin);
				m_valMin = _val;
			}
		}

		// ajout
		m_queue.push(_val);
		if (m_queue.size() > m_contenance)
			m_queue.pop();

		return ;
	}

	void	affichageElement(T _val, int _pX, int _tX) const
	{
		T		pas;
		T		v = m_valMin;
		char	c;

		pas = (m_valMax - m_valMin) / _tX;
		mvwprintw(m_windowNcurses, m_posY, _pX, "[");
		for (int i = 0; i < _tX; ++i)
		{
			if (_val > v)
				c = '|';
			else
				c = ' ';

			mvwprintw(m_windowNcurses, m_posY, _pX + i + 1, "%c", c);
			v += pas;
		}
		mvwprintw(m_windowNcurses, m_posY, _pX + _tX + 1, "]");
	}

	void	affichageQueue() const
	{
		std::queue<T>		tmp(m_queue);

		while (!tmp.empty())
		{
			this->affichageElement(tmp.front(), m_posX, m_tailleX);
			tmp.pop();
		}
	}

private:
	WINDOW *		m_windowNcurses;
	std::queue<T>	m_queue;
	int				m_posX;
	int 			m_posY;
	int 			m_tailleX;
	int 			m_tailleY;
	unsigned int	m_contenance;
	T				m_valMin;
	T				m_valMax;
	bool			m_intervaleBloque;

	GraphNcurses();
};

#endif