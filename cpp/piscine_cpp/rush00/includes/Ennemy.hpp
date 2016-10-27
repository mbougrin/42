#ifndef _Ennemy_HPP
# define _Ennemy_HPP

# include "../includes/GameEntity.hpp"
# include "../includes/Bullet.hpp"
# include <ncurses.h>

# include <iostream>
# include <string>

# define NB_ENNEMIES_MAX 100

class Ennemy : public GameEntity
{
public:
	Ennemy();
	Ennemy(int x, int y, char c, int sizeX, int sizeY, int speed);
	Ennemy(GameEntity const& ge);
	Ennemy(Ennemy const &);
	~Ennemy();

	Ennemy& operator=(Ennemy const &);

	void	update();
	void	draw();
	void	collide(GameEntity const &);
	void	die();
	void	shoot(void) const;

	void	debugAnnounce(std::ostream &) const;

	static Ennemy **	getEnnemiesTab();
	static void			initEnnemiesTab();
	static void			freeEnnemiesTab();
	static void			drawEnnemies();
	static void			updateEnnemies();
	static int			addNewEnnemy(Ennemy *newEnnemy);
	static void			deleteEnnemy(int index);

private:
	static Ennemy *	_ennemies[NB_ENNEMIES_MAX];

	int		_index;
	int 	_shootCount;
	int 	_dying;

};

#endif //_Ennemy_HPP
