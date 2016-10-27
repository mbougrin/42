
#include <string>
#include <iostream>
#include <queue>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <unistd.h>


#include "GraphShell.hpp"

int main()
{
	srand(time(0));
	srand48(time(0));

	GraphShell<int>		prc(10, 0, 100);
	GraphShell<float>	dbl(10, 0.f, 1.f);

	while (1)
	{
		prc.ajouterValeurALaFile(rand() % 100);
		dbl.ajouterValeurALaFile(drand48());

		prc.affichageQueue();
		std::cout << std::endl;
		dbl.affichageQueue();
		std::cout << std::endl;

		sleep(1);
	}

	return 0;
}