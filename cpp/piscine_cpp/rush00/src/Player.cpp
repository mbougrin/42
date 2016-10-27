
#include "../includes/Player.hpp"

#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////
//                         public                             //
////////////////////////////////////////////////////////////////

Player::Player() : GameEntity(), _score(0), _life(5), _invincible(0), _difficulty(10)
{
	_entityType = "Player";
	_x = LINES / 2;
	_y = 5;
	_c = '>';
	wbkgd(_win, COLOR_PAIR(5));
	return ;
}

Player::Player(Player const& instance)
{
	*this = instance;
	return ;
}

Player::~Player()
{
	//delwin(_win); // dans GameEntity
	return ;
}

Player& Player::operator=(Player const& rhs)
{
	_entityType =	rhs._entityType;
	_win =			rhs._win;
	_x =			rhs._x;
	_y =			rhs._y;
	_c =			rhs._c;
	_sizeX =		rhs._sizeX;
	_sizeY =		rhs._sizeY;
	_speed =		rhs._speed;
	_life =			rhs._life;
	_score =		rhs._score;

	return (*this);
}

void	Player::update()
{
	return ;
}

void	Player::draw()
{
	mvwprintw(_win, 0, 0, "%c", ' ');
	wrefresh(_win);
	mvwin(_win, _x, _y);
	if (_invincible > 0)
	{
		--_invincible;
		wbkgd(_win, COLOR_PAIR(7));
		mvwprintw(_win, 0, 0, "%c", '#');
	}
	else
	{
		wbkgd(_win, COLOR_PAIR(5));
		mvwprintw(_win, 0, 0, "%c", _c);
	}
	wrefresh(_win);

	return ;
}

bool	Player::isColliding(GameEntity const & other) const
{
	return (GameEntity::isColliding(other) && _invincible <= 0);
}

void	Player::collide(GameEntity const & other)
{
	_life--;
	if (_life <= 0)
		die();
	_invincible = 50;
	
	(void)other;
	return ;
}

void	Player::controls(int key)
{
	if (KEY_UP == key)
		move(_x - 1, _y);
	else if (KEY_DOWN == key)
		move(_x + 1, _y);
	else if (KEY_LEFT == key)
		move(_x, _y - 1);
	else if (KEY_RIGHT == key)
		move(_x, _y + 1);
	else if (key == 32)
		shoot();

	return ;
}

void	Player::shoot() const
{
	Bullet	*newBullet = new Bullet(_x, _y, '-', 1, 1, 5, 1, 1);

	Bullet::addNewBullet(newBullet);
	return ;
}

void	Player::die()
{
	return ;
}

void	Player::increaseScore(int n)
{
	_score += n;
	return;
}

void	Player::increaseDifficulty(int n)
{
	if ((_difficulty += n) > DIFFICULTY_MAX)
		_difficulty = DIFFICULTY_MAX;

	return ;
}

int		Player::getScore() const { return (_score); }
int		Player::getLife() const { return (_life); }
int		Player::getDiff() const { return (_difficulty); }

void	Player::debugAnnounce(std::ostream& os) const
{
	GameEntity::debugAnnounce(os);
	os << "# " << "life:  " << _life << std::endl;
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
