/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 05:45:47 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/16 05:46:43 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <class T>
class Array {

	public:
		Array( void ) : _content(NULL), _size(0) {
			return;
		}
		Array( unsigned int n ) : _size(n) {
			this->_content = new T[n];
		}
		Array( Array const & src ) {
			this->_content = new T[src.getSize()];
			*this = src;
		}
		~Array( void ) {
			if ( this->_content != NULL)
				delete [] this->_content;
			return;
		}

		Array<T>&	operator=( Array<T> const & rhs ) {
			if (this != &rhs) {
				for(int i = 0; i < rhs.getSize(); i++) {
					this->_content[i] = rhs[i];
				}
				this->_size = rhs.getSize();
			}
			return *this;
		}

		T&			operator[]( int n ) const {
			if ( n >= this->_size)
				throw std::exception();
			return this->_content[n];
		}

		int			getSize( void ) const {
			return this->_size;
		}

	private:
		T*	_content;
		int	_size;
};

#endif

