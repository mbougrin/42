/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 16:38:12 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/12 17:49:39 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

int kbhit(void)
{
	int ch = getch();

	if (ch != ERR) {
		ungetch(ch);
		return 1;
	} else {
		return 0;
	}
}

void checkCollisions(Player &	player)
{
	int i = 0;
	int j = 0;

	Bullet **	bulletsTab = Bullet::getBulletsTab();
	Ennemy **	ennmiesTab = Ennemy::getEnnemiesTab();

	while (i < NB_BULLETS_MAX)
	{
		j = 0;
		while (j < NB_ENNEMIES_MAX)
		{
			if (bulletsTab[i] != NULL && ennmiesTab[j] != NULL)
			{
				if (bulletsTab[i]->isColliding(*(ennmiesTab[j])))
				{
					if (bulletsTab[i]->getDir() == 1)
					{
						if (ennmiesTab[j]->getC() != 'o')
						{
							ennmiesTab[j]->collide(*(bulletsTab[i]));
							player.increaseScore(1);
							player.increaseDifficulty(5);
						}
						bulletsTab[i]->die();
					}
					else if (ennmiesTab[j]->getC() == 'o')
						bulletsTab[i]->die();
				}
			}
			++j;
		}

		if (bulletsTab[i] != NULL && bulletsTab[i]->getDir() == -1)
		{
			if (player.isColliding(*(bulletsTab[i])))
			{
				player.collide(*(bulletsTab[i]));
				bulletsTab[i]->die();
			}
		}

		++i;
	}

	j = 0;
	while (j < NB_ENNEMIES_MAX)
	{
		if (ennmiesTab[j] != NULL)
		{
			if (player.isColliding(*(ennmiesTab[j])))
			{
				player.collide(*(ennmiesTab[j]));
				if (ennmiesTab[j]->getC() == '<')
					ennmiesTab[j]->die();
			}
		}
		++j;
	}

}

int					main(void)
{
	Class_ncurse	win;

	srand(time(NULL));
	if (win.ft_print_menu() == 1)
	{
		Player	player;

		Bullet::initBulletsTab();
		Ennemy::initEnnemiesTab();

		int		key = 0;
		unsigned int		random = 0;
		timeout(0);
		while (player.getLife() > 0)
		{
			win.ft_print_score(player);
			if (kbhit())
			{
				key = getch();

				player.controls(key);

				if (key == 27) // echap
					break ;
			}
			Bullet::updateBullets();
			Ennemy::updateEnnemies();
			player.update();

			checkCollisions(player);

			Bullet::drawBullets();
			Ennemy::drawEnnemies();
			player.draw();

			if (rand() % 1000 < player.getDiff())
			{
				if (random % 2 == 0)
					Ennemy::addNewEnnemy(new Ennemy(rand() % LINES + 2, COLS, '<', 0, 0, 50));
				else
					Ennemy::addNewEnnemy(new Ennemy(rand() % LINES + 2, COLS, 'o', 0, 0, 50));
				random++;
			}

			usleep(1000);
		}
		win.ft_delwin();
		Bullet::freeBulletsTab();
		Ennemy::freeEnnemiesTab();
		win.save(player.getScore());
		win.game_over();
		win.~Class_ncurse();
		main();
	}
	return (0);
}
