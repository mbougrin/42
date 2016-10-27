
#include "../includes/GameEntity.hpp"

#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////
//                         public                             //
////////////////////////////////////////////////////////////////

GameEntity::GameEntity() : _entityType("GameEntity"),
							_x(0), _y(0), _c('Z'), _sizeX(1), _sizeY(1), _speed(0), _speedCount(0)
{
	// faire des vérifications sur la validité du pointeur donné? (genre != NULL)
	_win = newwin(1, 1, _x, _y);
	return ;
}

GameEntity::GameEntity(int x, int y, char c, int sizeX, int sizeY, int speed) :
						_entityType("GameEntity"), _x(x), _y(y), _c(c),
						_sizeX(sizeX), _sizeY(sizeY), _speed(speed), _speedCount(0)
{
	// faire des vérifications sur la validité du pointeur _win donné? (genre != NULL)
	// faire des vérifications sur les valeurs x, y, c, size, ...?
	_win = newwin(1, 1, _x, _y);
	return ;
}

GameEntity::GameEntity(GameEntity const& instance)
{
	*this = instance;
	return ;
}

GameEntity::~GameEntity()
{
	delwin(_win);
	return ;
}

GameEntity& GameEntity::operator=(GameEntity const& rhs)
{
	_entityType =	rhs._entityType;
	_win =			rhs._win;
	_x =			rhs._x;
	_y =			rhs._y;
	_c =			rhs._c;
	_sizeX =		rhs._sizeX;
	_sizeY =		rhs._sizeY;
	_speed =		rhs._speed;
	_speedCount =	rhs._speedCount;

	return (*this);
}

void	GameEntity::update()
{
	return ;
}

void	GameEntity::draw()
{
	return ;
}

void	GameEntity::collide(GameEntity const & other)
{
	// faire tout ce qu'il y a faire quand les objets collisionnent.
	// die(); éventuellement
	// à surcharger par type d'entités
	(void)other;
	return ;
}

void	GameEntity::die()
{
	// à surcharger par type d'entités
	return ;
}

void	GameEntity::move(int x, int y)
{
	if (x >= 0 && x < LINES)
		_x = x;
	if (y >= 0 && y < COLS)
		_y = y;
	
	return ;
}

bool	GameEntity::isColliding(GameEntity const & other) const
{
	return (_x == other._x && _y == other._y);
}

std::string	GameEntity::getEntityType() const 	{ return (_entityType); }
WINDOW *	GameEntity::getWin() const 			{ return (_win); }
int			GameEntity::getX() const 			{ return (_x); }
int			GameEntity::getY() const 			{ return (_y); }
char		GameEntity::getC() const 			{ return (_c); }
int			GameEntity::getSizeX() const 		{ return (_sizeX); }
int			GameEntity::getSizeY() const 		{ return (_sizeY); }
int			GameEntity::getSpeed() const 		{ return (_speed); }

void		GameEntity::debugAnnounce(std::ostream& os) const
{
	os << "# " << _entityType << std::endl;
	os << "# " << "win:   " << _win << std::endl;
	os << "# " << "pos:   [" << _x << ", " << _y << "]" << std::endl;
	os << "# " << "char:  " << _c << std::endl;
	os << "# " << "size:  [" << _sizeX << ", " << _sizeY << "]"<< std::endl;
	os << "# " << "speed: " << _sizeY << std::endl;
	return ;
}

////////////////////////////////////////////////////////////////
//                       protected                            //
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
//                       non membre                           //
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
//                        private                             //
////////////////////////////////////////////////////////////////

