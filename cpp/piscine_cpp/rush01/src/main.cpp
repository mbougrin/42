/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 14:04:53 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 14:04:55 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NameModule.hpp"
#include "InfoModule.hpp"
#include "TimeModule.hpp"
#include "Class_cpu.hpp"
#include "Class_ram.hpp"
#include "Class_network.hpp"
#include "Class_sdl.hpp"
#include "GraphSDL.hpp"
#include "GraphNcurses.hpp"
#include <time.h>
#include <ncurses.h>
#include <string>
#include <cstring>
#include <sstream>

void		ft_set(TimeModule& time, Class_cpu& cpu, Class_ram& ram, Class_network &net);

void		ft_sdl(void)
{
	Class_sdl		sdl("ft_gkrellm", 600, 800, 0, 0);
	SDL_Event		event;
	NameModule		name;
	InfoModule		info;
	TimeModule		time;
	Class_cpu		cpu;
	Class_ram		ram;
	Class_network	net;
	bool filtre = true;

	name.set();
	info.set();
	ram.setConvert("octel");

	GraphSDL<long long>		graphRAM(sdl.getRenderer(), 50, 0, ram.getPMemory(), true);
	GraphSDL<long long>		graphNet(sdl.getRenderer(), 50, 0LL, 500000LL, false);

	GraphSDL<float>	graphCore1(sdl.getRenderer(), 25, 0.f, 100.f, true);
	GraphSDL<float>	graphCore2(sdl.getRenderer(), 25, 0.f, 100.f, true);
	GraphSDL<float>	graphCore3(sdl.getRenderer(), 25, 0.f, 100.f, true);
	GraphSDL<float>	graphCore4(sdl.getRenderer(), 25, 0.f, 100.f, true);

	graphRAM.mutPos(20, 220);
	graphRAM.mutTaille(150, 100);
	graphNet.mutPos(20, 430);
	graphNet.mutTaille(200, 50);

	graphCore1.mutPos(300, 270);
	graphCore1.mutTaille(50, 50);
	graphCore2.mutPos(graphCore1.accPosX() + graphCore1.accTailleX() + 10, graphCore1.accPosY());
	graphCore2.mutTaille(graphCore1.accTailleX(), graphCore1.accTailleY());
	graphCore3.mutPos(graphCore2.accPosX() + graphCore2.accTailleX() + 10, graphCore2.accPosY());
	graphCore3.mutTaille(graphCore2.accTailleX(), graphCore2.accTailleY());
	graphCore4.mutPos(graphCore3.accPosX() + graphCore3.accTailleX() + 10, graphCore3.accPosY());
	graphCore4.mutTaille(graphCore3.accTailleX(), graphCore3.accTailleY());


	while (1)
	{
		ft_set(time, cpu, ram, net);
		if (SDL_PollEvent(&event))
		{
			if (event.type)
			{
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
					exit(-1);
				if (event.window.event == 1)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
						exit(-1);
				}
			}
		}


		unsigned int font_size = 20;

		sdl.ft_write_on_screen(name.getHostName() + " " + name.getUserName(),
								font_size, 5, 5, 0x4040FF);

		sdl.ft_write_on_screen(time.getTime(),
								font_size, 5, 40, 0x4040FF);

		sdl.ft_write_on_screen(info.getInfo(),
								font_size, 300, 5, 0x4040FF);

		sdl.ft_write_on_screen(cpu.getName(),
								font_size, 300, 40, 0x4040FF);

		sdl.ft_write_on_screen("Total Ram: " + std::to_string(ram.getPMemory()) + " Octel",
								font_size, 5, 120, 0x4040FF);

		sdl.ft_write_on_screen("Used Ram: " + std::to_string(ram.getUsedMemory()) + " Octel",
								font_size, 5, 150, 0x4040FF);

		sdl.ft_write_on_screen("Free Ram: " + std::to_string(ram.getFreeMemory()) + " Octel",
								font_size, 5, 180, 0x4040FF);

		sdl.ft_write_on_screen(std::to_string(cpu.getNBCpu()) + " cores",
								font_size, 300, 90, 0x4040FF);
		

		for (unsigned int i = 0; i < cpu.getNBCpu(); ++i)
		{
			sdl.ft_write_on_screen(	"CPU" + std::to_string(i+1) +
									": system:" + std::to_string(cpu.cpu_system(i)) +
									" user:" + std::to_string(cpu.cpu_user(i)) +
									" idle:" + std::to_string(cpu.cpu_idle(i)),
									font_size, 300, 120 + i*30, 0x4040FF);
		}

		sdl.ft_write_on_screen(	"ACPU: system:" + std::to_string(cpu.Tcpu_system()) +
								" user:" + std::to_string(cpu.Tcpu_user()) +
								" idle:" + std::to_string(cpu.Tcpu_idle()),
								font_size, 300, 120 + 30 * cpu.getNBCpu(), 0x4040FF);


		sdl.ft_write_on_screen("Network throughput: " +
								std::to_string(net.ft_get_network()) +
								" bytes/sec",
								font_size, 5, 400, 0x4040FF);

		if (!filtre)
		{
			graphRAM.ajouterValeurALaFile(ram.getUsedMemory());
			graphRAM.affichageQueue();

			graphNet.ajouterValeurALaFile(net.ft_get_network());
			graphNet.affichageQueue();

			graphCore1.ajouterValeurALaFile(100.f - cpu.cpu_idle(0));
			graphCore1.affichageQueue();
			graphCore2.ajouterValeurALaFile(100.f - cpu.cpu_idle(1));
			graphCore2.affichageQueue();
			graphCore3.ajouterValeurALaFile(100.f - cpu.cpu_idle(2));
			graphCore3.affichageQueue();
			graphCore4.ajouterValeurALaFile(100.f - cpu.cpu_idle(3));
			graphCore4.affichageQueue();
		}
		filtre = false;

		sleep(1);
		sdl.ft_refresh();
		if (SDL_PollEvent(&event))
		{
			if (event.type)
			{
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
					exit(-1);
				if (event.window.event == 1)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
						exit(-1);
				}
			}
		}

	}
}

