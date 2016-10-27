
#include "Ennemy.hpp"

////////////////////////////////////////////////////////////////
//                         public                             //
////////////////////////////////////////////////////////////////

Ennemy::Ennemy() : GameEntity(), _index(-1), _shootCount(20), _dying(-1)
{
	_entityType = "Ennemy";
	_c = '#';
	wbkgd(_win, COLOR_PAIR(2));
	_shootCount += rand() % 20;
	return ;
}

Ennemy::Ennemy(int x, int y, char c, int sizeX, int sizeY, int speed) :
				GameEntity(x, y, c, sizeX, sizeY, speed), _index(-1), _shootCount(20), _dying(-1)
{
	_entityType = "Ennemy";
	if (_c == 'o')
		wbkgd(_win, COLOR_PAIR(7));
	else if (_c == '<')
		wbkgd(_win, COLOR_PAIR(3));
	_shootCount += rand() % 20;
	return ;
}

Ennemy::Ennemy(GameEntity const& ge) : GameEntity(ge), _index(-1), _shootCount(20), _dying(-1)
{
	_entityType = "Ennemy";
	_shootCount += rand() % 20;
	return ;
}

Ennemy::Ennemy(Ennemy const& instance)
{
	*this = instance;
	return ;
}

Ennemy::~Ennemy()
{
	//delwin(_win); // dans GameEntity
	return ;
}

Ennemy& Ennemy::operator=(Ennemy const& rhs)
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
	_dying =		rhs._dying;

	return (*this);
}

void	Ennemy::update()
{
	--_speedCount;

	if (_speedCount <= 0)
	{
		_moved = true;
		_y -= 1;
		_speedCount = _speed;

		_shootCount--;
		if (_shootCount <= 0 && _dying < 0)
		{
			if (_c == '<')
				shoot();
			_shootCount = rand() % 20;
		}
	}
	else
		_moved = false;

	if (_y < 1 || _dying > 0) // sortie de fenêtre
		die();

	return ;
}

void	Ennemy::draw()
{
	if (_moved)
	{
		mvwprintw(_win, 0, 0, "%c", ' ');
		wrefresh(_win);
	}
	mvwin(_win, _x, _y);
	if (_dying < 0)
	{
		mvwprintw(_win, 0, 0, "%c", _c);
		wrefresh(_win);
	}
	else
	{
		mvwprintw(_win, 0, 0, "%c", '#');
		wrefresh(_win);
	}
	return ;
}

void	Ennemy::collide(GameEntity const & other)
{
	// faire tout ce qu'il y a faire quand les objets collisionnent.
	// other.die(); éventuellement
	// à surcharger par type d'entités

	(void)other;
	if (_dying < 0)
		_dying = 20;
	die();
	return ;
}

void	Ennemy::die()
{
	--_dying;
	if (_dying <= 0)
	{
		mvwprintw(_win, 0, 0, "%c", ' ');
		wrefresh(_win);
		
		deleteEnnemy(_index);
	}
	return ;
}

void	Ennemy::shoot(void) const
{
	Bullet	*newBullet = new Bullet(_x, _y - 1, '-', 1, 1, 10, 1, -1);

	Bullet::addNewBullet(newBullet);
	
	return ;
}

Ennemy ** Ennemy::getEnnemiesTab()
{
	return (_ennemies);
}

void	Ennemy::debugAnnounce(std::ostream& os) const
{
	GameEntity::debugAnnounce(os);
	os << "# " << "index: " << _index << std::endl;
	return ;
}

////////////////////////////////////////////////////////////////
//                       protected                            //
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
//                       non membre                           //
////////////////////////////////////////////////////////////////

Ennemy *	Ennemy::_ennemies[NB_ENNEMIES_MAX];

void	Ennemy::initEnnemiesTab()
{
	int i = 0;

	while (i < NB_ENNEMIES_MAX)
	{
		_ennemies[i] = NULL;
		++i;
	}
	return ;
}

void	Ennemy::freeEnnemiesTab()
{
	int i = 0;

	while (i < NB_ENNEMIES_MAX)
	{
		if (_ennemies[i] != NULL)
			delete _ennemies[i];
		++i;
	}
	return ;
}

void	Ennemy::drawEnnemies()
{
	int i = 0;

	while (i < NB_ENNEMIES_MAX)
	{
		if (_ennemies[i] != NULL)
			_ennemies[i]->draw();
		++i;
	}
	return ;
}

void	Ennemy::updateEnnemies()
{
	int i = 0;

	while (i < NB_ENNEMIES_MAX)
	{
		if (_ennemies[i] != NULL)
			_ennemies[i]->update();
		++i;
	}
	return ;
}

void	Ennemy::deleteEnnemy(int index)
{
	if (index != -1 && _ennemies[index] != NULL)
	{
		delete _ennemies[index];
		_ennemies[index] = NULL;
	}
	return ;
}

int		Ennemy::addNewEnnemy(Ennemy *newEnnemy)
{

	int i = 0;

	while (_ennemies[i] != NULL && i < NB_ENNEMIES_MAX) // recherche de case vide dans le tableau
	{
		++i;
	}
	if (i != NB_ENNEMIES_MAX) // si le tableau n'est pas rempli
	{
		_ennemies[i] = newEnnemy;
		newEnnemy->_index = i;
		return 1;
	}
	return 0;
}

////////////////////////////////////////////////////////////////
//                        private                             //
////////////////////////////////////////////////////////////////
