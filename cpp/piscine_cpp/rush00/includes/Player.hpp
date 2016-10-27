#ifndef _Player_HPP
# define _Player_HPP

# include "../includes/GameEntity.hpp"
# include "../includes/Bullet.hpp"
# include <curses.h>

# include <iostream>
# include <string>

# define DIFFICULTY_MAX 600

class Player : public GameEntity
{
public:
	Player();
	Player(Player const &);
	~Player();

	Player& operator=(Player const &);

	void	update();
	void	draw();
	bool	isColliding(GameEntity const & other) const;
	void	collide(GameEntity const &);

	void	controls(int key);
	void	shoot() const;
	void	die();
	void	increaseScore(int n);
	void	increaseDifficulty(int n);

	int		getScore() const;
	int		getLife() const;
	int		getDiff() const;

	void	debugAnnounce(std::ostream &) const;

protected:
	int		_score;
	int		_life;
	int		_invincible;
	int		_difficulty;
};

#endif //_Player_HPP
