/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_player.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 03:00:34 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/12 12:32:16 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PLAYER_HPP
# define CLASS_PLAYER_HPP

# include <curses.h>
# include "../includes/Bullet.hpp"
# include "../includes/GameEntity.hpp"

# define DIFFICULTY_MAX 600

class		Class_player
{
public:
	Class_player(void);
	Class_player(Class_player const &src);
	virtual ~Class_player(void);

	void		setposX(int nb);
	void		setposY(int nb);
	void		setscore(int nb);
	void		setlife(int nb);
	int			getposX(void);
	int			getposY(void);
	int			getscore(void);
	int			getlife(void);
	char		getchar(void);
	int			getdifficulty(void);
	void		increaseDifficulty(int n);
	void		refresh(void);

	void		collide(GameEntity const &);
	bool		isColliding(GameEntity const &) const;

	void		shoot() const;
	void		die();

	Class_player&			operator=(Class_player const &src);

private:
	WINDOW		*_win;
	int			_posX;
	int			_posY;
	int			_score;
	int			_life;
	char		_c;
	int			_invincible;
	int			_difficulty;
};

#endif
