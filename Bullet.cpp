// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 09:17:16 by vchaus            #+#    #+#             //
//   Updated: 2018/06/24 09:17:16 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bullet.hpp"

Bullet::Bullet() {}

Bullet::Bullet(int y, int x)
{
	this->_y = y;
	this->_x = x;
}

Bullet::Bullet(const Bullet & src)
{
	*this = src;
}

Bullet &	Bullet::operator=(const Bullet & src)
{
	this->_y = src._y;
	this->_x = src._x;
	return *this;
}

Bullet::~Bullet() {}

bool	Bullet::move(int y, int x, int y_max, int x_max, WINDOW * win)
{
	mvwprintw(win, this->_y, this->_x, " ");
	if (this->_y - y < 1)
		return false;
	else if (this->_y - y > y_max - 2)
		return false;
	else
		this->_y -= y;

	if (this->_x + x < 1)
		return false;
	else if (this->_x + x > x_max - 2)
		return false;
	else
		this->_x += x;
	mvwprintw(win, this->_y, this->_x, ".");
	return true;
}


