
#include "../includes/Bullet.hpp"

#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////
//                         public                             //
////////////////////////////////////////////////////////////////

Bullet::Bullet() : GameEntity(), _power(1), _dir(0), _index(-1)
{
	wbkgd(_win, COLOR_PAIR(0));
	_entityType = "Bullet";
	_c = '-';
	return ;
}

Bullet::Bullet(int x, int y, char c, int sizeX, int sizeY, int speed, int power, int dir) :
				GameEntity(x, y, c, sizeX, sizeY, speed), _power(power), _dir(dir), _index(-1)
{
	if (_dir > 0)
		wbkgd(_win, COLOR_PAIR(8));
	else
		wbkgd(_win, COLOR_PAIR(9));

	_entityType = "Bullet";
	return ;
}

Bullet::Bullet(GameEntity const& ge, int power, int dir) :
				GameEntity(ge), _power(power), _dir(dir), _index(-1)
{
	_entityType = "Bullet";
	return ;
}

Bullet::Bullet(Bullet const& instance)
{
	*this = instance;
	return ;
}

Bullet::~Bullet()
{
	//delwin(_win); // dans GameEntity
	return ;
}

Bullet& Bullet::operator=(Bullet const& rhs)
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
	_power =		rhs._power;
	_dir =			rhs._dir;

	return (*this);
}

void	Bullet::update()
{
	--_speedCount;
	if (_speedCount <= 0)
	{
		_y += _dir;
		_moved = true;
		_speedCount = _speed;
	}
	else
		_moved = false;

	if (_y > COLS || _y < 0) // sortie de fenêtre
		die();

	return ;
}

void	Bullet::draw()
{
	if (_moved)
	{
		mvwprintw(_win, 0, 0, "%c", ' ');
		wrefresh(_win);
	}
	mvwin(_win, _x, _y);
	mvwprintw(_win, 0, 0, "%c", _c);
	wrefresh(_win);
	return ;
}

void	Bullet::collide(GameEntity const & other)
{
	(void)other;
	die();
	return ;
}

void	Bullet::die()
{
	mvwprintw(_win, 0, 0, "%c", ' ');
	wrefresh(_win);

	deleteBullet(_index);

	return ;
}

int		Bullet::getPower() const	{ return (_power); }
int		Bullet::getDir() const		{ return (_dir); }

Bullet ** Bullet::getBulletsTab()
{
	return (_bullets);
}

void	Bullet::debugAnnounce(std::ostream& os) const
{
	GameEntity::debugAnnounce(os);
	os << "# " << "power: " << _power << std::endl;
	os << "# " << "index: " << _index << std::endl;
	return ;
}

////////////////////////////////////////////////////////////////
//                       protected                            //
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
//                       non membre                           //
////////////////////////////////////////////////////////////////

Bullet *	Bullet::_bullets[NB_BULLETS_MAX];

void	Bullet::initBulletsTab()
{
	int i = 0;

	while (i < NB_BULLETS_MAX)
	{
		_bullets[i] = NULL;
		++i;
	}
	return ;
}

void	Bullet::freeBulletsTab()
{
	int i = 0;

	while (i < NB_BULLETS_MAX)
	{
		if (_bullets[i] != NULL)
			delete _bullets[i];
		++i;
	}
	return ;
}

void	Bullet::drawBullets()
{
	int i = 0;

	while (i < NB_BULLETS_MAX)
	{
		if (_bullets[i] != NULL)
			_bullets[i]->draw();
		++i;
	}
	return ;
}

void	Bullet::updateBullets()
{
	int i = 0;

	while (i < NB_BULLETS_MAX)
	{
		if (_bullets[i] != NULL)
			_bullets[i]->update();
		++i;
	}
	return ;
}

void	Bullet::deleteBullet(int index)
{
	if (index != -1 && _bullets[index] != NULL)
	{
		delete _bullets[index];
		_bullets[index] = NULL;
	}
	return ;
}

int		Bullet::addNewBullet(Bullet *newBullet)
{
	int i = 0;

	while (_bullets[i] != NULL && i < NB_BULLETS_MAX) // recherche de case vide dans le tableau
	{
		++i;
	}
	if (i != NB_BULLETS_MAX) // si le tableau n'est pas rempli
	{
		_bullets[i] = newBullet;
		newBullet->_index = i;
		return 1;
	}
	return 0;
}

////////////////////////////////////////////////////////////////
//                        private                             //
////////////////////////////////////////////////////////////////
