/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_player.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 03:00:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/12 17:28:23 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_player.hpp>

Class_player::Class_player(void) : 
	_posX(LINES / 2), _posY(5),
	_score(0), _life(5), _c('>'), _invincible(0), _difficulty(10)
{
	this->_win = newwin(1, 1, this->getposX(), this->getposY());
	wbkgd(this->_win, COLOR_PAIR(5));
	mvwprintw(this->_win, 0, 0, "%c", this->getchar());
	wrefresh(this->_win);
	return ;
}

void		Class_player::setposX(int nb)
{
	if (nb > 0 && nb < LINES)
	{
		mvwin(this->_win, this->getposX(), this->getposY());
		mvwprintw(this->_win, 0, 0, "%c", ' ');
		wrefresh(this->_win);
		this->_posX = nb;
	}
}

void		Class_player::setposY(int nb)
{
	if (nb >= 0 && nb < COLS)
	{
		mvwin(this->_win, this->getposX(), this->getposY());
		mvwprintw(this->_win, 0, 0, "%c", ' ');
		wrefresh(this->_win);
		this->_posY = nb;
	}
}

void		Class_player::setscore(int nb) { this->_score = nb; }
void		Class_player::setlife(int nb) { this->_life = nb; }
int			Class_player::getposX(void) { return this->_posX; }
int			Class_player::getposY(void) { return this->_posY; }
int			Class_player::getscore(void) { return this->_score; }
int			Class_player::getlife(void) { return this->_life; }
char		Class_player::getchar(void) { return this->_c; }
int			Class_player::getdifficulty(void) { return this->_difficulty; }

void		Class_player::increaseDifficulty(int n)
{
	if ((_difficulty += n) > DIFFICULTY_MAX)
		_difficulty = DIFFICULTY_MAX;

	return ;
}

void		Class_player::refresh(void)
{
	mvwin(this->_win, this->getposX(), this->getposY());
	if (_invincible > 0)
	{
		--_invincible;
		wbkgd(this->_win, COLOR_PAIR(7));
		mvwprintw(this->_win, 0, 0, "%c", '#');
	}
	else
	{
		wbkgd(this->_win, COLOR_PAIR(5));
		mvwprintw(this->_win, 0, 0, "%c", this->getchar());

	}
	wrefresh(this->_win);
}

void		Class_player::collide(GameEntity const &)
{
	_life--;
	if (_life <= 0)
		die();
	_invincible = 50;
	
	return ;
}

bool		Class_player::isColliding(GameEntity const & other) const
{
	return (_posX == other.getX() &&  _posY == other.getY() && _invincible <= 0);
}

void		Class_player::die()
{
	return ;
}


void		Class_player::shoot(void) const
{
	Bullet	*newBullet = new Bullet(_posX, _posY, '-', 1, 1, 5, 1, 1);

	Bullet::addNewBullet(newBullet);
	
	return ;
}

Class_player::Class_player(Class_player const &src) { if (this != &src) { *this = src ; } return ; }

Class_player::~Class_player(void) { delwin(this->_win); return ; }

Class_player&		Class_player::operator=(Class_player const &src) { if (this != &src) { } return *this; }
