#ifndef _GameEntity_HPP
# define _GameEntity_HPP

# include <ncurses.h>

# include <iostream>
# include <string>

//
//	Classe de base des objets graphiques du jeu:	player, bullets, ennemies (+ boss),
//								et peut etre:		éléments de décors
//

class GameEntity
{
public:
	GameEntity();
	GameEntity(int x, int y, char c, int sizeX, int sizeY, int speed);
	GameEntity(GameEntity const &);
	virtual ~GameEntity();

	GameEntity& operator=(GameEntity const &);

	virtual void	update();
	virtual void	draw();
	virtual void	collide(GameEntity const &);
	virtual void	die();

	void			move(int x, int y);
	bool			isColliding(GameEntity const &) const;

	std::string	getEntityType() const;
	WINDOW *	getWin() const;
	int			getX() const;
	int			getY() const;
	char		getC() const;
	int			getSizeX() const;
	int			getSizeY() const;
	int			getSpeed() const;

	void	debugAnnounce(std::ostream &) const;

protected:
	std::string	_entityType;	// pour le debug principalement
	WINDOW *	_win;
	int			_x;
	int			_y;
	char		_c;
	int			_sizeX;
	int			_sizeY;
	int			_speed;
	int			_speedCount;
	bool		_moved;
};

#endif //_GameEntity_HPP