void		ft_print(NameModule &name, InfoModule &info, TimeModule &time, Class_ram &ram,
						Class_cpu &cpu, WINDOW *win, Class_network &net)
{
	mvwprintw(win, 0, 0, "%s %s", name.getHostName().c_str(), name.getUserName().c_str());
	mvwprintw(win, 0, 40, "%s", info.getInfo().c_str());
	mvwprintw(win, 1, 0, "%s", time.getTime().c_str());
	mvwprintw(win, 1, 40, "%s", cpu.getName().c_str());
	mvwprintw(win, 4, 0, "Total Ram: %lld %s", ram.getPMemory(), ram.getConvert().c_str());
	mvwprintw(win, 5, 0, "Used  Ram: %lld %s", ram.getUsedMemory(), ram.getConvert().c_str());
	mvwprintw(win, 6, 0, "Free  Ram: %lld %s", ram.getFreeMemory(), ram.getConvert().c_str());

	
	mvwprintw(win, 3, 40, "%d cores", cpu.getNBCpu());
	mvwprintw(win, 4, 40, "cpu1: system: %f %% user: %f %% idle: %f %%", \
			cpu.cpu_system(0), cpu.cpu_user(0), cpu.cpu_idle(0));
	mvwprintw(win, 5, 40, "cpu2: system: %f %% user: %f %% idle: %f %%", \
			cpu.cpu_system(1), cpu.cpu_user(1), cpu.cpu_idle(1));
	mvwprintw(win, 6, 40, "cpu3: system: %f %% user: %f %% idle: %f %%", \
			cpu.cpu_system(2), cpu.cpu_user(2), cpu.cpu_idle(2));
	mvwprintw(win, 7, 40, "cpu4: system: %f %% user: %f %% idle: %f %%", \
			cpu.cpu_system(3), cpu.cpu_user(3), cpu.cpu_idle(3));
	mvwprintw(win, 8, 40, "Acpu: system: %f %% user: %f %% idle: %f %%", \
			cpu.Tcpu_system(), cpu.Tcpu_user(), cpu.Tcpu_idle());

	mvwprintw(win, 13, 0, "                                    ", net.ft_get_network()); // c'est ca qu'est bon !!!
	mvwprintw(win, 13, 0, "Network: %lld bytes/sec", net.ft_get_network());
}

