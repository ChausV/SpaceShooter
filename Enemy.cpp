// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 07:40:47 by vchaus            #+#    #+#             //
//   Updated: 2018/06/24 07:40:48 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy()
{
	this->_y = 1;
	this->_x = (rand() % 78) + 1;
}

Enemy::Enemy(const Enemy & src)
{
	*this = src;
}

Enemy &	Enemy::operator=(const Enemy & src)
{
	this->_y = src._y;
	this->_x = src._x;
	return *this;
}

Enemy::~Enemy() {}

bool	Enemy::move(int y, int x, int y_max, int x_max, WINDOW * win)
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
	mvwprintw(win, this->_y, this->_x, "O");
	return true;
}


