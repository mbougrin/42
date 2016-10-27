/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:08:16 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/08 00:44:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"

int				main()
{
	Pony	stack = Pony("Stack");
	Pony	*heap = new Pony("Heap");
	int		nb;
	int		dead_bullet;

	srand(time(NULL));
	dead_bullet = rand() % 5;
	nb = rand() % 5;
	if (dead_bullet == nb)
		std::cout << heap->get_name() << " is dead with a russian roulette" << std::endl;
	nb = rand() % 5;
	if (dead_bullet == nb)
		std::cout << stack.get_name() << " is dead with a russian roulette" << std::endl;
	delete heap;
	return (0);
}
