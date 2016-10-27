/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:36:57 by mbougrin          #+#    #+#             */
/*   Updated: 2015/01/15 18:07:36 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <cstdlib>
# include <numeric>

class			Span
{
	public:
		Span(unsigned int nb);
		Span(Span const &src);
		virtual ~Span(void);

		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			addNumber(unsigned int nb);
		Span&			operator=(Span const &src);
	private:
		Span(void);
		unsigned	int				_n;
		std::list<unsigned int>		_lst;
};

#endif
