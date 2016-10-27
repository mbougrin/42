#ifndef _GraphShell_HPP
# define _GraphShell_HPP

# include <iostream>
# include <string>
# include <queue>
# include <iterator>

template<typename T>
class GraphShell
{
public:
	GraphShell<T>(unsigned int _contenance, T _min, T _max) :
			m_queue(), m_contenance(_contenance),
			m_valMin(_min), m_valMax(_max)
	{ return ; }
	GraphShell<T>(GraphShell const& _inst) :
			m_queue(_inst.m_queue), m_contenance(_inst.m_contenance),
			m_valMin(_inst.m_valMin), m_valMax(_inst.m_valMax)
	{ return ; }
	~GraphShell<T>() { return ; }

	GraphShell<T>&	operator = (GraphShell<T> const& _rhs)
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

	unsigned int	accContenance() const { return (m_contenance); }
	T				accValMin() const { return (m_valMin); }
	T				accValMax() const { return (m_valMax); }
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

	void	affichageElement(T _val) const
	{
		T		pas;
		T		v = m_valMin;

		pas = (m_valMax - m_valMin) / 20;
		std::cout << "[";
		for (int i = 0; i < 20; ++i)
		{
			if (_val > v)
				std::cout << "|";
			else
				std::cout << " ";
			v += pas;
		}
		std::cout << "] " << _val << std::endl;
	}

	void	affichageQueue() const
	{
		std::queue<T>		tmp(m_queue);

		while (!tmp.empty())
		{
			this->affichageElement(tmp.front());
			tmp.pop();
		}
	}

private:
	std::queue<T>	m_queue;
	unsigned int	m_contenance;
	T				m_valMin;
	T				m_valMax;

	GraphShell();
};

#endif