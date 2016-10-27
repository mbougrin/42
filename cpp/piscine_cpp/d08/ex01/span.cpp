/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:37:00 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/17 15:42:45 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

unsigned int	Span::longestSpan(void)
{
	return (*std::max_element(this->_lst.begin(), this->_lst.end()) - \
			*std::min_element(this->_lst.begin(), this->_lst.end()));
}

unsigned int	Span::shortestSpan(void)
{
	std::list<unsigned int>		lst_tmp = this->_lst;
	lst_tmp.sort();
	std::adjacent_difference(lst_tmp.begin(), lst_tmp.end(), lst_tmp.begin());
	return (*std::min_element(lst_tmp.begin(), lst_tmp.end()));
}

void			Span::addNumber(unsigned int nb)
{
	static unsigned int		count;

	if (count < _n)
		this->_lst.push_back(nb);
	else
	{
		throw std::exception();
	}
	count++;
}

Span&	Span::operator=(Span const &src) { if (this != &src) {} return *this; }

Span::Span(void) { return ; }

Span::Span(unsigned int nb) : _n(nb) { return ; }

Span::Span(Span const &src) { *this = src; }

Span::~Span(void) { return ; }