void		ft_set(TimeModule& time, Class_cpu& cpu, Class_ram& ram, Class_network &net)
{
	cpu.setName();
	time.set();
	cpu.setCpu();
	cpu.convertCpu();
	ram.setUsedMemory();
	net.ft_set_network();
}

void		ft_init(NameModule &name, InfoModule &info, Class_ram &ram, char *str)
{
	name.set();
	info.set();
	if (str == NULL)
		ram.setConvert("octel");
	else
		ram.setConvert(str);
	initscr();
	curs_set(FALSE);
	start_color();
	nodelay(stdscr, TRUE);
	noecho();
	raw();
	keypad(stdscr, TRUE);
	init_color(COLOR_BLACK, 200, 200, 200);

}

void		ft_ncurses(int ac, char **av)
{
	NameModule		name;
	InfoModule		info;
	TimeModule		time;
	Class_cpu		cpu;
	Class_ram		ram;
	Class_network	net;

	if (ac == 1)
		ft_init(name, info, ram, NULL);
	else
		ft_init(name, info, ram, av[1]);

	WINDOW*			win = newwin(800, 600, 0, 0);

	GraphNcurses<long long>	graphNRAM(win, 1, 0, ram.getPMemory(), true);
	GraphNcurses<long long>	graphNNet(win, 1, 0LL, 500000LL, false);

	GraphNcurses<float>		graphNCore1(win, 1, 0.f, 100.f, true);
	GraphNcurses<float>		graphNCore2(win, 1, 0.f, 100.f, true);
	GraphNcurses<float>		graphNCore3(win, 1, 0.f, 100.f, true);
	GraphNcurses<float>		graphNCore4(win, 1, 0.f, 100.f, true);

	graphNRAM.mutPos(5, 8);
	graphNNet.mutPos(5, 15);
	graphNCore1.mutPos(45, 10);
	graphNCore2.mutPos(45, 11);
	graphNCore3.mutPos(45, 12);
	graphNCore4.mutPos(45, 13);

	while (283 != getch())
	{
		ft_set(time, cpu, ram, net);
		ft_print(name, info, time, ram, cpu, win, net);

		graphNRAM.ajouterValeurALaFile(ram.getUsedMemory());
		mvwprintw(win, 8, 0, "RAM: ");
		graphNRAM.affichageQueue();

		graphNNet.ajouterValeurALaFile(net.ft_get_network());
		mvwprintw(win, 15, 0, "Net :");
		graphNNet.affichageQueue();

		graphNCore1.ajouterValeurALaFile(100.f - cpu.cpu_idle(0));
		mvwprintw(win, 10, 40, "cpu1:");
		graphNCore1.affichageQueue();

		graphNCore2.ajouterValeurALaFile(100.f - cpu.cpu_idle(1));
		mvwprintw(win, 11, 40, "cpu2:");
		graphNCore2.affichageQueue();

		graphNCore3.ajouterValeurALaFile(100.f - cpu.cpu_idle(2));
		mvwprintw(win, 12, 40, "cpu3:");
		graphNCore3.affichageQueue();

		graphNCore4.ajouterValeurALaFile(100.f - cpu.cpu_idle(3));
		mvwprintw(win, 13, 40, "cpu4:");
		graphNCore4.affichageQueue();

		clear();
		wrefresh(win);
		sleep(1);
	}
	getch();
	endwin();

}

int			main(int ac, char **av)
{
	if (ac == 1 || (ac == 2 && strstr(av[1], "octel") != NULL))
		ft_ncurses(ac, av);
	else if (ac == 2 && strstr(av[1], "sdl") != NULL)
		ft_sdl();
	return 0;
}
