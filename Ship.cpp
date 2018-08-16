// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ship.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 23:44:29 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 23:44:30 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ship.hpp"

Ship::Ship() : _sight('X') {}

Ship::Ship(const Ship & src)
{
	*this = src;
}

Ship &	Ship::operator=(const Ship & src)
{
	this->_y = src._y;
	this->_x = src._x;
	this->_sight = src._sight;
	return *this;
}

Ship::~Ship() {}

char	Ship::getSight() const
{
	return this->_sight;
}

bool	Ship::move(int y, int x, int y_max, int x_max, WINDOW * win)
{
	mvwprintw(win, this->_y, this->_x, " ");
	if (this->_y - y < 1)
		(this->_y = 1);
	else if (this->_y - y > y_max - 2)
		(this->_y = y_max - 2);
	else
		this->_y -= y;

	if (this->_x + x < 1)
		(this->_x = 1);
	else if (this->_x + x > x_max - 2)
		(this->_x = x_max - 2);
	else
		this->_x += x;
	mvwprintw(win, this->_y, this->_x, "%c", this->getSight());
	return true;
}

