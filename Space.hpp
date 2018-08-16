// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Space.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 23:40:25 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 23:40:25 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef	SPACE_H
# define SPACE_H

# include "Ship.hpp"
# include "Enemy.hpp"
# include "Bullet.hpp"

# include <iostream>
# include <curses.h>

# define DEAD_ENEMY_POINT 5
# define SHIP_COLLISION_DAMAGE 20

class Space
{
	public:
		Space();
		Space(const Space &);
		Space & operator=(const Space &);
		~Space();

		Ship &	getShip();
		void	createEnemy();
		void	createBullet();
		void	moveEnemy(int, int, WINDOW *);
		void	moveBullet(int, int, WINDOW *);
		int		bulletCollision(WINDOW *);
		int		shipCollision(WINDOW *);
	protected:
	private:
		Ship 		_ship;
		Enemy *		_enemies[MAX_ENEMIES_NUMBER];
		Bullet *	_bullets[MAX_BULLET_NUMBER];
};

#endif
