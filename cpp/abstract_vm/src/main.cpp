/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:26:19 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/11 16:20:08 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

int				main(int ac, char **av)
{
	std::string	line;
	std::string stab[8192];
	int			i = 0;

	Class_parse	*Parse = new Class_parse();
	if (ac == 1)
	{
		while (line != ";;")
		{
			std::getline(std::cin, line);
			if (line == "")
				exit(0);
			if (line != ";;")
			{
				stab[i] = line;
				i++;
			}
		}
		i = 0;
		while (stab[i] != "")
		{
			try { Parse->ft_parse(stab[i]); }
			catch (const char *msg) { std::cerr << msg << std::endl; exit(0); }
			i++;
		}
	}
	else if (ac == 2)
	{
		std::ifstream infile(av[1]);
		while (line != "exit")
		{
			std::getline(infile, line);
			try { Parse->ft_parse(line); }
			catch (const char *msg) { std::cerr << msg << std::endl; exit (0); }
		}
	}
	delete Parse;
	return (0);
}
