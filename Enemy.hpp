// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 22:01:40 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 22:01:41 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_H
# define ENEMY_H

# include <iostream>
# include <curses.h>
# include "ASpaceObject.hpp"

# define MAX_ENEMIES_NUMBER 100

class Enemy : public ASpaceObject
{
	public:
		Enemy();
		Enemy(const Enemy &);
		Enemy &	operator=(const Enemy &);
		~Enemy();

		bool	move(int y, int x, int y_max, int x_max, WINDOW * win);
	protected:
	private:
};

#endif
