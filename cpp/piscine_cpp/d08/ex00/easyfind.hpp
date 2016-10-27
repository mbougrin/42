/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 12:08:32 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/17 15:27:57 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template<typename T>

void			easyfind(T *ptr, int find)
{
	int *p = std::find(ptr, ptr + 4, find);

	if (*p == find)
		std::cout << "easyfind " << *p << " found" << std::endl;
	else
		std::cout << "easyfind " << find << " not found" << std::endl;
}

#endif
