/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 16:21:11 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/15 19:28:28 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename IT>

void			function(IT *src)
{
	*src += 1;
}

template<typename ITER>

void			iter(ITER *array, int len, void (*ptr_function)(ITER))
{
	int		i = 0;

	while (i < len)
	{
		ptr_function(*array + i);
		i++;
	}
}

int				main(void)
{
	char	str[6] = "salut";
	int		i[4] = {0, 0, 0, 0};

	std::cout << str << std::endl;
	std::cout << i[1] << std::endl;
	iter(&i, 4, function);
	iter(&str, 5, function);
	std::cout << str << std::endl;
	std::cout << i[1] << std::endl;
	return (0);
}
