// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 22:01:52 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 22:01:53 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BULLET_H
# define BULLET_H

# include <iostream>
# include <curses.h>
# include "ASpaceObject.hpp"

# define MAX_BULLET_NUMBER 100

class Bullet : public ASpaceObject
{
	public:
		Bullet(int y, int x);
		Bullet(const Bullet &);
		Bullet &	operator=(const Bullet &);
		~Bullet();

		bool	move(int y, int x, int y_max, int x_max, WINDOW * win);
	protected:
	private:
		Bullet();
};

#endif
