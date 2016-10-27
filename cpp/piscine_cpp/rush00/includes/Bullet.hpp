#ifndef _Bullet_HPP
# define _Bullet_HPP

# include "../includes/GameEntity.hpp"
# include <ncurses.h>

# include <iostream>
# include <string>

# define NB_BULLETS_MAX 500

class Bullet : public GameEntity
{
public:
	Bullet();
	Bullet(int x, int y, char c, int sizeX, int sizeY, int speed, int power, int dir);
	Bullet(GameEntity const &, int power, int dir);
	Bullet(Bullet const &);
	~Bullet();

	Bullet& operator=(Bullet const &);

	void	update();
	void	draw();
	void	collide(GameEntity const &);
	void	die();

	int		getPower() const;
	int		getDir() const;

	void	debugAnnounce(std::ostream &) const;

	static Bullet ** getBulletsTab();

	static void		initBulletsTab();
	static void		freeBulletsTab();
	static void		drawBullets();
	static void		updateBullets();
	static int		addNewBullet(Bullet *newBullet);
	static void		deleteBullet(int index);

private:
	int		_power;
	int 	_dir;
	int		_index;

	static Bullet *	_bullets[NB_BULLETS_MAX];
};

#endif //_Bullet_HPP
